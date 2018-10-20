#pragma once
#include <vector>

#include "../utils/console.hpp"
#include "sexy.hpp"

namespace ch1 {
namespace factors
{
    template <typename T>
    std::vector<T> get_prime_factors(T val)
    {
        std::vector<T> ret;

        for (T i = 2; i <= (val / 2); ++i)
            if (val % i == 0 && sexy::is_prime(i))
                ret.push_back(i); // sexy.is_prime use memorization
                    
        return ret;
    };

    void main()
    {
        console::print_title(1, 9, "Prime factors");
        int val = console::get_input<int>("value");

        std::vector<int> solution = get_prime_factors(val);
        console::print_solution(solution);
    };
};
};