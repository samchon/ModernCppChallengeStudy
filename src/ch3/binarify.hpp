#pragma once

#include <string_view>
#include <vector>
#include <exception>

#include "../utils/console.hpp"

namespace ch3
{
namespace binarify
{
	int to_hex(char letter)
	{
		if ('A' <= letter <= 'F')
			return letter - 'A' + 10;
		else
			return letter - '0';
	};
	
	std::vector<int> binarify(const std::string_view &str)
	{
		if (str.size() % 2 != 0)
			throw std::invalid_argument("Number of characters must be even.");

		std::vector<int> ret;
		for (size_t i = 0; i < str.size(); i += 2)
		{
			std::string_view piece = str.substr(i, 2);
			int value = to_hex(piece[0]) * 16;
			value += to_hex(piece[1]);

			ret.push_back(value);
		}
		return ret;
	};

	void main()
	{
		console::print_title(3, 24, "String to binary conversion");

		std::string str = console::get_input<std::string>("hex string");
		std::vector<int> ret = binarify(str);

		console::print_solution(ret);
	};
};
};