#pragma once
#include <string>
#include <exception>

#include "../utils/console.hpp"

namespace ch3
{
namespace stringify
{
	template <typename T>
	std::string to_hex_string(T&& val)
	{
		static const std::string CHARACTERS = "0123456789ABCDEF";
		if (val >= 0xFF)
			throw std::overflow_error("Must be less or equal to 0xFF.");

		std::string ret;
		ret += CHARACTERS[(size_t)(val / 16)];
		ret += CHARACTERS[(size_t)(val % 16)];

		return ret;
	};

	template <typename Iterator>
	std::string stringify(Iterator first, Iterator last)
	{
		std::string ret;
		for (auto it = first; it != last; ++it)
			ret += to_hex_string(*it);

		return ret;
	};

	void main()
	{
		console::print_title(3, 23, "Binary to string conversion");

		const unsigned char input[] = { 0xBA, 0xAD, 0xF0, 0x0D };
		std::cout << stringify(input, input + 4) << std::endl;
	};
};
};