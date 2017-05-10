#include "catch.hpp"
#include "../core/asset.hpp"
TEST_CASE( "asset_url", "asset url type and path modifications") {
	SECTION( "adequate construction with 2 param constructor" ) {
		asset_url ex( "mesh", "folder1.folder2.toroid" );
		REQUIRE( ex.has_type() );
		REQUIRE( ex.get_name() == "toroid" );
		REQUIRE( ex.get_path() == "folder1.folder2.toroid" );
		REQUIRE( ex.get_type() == "mesh" );
	}

	SECTION( "adequate construction with 1 param constructor" ) {
		asset_url ex( "folder1.folder2.toroid" );
		REQUIRE( !ex.has_type() );
		REQUIRE( ex.get_name() == "toroid" );
		REQUIRE( ex.get_path() == "folder1.folder2.toroid" );
		REQUIRE( ex.get_type() == "" );
	}

	SECTION( "adequate type modification/removal, path and name modification" ) {
		asset_url ex( "mesh", "folder1.folder2.toroid" );

		ex.remove_type();
		REQUIRE( ex.get_type() == "" );
		REQUIRE( ex.get_path() == "folder1.folder2.toroid" );

		ex.set_type( "texture" );
		REQUIRE( ex.get_type() == "texture" );
		REQUIRE( ex.get_path() == "folder1.folder2.toroid" );

		ex.set_path( "local.fasz" );
		REQUIRE( ex.get_path() == "local.fasz" );
		REQUIRE( ex.get_name() == "fasz" );
		REQUIRE( ex.get_type() == "texture" );
	}

	SECTION( "proper completing" ) {
		asset_url ex( "mesh", "this.*.incomplete" );
		asset_url ex2( "is" );

		REQUIRE( ex.make_complete( ex2 ).format() == "mesh@this.is.incomplete" );
	}

	SECTION( "proper recognition of complete and incomplete paths" ) {
		asset_url ex( "mesh", "this.*.incomplete" );
		asset_url ex2( "mesh", "this.is.complete" );

		REQUIRE( !ex.is_complete() );
		REQUIRE( ex2.is_complete() );
		REQUIRE( ex.make_complete( ex2 ).is_complete() );
	}
}

#include <wallaroo\catalog.h>
using wallaroo::Catalog;
TEST_CASE( "asset_manager", "asset manager base functionality" ) {
	Catalog c;
	auto manager = c.Create( "test", "asset_manager_test" );
	auto log = c.Create( "logger", "logger_mock" );
	auto streamer = c.Create( "streamer", "asset_streamer_test" );
	auto listener = c.Create( "listener", "asset_listener_test" );
	manager.Wire( "logger", log );
	manager.Wire( "streamer", streamer );
	std::vector< std::string > assets = { "test@*.collision", "test@m.collision", "test@fullpath.nocollision", "test@middle.*.incomplete.noc", "test@async" };
	std::vector< std::string > paths = { "m", "shouldbeinserted.to.the.incompletes", "test.test.test" };
//	manager.SetAttribute( "assets", assets );
//	manager.SetAttribute( "search_urls", paths );
	c.Init();

	std::shared_ptr< i_asset_manager > m = manager;

	SECTION( "creation and initialization" ) {
		
		typedef asset_url au;
		REQUIRE( m->get_asset( au( "test@m.collision" ) ) );
		REQUIRE( m->get_asset( au( "test@shouldbeinserted.to.the.incompletes.collision" ) ) );
		REQUIRE( m->get_asset( au( "test@test.test.test.collision" ) ) );

		REQUIRE( m->get_asset( au( "test@m.collision0" ) ) );
		REQUIRE( m->get_asset( au( "test@fullpath.nocollision" ) ) );

		REQUIRE( m->get_asset( au( "test@middle.m.incomplete.noc" ) ) );
		REQUIRE( m->get_asset( au( "test@middle.shouldbeinserted.to.the.incompletes.incomplete.noc" ) ) );
		REQUIRE( m->get_asset( au( "test@middle.test.test.test.incomplete.noc" ) ) );
	}

	SECTION( "asset loading" ) {
		auto ass = m->load_asset( "collision" );
		REQUIRE( ass );
		REQUIRE( ass->get_state() == asset_state::loaded );
	}

	SECTION( "async asset loading" ) {
		auto ass = m->load_asset( "async", listener.operator std::shared_ptr< i_asset_listener >().get() );
		REQUIRE( ass->get_state() == asset_state::loading );
		while( ass->get_state() == asset_state::loading ) {
			std::this_thread::sleep_for( std::chrono::milliseconds( 750 ) );
			std::cout << "loading asset..." << std::endl;
		}
		REQUIRE( ass->get_state() == asset_state::loaded );
	}
}