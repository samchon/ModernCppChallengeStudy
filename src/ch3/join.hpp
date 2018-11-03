#pragma once

#include <vector>
#include <string>

#include "../utils/console.hpp"

namespace ch3
{
namespace join
{
	template <typename Elements>
	std::string join(const Elements &elements, const std::string &&delim)
	{
		std::string ret;
		for (auto elem : elements)
			ret += (std::string)elem + delim;

		ret.erase(ret.end() - delim.size(), ret.end());
		return ret;
	};

	void main()
	{
		console::print_title(3, 26, "Join string");

		auto elements = { "this","is","an","example" };
		std::cout << join(elements, " ") << std::endl;
	};
};
};