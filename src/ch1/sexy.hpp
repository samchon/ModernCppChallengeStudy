#pragma once
#include <vector>
#include <unordered_map>

#include "../utils/console.hpp"

namespace ch1 {
namespace sexy
{
    template <typename T>
    bool is_prime(T val)
    {
        // SPECIAL RULE
        static std::unordered_map<T, bool> cache;
        if (val <= 3)
            return val >= 2;
        else if (cache.count(val))
            return cache.at(val);

        // ITERATION
        for (T i = 3; i <= (val / 2); ++i)
            if (val % i == 0)
            {
                cache.emplace(val, false);
                return false;
            }

        cache.emplace(val, true);
        return true;
    };

    template <typename T>
    bool is_sexy_prime(T val)
    {
        return is_prime(val) && is_prime(val + 6);
    };

    template <typename T>
    std::vector<T> solve(T limit)
    {
        std::vector<T> ret;
        for (T i = 2; i <= limit; ++i)
            if (is_sexy_prime(i))
                ret.push_back(i);

        return ret;
    };

    void main()
    {
        // PREPARES
        console::print_title(1, 5, "Sexy Prime Pairs");
        int limit = console::get_input<int>("limit");

        // SOLUTION
        std::vector<int> solution = solve(limit);
        console::print_solution(solution);
    };
};
};