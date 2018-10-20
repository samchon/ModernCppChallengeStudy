#pragma once

#include "../utils/console.hpp"

namespace ch1 {
namespace collatz
{
    template <typename T>
    bool is_colatz(T val, size_t &step)
    {
        for (step = 0; step < 1'000'000; ++step)
            if (val == 1)
                return true;
            else if (val % 2 == 0)
                val /= 2;
            else
                val = val * 3 + 1;
    };

    void main()
    {
        console::print_title(1, 12, "Largest Collatz");
        unsigned long long val = console::get_input<unsigned long long>("value");
        size_t step;

        std::cout << "success: " << is_colatz(val, step) << std::endl;
        std::cout << "step: " << step << std::endl;
    };
};
};