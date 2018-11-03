#pragma once

#include <string_view>

#include "../utils/console.hpp"

namespace ch3
{
namespace palindromic
{
	size_t _Compute(std::string_view str, size_t left, size_t right)
	{
		size_t ret = 0;
		while (str[left] == str[right])
		{
			++ret;
			if (left-- == 0 || ++right == str.size())
				break;
		}
		return ret;
	};

	std::string_view find(std::string_view str)
	{
		std::string_view ret;
		for (size_t i = 0; i < str.size(); ++i)
		{
			// ODD
			if (i > 0 && i < str.size() - 1)
			{
				size_t length = _Compute(str, i-1, i+1);
				std::string_view letter = str.substr(i - length, 2 * length + 1);

				if (letter.size() > ret.size())
					ret = letter;
			}

			// EVEN
			if (i < str.size() - 1 && str[i] == str[i + 1])
			{
				size_t length = _Compute(str, i, i + 1);
				std::string_view letter = str.substr(i - length + 1, 2 * length);

				if (letter.size() > ret.size())
					ret = letter;
			}
		}
		if (ret.empty() && !str.empty())
			return str.substr(0, 1);
		else
			return ret;
	};

	void main()
	{
		console::print_title(3, 28, "Longest palindromic substring");

		std::string str = console::get_input<std::string>("value");
		std::cout << find(str) << std::endl;
	};
};
};