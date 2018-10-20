#pragma once
#include <cmath>

#include "../utils/console.hpp"

namespace ch1 {
namespace pi
{
    template <typename T>
    T compute(size_t inf = 1000 * 1000)
    {
        T ret = (T)0;
        for (size_t n = 1; n <= inf; ++n)
            ret += (T)(1.0 / (n * n));

        return (T)sqrt(ret * 6.0);
    };

    void main()
    {
        console::print_title(1, 13, "Computing Pi");
        std::cout << compute<double>() << std::endl;
    };
};
};