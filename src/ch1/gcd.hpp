#pragma once

#include "../utils/console.hpp"

namespace ch1 {
namespace gcd
{
	template <typename T>
	T gcd(T x, T y)
	{
        while (y > 0)
        {
            T temp = y;

            y = x % y;
            x = temp;
        }
		return x;
	};

    void main()
    {
        // PREPARES
        console::print_title(1, 2, "Greatest Common Divisor");
        int x = console::get_input<int>("x");
        int y = console::get_input<int>("y");

        // SOLUTION
        std::cout << gcd(x, y) << std::endl;
    };
};
};