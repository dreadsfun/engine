#include "catch.hpp"
#include "../core/multi_thread.hpp"
#include <iostream>
TEST_CASE( "multi_thread", "multi thread job pushing, and lifetime" ) {
	multi_thread mt;

	SECTION( "push simple job" ) {
		mt.push_job( [] {
			std::cout << "hello from pushed job" << std::endl;
			REQUIRE( true );
		} );
	}

	SECTION( "push long simulated job" ) {
		mt.push_job( [] {
			std::cout << "starting long job" << std::endl;
			std::this_thread::sleep_for( std::chrono::seconds( 2 ) );
			std::cout << "long job finished" << std::endl;
		} );
	}

	SECTION( "push lot of jobs" ) {
		for( int i = 0; i < 25; ++i ) {
			mt.push_job( []( int v ) {
				std::cout << "my job id is " << v << std::endl;
			}, i );
		}
	}
}