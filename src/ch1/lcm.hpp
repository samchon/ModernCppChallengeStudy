#pragma once

#include "../utils/console.hpp"
#include "gcd.hpp"

namespace ch1 {
namespace lcm
{
	template <typename T>
	T lcm(T x, T y)
	{
		return x * y / gcd::gcd(x, y);
	};

    void main()
    {
        // PREPARES
        console::print_title(1, 3, "Least Common Multiple");
        int x = console::get_input<int>("x");
        int y = console::get_input<int>("y");

        // SOLUTION
        std::cout << lcm(x, y) << std::endl;
    };
};
};