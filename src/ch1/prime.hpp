#pragma once

#include "../utils/console.hpp"

namespace ch1 {
namespace prime
{
	template <typename T>
	bool is_prime(T val)
	{
		// SPECIAL RULE
		if (val <= 3) 
			return val >= 2;

		// ITERATION
		for (T i = 3; i <= (val / 2); ++i)
			if (val % i == 0)
				return false;
		
		return true;
	};

	template <typename T>
	T largest_prime(T limit)
	{
		for (; limit != 0; --limit)
			if (is_prime(limit))
				return limit;
	};

	void main()
	{
        // PREPARES
        console::print_title(1, 4, "Largest Prime");
        int limit = console::get_input<int>("limit");

		std::cout << largest_prime(limit) << std::endl;
	};
};
};