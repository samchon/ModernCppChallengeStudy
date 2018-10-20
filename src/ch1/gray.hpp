#pragma once
#include <cmath>

#include "../utils/console.hpp"

namespace ch1 {
/**
 * @refer https://en.wikipedia.org/wiki/International_Standard_Book_Number#ISBN-10_check_digits
 */
namespace gray
{
    template <typename T>
    T to_binary(T val, size_t digit)
    {
        for (size_t i = 0; i < digit; ++i)
        {
            T unit = (T)(pow(2, i));
            val = val ^ (val >> unit);
        }
        return val;
    };

    template <typename T>
    T encode(T val)
    {
        return val ^ (val >> 1);
    };

    template <typename T>
    T decode(T val)
    {
        T mask = val >> 1;
        while (mask != 0)
        {
            val = val ^ mask;
            mask = mask >> 1;
        }
        return val;
    };

    template <typename T>
    void solve(size_t digit)
    {
        std::cout << "Number\tBinary\tGray\tDecoded\n";
        std::cout << "------\t------\t----\t-------\n";

        for (T i = 0; i < (T)pow(2, digit); ++i)
            std::cout << i << '\t'
                << to_binary(i, digit) << '\t'
                << encode(i) << '\t'
                << decode(i) << '\t'
                << std::endl;
    };

    void main()
    {
        console::print_title(1, 10, "Gray Code");
        solve<unsigned int>(5);
    }
};
};