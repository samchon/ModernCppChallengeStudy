#pragma once
#include <vector>
#include <utility>

#include "../utils/console.hpp"

namespace ch1 {
namespace abundant
{
    template <typename T>
    T sum_of_divisors(T val)
    {
        T ret = 0;
        for (T i = 1; i <= val / 2; ++i)
            if (val % i == 0)
                ret += i;
        
        return ret;
    };

    template <typename T>
    std::vector<std::pair<T, T>> solve(T limit)
    {
        std::vector<std::pair<T, T>> ret;
        for (T i = 0; i < limit; ++i)
        {
            T sum = sum_of_divisors(i);
            if (sum > i)
                ret.push_back({ i, sum });
        }

        return ret;
    };

    void main()
    {
        // PREPARES
        console::print_title(1, 6, "Abundant Numbers");
        int limit = console::get_input<int>("limit");

        // SOLUTION
        std::vector<std::pair<int, int>> solution = solve(limit);
        console::print_solution(solution);
    };
};
};