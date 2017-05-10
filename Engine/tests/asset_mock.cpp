#include "../core/asset.hpp"
class asset_test
	: public asset_base {
public:
	asset_test( const asset_url& url )
		: asset_base( url ) {}

	// called by the asset manager just before calling load
	virtual void pre_load( void ) override {

	}

	// called by the asset manager when loading the asset
	// this is the main logic of loading and initializing
	// a specific asset type
	// returns true if successful, false otherwise
	virtual bool load( const std::string& data, std::string& err ) override {
		std::cout << "asset loaded: " << data << std::endl;
		return true;
	}

	// called by the asset manager after load, only if
	// load was successful ( returned true )
	virtual void post_load( void ) override {

	}
};

#include <wallaroo\part.h>
using wallaroo::Part;
#include <wallaroo\collaborator.h>
#include <wallaroo\attribute.h>
class asset_manager_test
	: public asset_manager_base {

	// Returns the type string that identifies the 
	// asset type, managed by the manager implementation
	virtual const char* get_type( void ) const override {
		return "test";
	}

	// Creates a new asset with the type of the asset
	// that the manager implementation manages
	// This is called when inserting new assets during initialization
	virtual asset_ptr create_asset( const asset_url& url ) override {
		return std::make_shared< asset_test >( url );
	}
};

class asset_listener_test
	: public i_asset_listener, public Part {
private:
	virtual void load_ready( asset_ptr a ) const override {
		std::cout << "asset listener : asset load ready of " << a->get_path();
	}
};

class asset_streamer_test
	: public i_asset_streamer, public Part {
	// opens a stream to the asset found on the specified url if it exists
	// returns the opened stream if successful
	virtual std::stringstream open_data_stream( const asset_url& url ) override {
		return std::stringstream();
	}

	// opens and fully loads the data of the asset, found on the url
	virtual std::string load_data( const asset_url& url ) override {
		if( url.get_name() == "async" ) {
			std::this_thread::sleep_for( std::chrono::seconds( 1 ) );
		}
		return "example asset data";
	}

	// opens and begins asynchronous loading of the data of the asset, found on the url
	virtual std::future< std::string > load_data_async( const asset_url& url ) override {
		return std::async( &asset_streamer_test::load_data, this, url );;
	}

	// returns true if the asset exists and is openable
	virtual bool check_asset( const asset_url& url ) override {
		return true;
	}
};

#include <wallaroo\registered.h>
WALLAROO_REGISTER( asset_manager_test );
WALLAROO_REGISTER( asset_streamer_test );
WALLAROO_REGISTER( asset_listener_test );
