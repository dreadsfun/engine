#include "../core/scripting.hpp"
#include "../core/system_base.hpp"
#include <Python.h>

class python_context;

class python_object
	: public i_script_object {
protected:
	PyObject* m_internal { nullptr };
	std::string m_name;
	python_context* m_context;

public:
	python_object( python_context* ctx, PyObject* ob, const std::string& name )
		: m_internal( ob ),
		m_context( ctx ),
		m_name( name ) { }

	PyObject* _get_internal( void ) {
		return m_internal;
	}

private:
	virtual std::string get_name( void ) const {
		return m_name;
	}

	virtual script_object_type get_type( void ) const {
		return script_object_type::script_void;
	}

	virtual i_script_context* get_context( void ) {
		return m_context;
	}

	virtual bool is_active( void ) const {

	}
};

#include <unordered_map>

class python_context
	: public i_script_context {
private:
	PyObject* m_dict;

	std::unordered_map< std::string, i_script_object* > m_objects;

public:
	python_context( void ) {
		PyObject* main = PyImport_AddModule( "__main__" );
		PyObject* dict = PyModule_GetDict( main );
		m_dict = PyDict_Copy( dict );
		Py_DECREF( main );
		Py_DECREF( dict );
	}

	virtual i_script_object* get_object( const std::string& name ) {
		i_script_object* r = nullptr;
		auto fit = m_objects.find( name );
		if( fit == m_objects.end() ) {
			PyObject* ob = PyDict_GetItemString( m_dict, name.c_str() );
			if( ob != nullptr ) {
				r = new python_object( this, ob, name );
				m_objects.insert( std::make_pair( name, r ) );
			}
		} else {
			r = fit->second;
		}
		return r;
	}

	virtual i_script_function* get_function( const std::string& name ) {
		return nullptr;
	}

	virtual i_script_class* get_class( const std::string& name ) {
		return nullptr;
	}

	virtual void add_object( i_script_object* src, const std::string& name ) {
		PyObject* ob = PyDict_GetItemString( m_dict, name.c_str() );
		if( ob == nullptr ) {
			python_object* pob = static_cast< python_object* >( src );
			PyDict_SetItemString( m_dict, name.c_str(), pob->_get_internal() );
		}
	}

	virtual i_script_object* create_function( const std::string& name ) {
		return nullptr;
	}

	virtual i_script_object* create_class( const std::string& name ) {
		return nullptr;
	}
};

class python_function
	: public python_object, public i_script_function {
private:
	virtual i_script_object* call( std::vector< i_script_object* > args ) {

	}
};

class python_class
	: public python_object, public i_script_class {
private:
	virtual i_script_object* instantiate( std::vector< i_script_object* > args ) {

	}
};

class python_scripting
	: public system_base, i_scripting {
private:
	virtual void initialize( void ) override {
		Py_Initialize();
	}

	virtual void update_scene( i_scene_node* root ) override {

	}

	virtual node_subscription create_subscription( void ) override {
		node_subscription ns;
		ns.allow_name( "py_script" );
		return ns;
	}

	virtual std::shared_ptr< i_script_context > create_context( void ) {
		return std::make_shared< python_context >();
	}
};

#include "../di_rtlib/register_class.hpp"
register_class( python_scripting );