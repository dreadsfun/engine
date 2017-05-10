#include "../cAPI/capi.h"
#include "catch.hpp"

TEST_CASE( "capi_logger", "" ) {
	SECTION( "log info test" ) {
		log_info( "capi log info test" );
	}
}