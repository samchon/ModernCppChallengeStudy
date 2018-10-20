#pragma once

#include "abundant.hpp"
#include "../utils/console.hpp"

namespace ch1 {
namespace amicable
{
    template <typename T>
    std::vector<std::pair<T, T>> solve(T limit)
    {
        std::vector<std::pair<T, T>> ret;

        for (T x = 1; x < limit; ++x)
        {
            T y = abundant::sum_of_divisors(x);
            if (x > y) // AVOID DUPLICATED PAIR
                continue;
            else if (x == y || x == abundant::sum_of_divisors(y))
                ret.push_back({ x, y }); // SOLUTION
        }
        return ret;
    };

    void main()
    {
        // PREPARES
        console::print_title(1, 7, "Amicable Numbers");
        unsigned long long limit = console::get_input<int>("limit");

        // SOLUTION
        auto solution = solve(limit);
        console::print_solution(solution);
    };
};
};