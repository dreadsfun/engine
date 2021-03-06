#include <functional>
#include "../core/system_base.hpp"
#include "../core/graphics.hpp"
#include "../core/logger.hpp"
#include "../core/windowing.hpp"
#include "../core/time.hpp"
#include "../di_rtlib/define_attribute.hpp"
#include "../di_rtlib/define_dependency.hpp"
#include "material_library.hpp"
#include "ogl_asset.hpp"
#include "ogl_scene_node.hpp"
#include "ogl_program.hpp"
class program_pool {
private:
	typedef std::vector< shader_program > program_vector;
	typedef std::unordered_map< std::string, shader_program* > fragment_program_map;
	typedef fragment_program_map unique_program_map;
	typedef std::unordered_map< std::string, fragment_program_map > vertex_fragment_program_map;

	program_vector m_programs;
	unique_program_map m_unique_map;
	vertex_fragment_program_map m_program_map;

	type_manager_ptr m_type_mgr;
	logger_ptr m_logger;

public:
	program_pool( type_manager_ptr tm, i_logger* l )
		: m_type_mgr( tm ),
		m_logger( l ) { }

	program_pool( void ) = default;

	program_pool& set_logger( logger_ptr l ) {
		m_logger = l;
		return *this;
	}

	program_pool& set_type_manager( type_manager_ptr tm ) {
		m_type_mgr = tm;
		return *this;
	}

	shader_program* insert_from_material( const std::string& mat, asset::shader_ptr vertex ) {
		return this->insert_from_material( material_library::get_material( mat ), vertex );
	}

	shader_program* insert_from_material( const material* mt, asset::shader_ptr vertex ) {
		shader_program* r = nullptr;
		if( mt != nullptr ) {
			// check if the material already exists
			auto fit = m_unique_map.find( mt->name() );
			if( fit == m_unique_map.end() ) {
				// if not..
				asset_manager_ptr shader_mgr = m_type_mgr->get( "shader" );
				if( mt != nullptr ) {
					// if the material definition exists..
					// load the required shaders and insert a program
					// that matches the material
					shader_mgr->load_asset( vertex->get_path() );
					r = this->insert( vertex, std::static_pointer_cast< asset::shader >(
						shader_mgr->load_asset( asset_url( mt->shader().file() ) )
						) );
					if( r != nullptr ) {
						// if insertion was successful, 
						// map the new program with the material
						m_unique_map.insert( std::make_pair( mt->name(), r ) );
					}
				}
			} else {
				// if it does..
				r = fit->second;
				//swarn << "material \"" << mt->name() << "\" was already extracted to create a program";
			}
		}
		return r;
	}

	shader_program* insert( asset::shader_ptr vertex, asset::shader_ptr fragment ) {
		shader_program*& p = m_program_map[ vertex->get_path().get_name() ][ fragment->get_path().get_name() ];
		if( p == nullptr ) {
			p = _create_insert_program( vertex, fragment );
		}
		return p;
	}

	shader_program* retrieve( const std::string& mat ) {
		shader_program* r = nullptr;
		auto fit = m_unique_map.find( mat );
		if( fit == m_unique_map.end() ) {
			serror << "program was not found, matching the \"" << mat << "\" named material";
		} else {
			r = fit->second;
		}
		return r;
	}

	shader_program* retrieve( const std::string& vn, const std::string& fn ) {
		shader_program* r = nullptr;
		auto fit = m_program_map.find( vn );
		if( fit == m_program_map.end() ) {
			serror << "no programs were found which run the vertex program, named \"" << vn << "\"";
		} else {
			auto ffit = fit->second.find( fn );
			if( ffit == fit->second.end() ) {
				serror << "no program was found which run the vertex program, \
					named \"" << vn << "\" and the fragment program, named \"" << fn << "\"";
			} else {
				r = ffit->second;
			}
		}
		return r;
	}

private:
	shader_program* _create_insert_program( asset::shader_ptr vtx, asset::shader_ptr fragment ) {
		shader_program p;
		shader_program* r = nullptr;
		if( p.set_vertex_program( vtx->get_name() )
			.set_fragment_program( fragment->get_name() )
			.link()
			.has_error() ) {
			serror << "failed to link program, vertex shader was \"" << vtx->get_path() << "\", fragment shader was \""
				<< fragment->get_path() << "\"\n\t\treason: " << p.get_log();
		} else {
			m_programs.emplace_back( std::move( p ) );
			r = &m_programs.back();
			sinfo << "program inserted, vertex shader was \"" << vtx->get_path() << "\", fragment shader was \""
				<< fragment->get_path() << "\"";
		}
		return r;
	}
};

class ogl_graphics
	: public i_graphics, public system_base {
#pragma region types
private:
	typedef std::unique_ptr< i_context_guard > context_guard_ptr;
	class mesh_renderer_dispatcher {
	private:
		typedef std::unordered_map< std::string, GLuint > texture_name_map;

		asset::shader_ptr m_vertex_shader;
		program_pool* m_pool;
		texture_name_map m_texture_map;

	public:
		mesh_renderer_dispatcher( program_pool* p )
			: m_pool( p ) { }

		bool load( type_manager_ptr tm ) {
			asset_manager_ptr sm = tm->get( "shader" );
			m_vertex_shader = std::static_pointer_cast< asset::shader >( sm->load_asset( asset_url( "shader@mesh_renderer_node_vertex" ) ) );
			return m_vertex_shader.operator bool();
		}

		void dispatch( mesh_renderer_node* n, node_subscription::node_range_iterator_pair cams ) {
			if( !n->try_lock() ) return;
			if( !n->get_mesh() ) {
				n->unlock();
				return;
			}

			const auto& mats = n->get_materials();
			size_t subm = 0;
			shader_program* p = nullptr;
			// for every material, assigned to the renderer
			for( const std::string& m : mats ) {
				// means there are more materials than submeshes
				// should not really happen
				if( subm == n->get_mesh()->get_submesh_count() ) break;
				// retrieve the referenced material and insert it into the program pool
				// does nothing if it's already inserted, such optimized wow
				const material* mmod = material_library::get_material( m );
				p = m_pool->insert_from_material( mmod, m_vertex_shader );
				if( p != nullptr ) {
					// if program insertion was successful, upload
					// the material's params to the program
					_setup_program_material( p, mmod );

					// get all the textures associated with this renderer
					// and bind them to the texture units [0; n) where
					// n is the number of textures
					const auto& texs = n->get_textures();
					if( texs.size() > subm ) {
						unsigned int unit = 0;
						for( const auto& pp : texs[ subm ] ) {
							pp.second->bind( unit++ );
						}
					}

					// draw this particular submesh to every provided camera
					// this allows the submesh's state to be setup only once per game-loop
					for( auto b = cams.first; b != cams.second; ++b ) {
						camera_node* cn = static_cast< camera_node* >( b->second );
						const glm::mat4& wm = n->get_transform().get_world_matrix();
						_render_camera( p, n, subm, cn->get_mvp( wm ), wm );
					}
				}
				subm++;
			}
			if( p != nullptr ) {
				// if there were less materials than submeshes, this will draw
				// the remaining ones, with the last program setup
				for( auto b = cams.first; b != cams.second; ++b ) {
					camera_node* cn = static_cast< camera_node* >( b->second );
					const glm::mat4& wm = n->get_transform().get_world_matrix();
					for( ; subm < n->get_mesh()->get_submesh_count(); ++subm ) {
						_render_camera( p, n, subm, cn->get_mvp( wm ), wm );
					}
				}
			}
			n->unlock();
		}

	private:
		void _render_camera( shader_program* p, mesh_renderer_node* n, size_t subm, const glm::mat4& mvp, const glm::mat4& wm ) {
			p->set( "g_full_vertex_transform", mvp );
			p->set( "g_model_to_world_transform", wm );
			n->get_mesh()->draw_submesh( subm );
		}

		void _setup_program_material( shader_program* pr, const material* m ) {
			pr->use();

			for( const vector& v : m->vector() ) {
				if( v.w_present() ) {
					pr->set( v.uniform(), glm::vec4( v.x(), v.y(), v.z(), v.w() ) );
				} else {
					if( v.z_present() ) {
						pr->set( v.uniform(), glm::vec3( v.x(), v.y(), v.z() ) );
					} else {
						if( v.y_present() ) {
							pr->set( v.uniform(), glm::vec2( v.x(), v.y() ) );
						} else {
							pr->set( v.uniform(), v.x() );
						}
					}
				}
			}

			int tex_slot = 0;
			for( const texture& t : m->texture() ) {
				pr->set( t.sampler(), tex_slot++ );
			}
		}

	};
#pragma endregion

#pragma region data members
private:
	component_dependency( m_type_manager, i_asset_type_manager );
	component_attribute( m_lighting_enabled, bool, true );
	context_guard_ptr m_guard;
	program_pool m_program_pool;
	mesh_renderer_dispatcher m_mesh_renderer;
#pragma endregion

#pragma region member functions
public:
	ogl_graphics( void )
		: m_mesh_renderer( &m_program_pool ) { }

private:
	virtual bool initialize( void ) override {
		info( "entering ogl graphics implementation..." );
		bool r = true;
		m_program_pool.set_logger( m_logger );
		m_program_pool.set_type_manager( m_type_manager );
		if( !m_mesh_renderer.load( m_type_manager ) ) {
			error( "failed to initialize mesh renderer subsystem" );
			r = false;
		}
		return r;
	}

	virtual node_subscription create_subscription( void ) override {
		node_subscription ns;
		if( m_lighting_enabled ) {
			ns.allow_name( "directional_light" );
			ns.allow_name( "point_light" );
		}

		ns.allow_name( "mesh_renderer" );
		ns.allow_name( "camera" );
		return ns;
	}

	virtual void _process_scene( i_scene_node* root, node_subscription& ns ) override {
		node_subscription::node_range_iterator_pair crs = ns.get_subscribers( "camera" );
		if( crs.first != crs.second ) {
			node_subscription::node_range_iterator_pair mrs = ns.get_subscribers( "mesh_renderer" );
			for( auto b = mrs.first; b != mrs.second; ++b ) {
				m_mesh_renderer.dispatch( static_cast< mesh_renderer_node* >( b->second ), crs );
			}
		}
	}

	virtual void update_scene( i_scene_node* root ) override {
		this->process_scene( root );
	}
#pragma endregion
};

#include "../di_rtlib/register_class.hpp"
register_class( ogl_graphics );