#pragma once
#include "../core/asset.hpp"
#include <Python.h>
class python_script
	: public asset_base {
private:
	std::string m_source;

public:
	python_script( const asset_url& url )
		: asset_base( url ) { }

	virtual bool load( const std::string& data, std::string& error ) override {
		m_source = data;
		PyRun_st
	}

	virtual bool unload( std::string& error ) override {

	}
};