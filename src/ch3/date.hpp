#pragma once

#include <string>
#include <string_view>
#include <vector>

#include "split.hpp"
#include "../utils/console.hpp"

namespace ch3
{
namespace date
{
	std::string convert(const std::string_view &str)
	{
		auto elems = split::split(str, {".", "-"});

		return (std::string)elems[2] + "-" 
			+ (std::string)elems[1] + "-"
			+ (std::string)elems[0];
	};

	void main()
	{
		console::print_title(3, 31, "Transforming dates in strings");
		std::string str = console::get_input<std::string>("date");

		std::cout << convert(str) << std::endl;
	};
};
};