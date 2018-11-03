#pragma once

#include <vector>
#include <string>
#include <string_view>

#include "../utils/console.hpp"

namespace ch3
{
namespace split
{
	std::vector<std::string_view> split(const std::string_view &str, const std::vector<std::string> &delims)
	{
		std::vector<std::string_view> ret;
		size_t start = 0;
		size_t x;

		auto insert = [&ret](const std::string_view &part)
		{
			if (!part.empty())
				ret.push_back(part);
		};

		while (true)
		{
			std::string_view first;
			size_t minimum = std::string_view::npos;

			for (auto delim : delims)
			{
				size_t pos = str.find(delim, start);
				if (pos != std::string_view::npos)
					if (minimum == std::string_view::npos || pos < minimum)
					{
						first = delim;
						minimum = pos;
					}
			}

			if (minimum == std::string_view::npos)
				break;

			insert(str.substr(start, minimum - start));

			x = minimum;
			start = minimum + first.size();
		}
		insert(str.substr(start, str.size() - start));
		return ret;
	};

	void main()
	{
		console::print_title(3, 27, "Split string");

		std::string str = "this,is.a sample!!";
		std::vector<std::string> delims = { ",", ".", " ", "!" };

		auto ret = split(str, delims);
		console::print_solution(ret);
	};
};
};