#pragma once

#include "../utils/console.hpp"

namespace ch1 {
namespace divisible
{
	template<typename T>
	T sum_of_divisible(T divide, T limit)
	{
		unsigned int n = (unsigned int)(limit / divide);
		return divide * n * (n + 1) / 2;
	};

    template <typename T>
    T solve(T limit)
    {
        return sum_of_divisible(3, limit)
            + sum_of_divisible(5, limit)
            - sum_of_divisible(15, limit);
    };

	void main()
	{
        // PREPARES
        console::print_title(1, 1, "Sum of naturals divisible by 3 and 5");
        int limit = console::get_input<int>("limit");

        // SOLUTION
		std::cout << solve(limit) << std::endl;
	};
};
};