#include "python_asset.hpp"

class python_script_manager
	: public asset_manager_base {
private:
	virtual const char* get_type( void ) const override {
		return "script";
	}

	virtual asset_ptr create_asset( const asset_url& url ) override {
		return std::make_shared< python_script >( url );
	}
};