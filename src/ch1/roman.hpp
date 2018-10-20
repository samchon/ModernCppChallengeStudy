#pragma once
#include <map>
#include <string>

#include "../utils/console.hpp"

namespace ch1 {
namespace roman
{
    template <typename T>
    std::string convert(T val)
    {
        static std::map<T, std::string> TABLE = 
        {
            { 1000, "M" },{ 900, "CM" },
            { 500, "D" },{ 400, "CD" },
            { 100, "C" },{ 90, "XC" },
            { 50, "L" },{ 40, "XL" },
            { 10, "X" },{ 9, "IX" },
            { 5, "V" },{ 4, "IV" },
            { 1, "I" }
        };

        std::string ret = "";
        while (val != 0)
        {
            // FIND THE NEAREST ONE
            auto it = TABLE.upper_bound(val);
            --it;

            // POST-PROCESS
            val -= it->first;
            ret += it->second;
        }
        return ret;
    };

    void main()
    {
        console::print_title(1, 7, "Roman number");
        int val = console::get_input<int>("value");

        std::cout << convert(val) << std::endl;
    };
};
};