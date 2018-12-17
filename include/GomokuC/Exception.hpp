#pragma once

#include <stdexcept>

class NoCompatibleProtocol : public std::runtime_error
{
	using std::runtime_error::runtime_error;
};