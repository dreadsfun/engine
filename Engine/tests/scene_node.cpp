#include "catch.hpp"
#include "../core/scene_node.hpp"
#include <iostream>

class unspecified {};

template< typename T, typename U = typename unspecified >
class shared_class_if2
	: public T {
public:
	template< typename ... args >
	static std::shared_ptr< T > make_shared( const args& ... a ) {
		return std::make_shared< U >( a ... );
	}
};

template< typename T >
class shared_class_if2< T, unspecified > {
public:
	template< typename ... args >
	static std::shared_ptr< T > make_shared( const args& ... a ) {
		return std::make_shared< T >( a ... );
	}
};


class scene_node_test
	: public scene_node_base {
public:
	scene_node_test( void ) = default;
	scene_node_test( const std::string& n )
		: scene_node_base( n ) {}

	virtual void update( node_subscription& ns ) override {
		std::cout << this->get_name() << std::endl;
	}
};


class node_visitor_test
	: public i_node_visitor, public shared_class_if2< node_visitor_test > {
private:
	std::vector< std::string > m_trav_data;

public:
	const std::vector< std::string >& get( void ) const {
		return m_trav_data;
	}

	void clear( void ) {
		m_trav_data.clear();
	}

	virtual void visit( i_scene_node* n ) override {
		//n->update( .0f );
		m_trav_data.push_back( static_cast< scene_node_test* >( n )->get_name() );
	}

	virtual bool completed( void ) const override {
		return false;
	}
};

class node_visitor_halt_test
	: public i_node_visitor, public shared_class_if2< node_visitor_halt_test > {
private:
	std::vector< std::string > m_trav_data;
	i_scene_node* m_found { nullptr };
public:
	const std::vector< std::string >& get( void ) const {
		return m_trav_data;
	}

	void clear( void ) {
		m_trav_data.clear();
	}

	virtual void visit( i_scene_node* n ) override {
		std::string dat = static_cast< scene_node_test* >( n )->get_name();
		if( dat == "c1" ) {
			m_found = n;
		}
		//n->update( .0f );
		m_trav_data.push_back( dat );
	}

	virtual bool completed( void ) const override {
		return m_found != nullptr;
	}
};

#include <wallaroo\registered.h>
WALLAROO_REGISTER( scene_node_test );

#include <string>
#include <array>
#include "../core/scene.hpp"
TEST_CASE( "scene_graph", "scene graph creation, traversal" ) {
	auto v = node_visitor_test::make_shared();
	auto v2 = node_visitor_halt_test::make_shared();

	scene_node_test root( "root" );
	scene_node_test c1( "c1" );
	scene_node_test c2( "c2" );
	scene_node_test c11( "c11" );
	scene_node_test c12( "c12" );
	scene_node_test c3( "c3" );
	scene_node_test c31( "c31" );
	scene_node_test c311( "c311" );

	root.add_child( &c1 );
	root.add_child( &c2 );
	root.add_child( &c3 );
	c1.add_child( &c11 );
	c1.add_child( &c12 );
	c3.add_child( &c31 );
	c31.add_child( &c311 );

	std::array< std::string, 8 > or = { "root", "c1", "c11", "c12", "c2", "c3", "c31", "c311" };
	std::array< std::string, 8 > or2 = { "root", "c1", "c2", "c3", "c11", "c12", "c31", "c311" };

	auto check_order = []( const std::vector< std::string >& l, const std::array< std::string, 8 > or ) -> bool {
		for( int i = 0; i < 8; ++i ) {
			if( l [ i ] != or [ i ] ) return false;
		}
		return true;
	};

	auto check_order_halt = []( const std::vector< std::string >& l, const std::array< std::string, 8 > or ) -> bool {
		for( int i = 0; i < 2; ++i ) {
			if( l [ i ] != or [ i ] ) return false;
		}
		return true;
	};

	SECTION( "depth first" ) {
		v->clear();
		root.traverse_depth( v );
		REQUIRE( check_order( v->get(), or ) );
	}

	SECTION( "breadth first" ) {
		v->clear();
		root.traverse_breadth( v );
		REQUIRE( check_order( v->get(), or2 ) );
	}

	SECTION( "depth first halt" ) {
		v2->clear();
		root.traverse_depth( v2 );
		REQUIRE( check_order_halt( v2->get(), or ) );
	}

	SECTION( "breadth first halt" ) {
		v2->clear();
		root.traverse_breadth( v2 );
		REQUIRE( check_order_halt( v2->get(), or2 ) );
	}

	SECTION( "scene with scene tree descriptor" ) {
		scene mod_sc;
		mod_sc.name( "test_scene" );
		mod_sc.graph( "n1 n11 n111 . n112 n1121 . . . n12 . n13 . n14 n141 . n142" );

		node mod_n1, mod_n11, mod_n111, mod_n112, mod_n1121, mod_n12,
			mod_n13, mod_n14, mod_n141, mod_n142;
		mod_n1.name( "n1" );
		mod_n11.name( "n11" );
		mod_n111.name( "n111" );
		mod_n112.name( "n112" );
		mod_n1121.name( "n1121" );
		mod_n12.name( "n12" );
		mod_n13.name( "n13" );
		mod_n14.name( "n14" );
		mod_n141.name( "n141" );
		mod_n142.name( "n142" );

		mod_n1.class_() = mod_n11.class_() = mod_n111.class_() = mod_n112.class_() = mod_n1121.class_() = mod_n12.class_() =
			mod_n13.class_() = mod_n14.class_() = mod_n141.class_() = mod_n142.class_() = "scene_node_test";

		nodes mod_ns;
		mod_ns.node().push_back( &mod_n1 );
		mod_ns.node().push_back( &mod_n11 );
		mod_ns.node().push_back( &mod_n111 );
		mod_ns.node().push_back( &mod_n112 );
		mod_ns.node().push_back( &mod_n1121 );
		mod_ns.node().push_back( &mod_n12 );
		mod_ns.node().push_back( &mod_n13 );
		mod_ns.node().push_back( &mod_n14 );
		mod_ns.node().push_back( &mod_n141 );
		mod_ns.node().push_back( &mod_n142 );


		getchar();
	}
}