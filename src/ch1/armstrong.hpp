#pragma once
#include <vector>

#include "../utils/console.hpp"

namespace ch1 {
namespace armstrong
{
    template <typename T>
    std::vector<T> get_digits(T val)
    {
        std::vector<T> ret;
        while (val != 0)
        {
            ret.push_back(val % 10);
            val /= 10;
        }
        return std::vector<T>(ret.rbegin(), ret.rend());
    };

	template <typename T>
	bool is_armstrong(T val)
	{
        std::vector<T> digits = get_digits(val);

        T sum = 0;
        for (T elem : digits)
            sum += elem * elem * elem;

        return val == sum;
	};

    template <typename T>
    std::vector<T> solve(T first = 100, T last = 999)
    {
        std::vector<T> ret;
        for (T i = first; i <= last; ++i)
            if (is_armstrong(i))
                ret.push_back(i);

        return ret;
    };

    void main()
    {
        console::print_title(1, 8, "Armstrong Numbers");

        std::vector<int> solution = solve<int>();
        console::print_solution(solution);
    };
};
};