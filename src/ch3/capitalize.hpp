#pragma once
#include <string>
#include <string_view>
#include <vector>

#include "../utils/console.hpp"

namespace ch3
{
namespace capitalize
{
    std::vector<std::string_view> split(const std::string_view &str, const std::string_view &delim)
    {
        std::vector<std::string_view> ret;
        size_t start = 0;
        size_t x;

		auto insert = [&ret](const std::string_view &part)
		{
			if (!part.empty())
				ret.push_back(part);
		};

        while ((x = str.find(delim, start)) != std::string_view::npos)
        {
            insert(str.substr(start, x - start));
            start = x + delim.size();
        }
        insert(str.substr(start, str.size() - start));
        return ret;
    }

	std::string capitalize(const std::string_view &str)
	{
        std::string ret;
        std::vector<std::string_view> words = split(str, " ");

        for (auto word : words)
        {
            // CAPITALIZE THE FIRST CHARACTER
            char first = word[0];
            if ('a' <= first && first <= 'z')
                ret += first + ('A' - 'a');
            
            // ATTACH THE TAIL
            if (words.size() > 1)
                ret += word.substr(1);
            ret += " ";
        }
        return ret;
	};

	void main()
	{
		console::print_title(3, 25, "Capitalize an article title");

        std::string str = console::get_input<std::string>("title");
		std::cout << capitalize(str) << std::endl;
	};
};
};