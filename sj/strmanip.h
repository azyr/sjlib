#pragma once

#include <string>

inline void pad_left(std::string &str, const size_t num, const char paddingChar = ' ')
{
	if (num > str.size())
	{
		str.insert(0, num - str.size(), paddingChar);
	}
}