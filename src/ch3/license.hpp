#pragma once

#include <algorithm>
#include <functional>
#include <string>
#include <string_view>

#include "../utils/console.hpp"

namespace ch3
{
namespace license
{
	bool _In_range(char val, char first, char last)
	{
		return first <= val && val <= last;
	};

	bool validate(const std::string_view &str)
	{
		// VALIDATORS
		auto is_capital_letter = std::bind(_In_range, std::placeholders::_1, 'A', 'Z');
		auto is_number = std::bind(_In_range, std::placeholders::_1, '0', '9');

		// GET ELEMENTS
		size_t dash_idx = str.find("-");
		size_t space_idx = str.find(" ", dash_idx + 1);

		std::string_view elements[] = 
		{
			str.substr(0, dash_idx),
			str.substr(dash_idx + 1, space_idx - (dash_idx + 1)),
			str.substr(space_idx + 1)
		};

		// DO VALIDATE
		return std::all_of(elements[0].begin(), elements[0].end(), is_capital_letter)
			&& std::all_of(elements[1].begin(), elements[1].end(), is_capital_letter)
			&& std::all_of(elements[2].begin(), elements[2].end(), is_number);
	};

	void main()
	{
		console::print_title(3, 29, "License plate validation");

		std::string str = console::get_input<std::string>("license");
		std::cout << "validate: " << validate(str) << std::endl;
	};
};
};