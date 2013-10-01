#ifndef DEMANGLE_HPP
#define DEMANGLE_HPP

#include <string>
#include <iostream>
#include <stdexcept>

#ifdef __GNUC__
#include "cxxabi.h"
#endif

namespace sj
{
#ifdef __GNUC__
inline std::string demangle(const char* name)
{
	char buf[1024];
	size_t size = 1024;
	int status;
	char* res = abi::__cxa_demangle
	(
		name,
		buf,
		&size,
		&status
	);

	if (status == -1)
		throw std::runtime_error("sj::demangle: memory allocation failed");
	if (status == -2)
		throw std::invalid_argument("sj::demangle: mangled name not valid");
	if (status == -3)
		throw std::invalid_argument("sj::demangle: invalid argument");

	return res;	
}
#else
std::string demangle(const char* name)
{
	throw std::exception("sj::demangle is supported only with"
						 " GCC/Clang compilers");
}
#endif // __GNUC__

template <class T>
std::string demangle(const T& var)
{
	return demangle(typeid(var).name());
}

} // namespace sj

#endif //  DEMANGLE_HPP
