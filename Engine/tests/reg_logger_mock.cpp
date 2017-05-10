#include <wallaroo\part.h>
using wallaroo::Part;
#include "../core/logger.hpp"
#include <iostream>
class logger_mock
	: public i_logger, public Part {
public:
	virtual void log( priority p, const std::string& m, const std::string& cl ) const override {
		std::cout << "mock log: " << m << std::endl;
	}

	virtual log_stream init_stream( priority p, const std::string& cl ) const override {
		return log_stream( p, cl, this );
	}

	virtual std::string priority_to_string( priority p ) const override {
		return "";
	}
};
#include <wallaroo\registered.h>
WALLAROO_REGISTER( logger_mock );