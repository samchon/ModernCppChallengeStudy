#pragma once
#include <string>

#include "../utils/console.hpp"

namespace ch1 {
namespace isbn
{
    /**
     * @refer https://en.wikipedia.org/wiki/International_Standard_Book_Number#ISBN-10_check_digits
     */
    bool validate(std::string str)
    {
        // ERASE '-' SYMBOLS
        while (true)
        {
            size_t idx = str.find("-");
            if (idx == std::string::npos)
                break;
            str = str.erase(idx, 1);
        }

        // MUST BE 10-DIGIT
        if (str.size() != 10)
            return false;

        // COMPUTE SUM
        int sum = 0;
        for (size_t i = 0; i < str.size(); ++i)
            sum += (str[i] - '0') * (10 - i);

        // VALIDATE
        return sum % 11 == 0;
    };

    void main()
    {
        console::print_title(1, 14, "ISBN Validator");
        std::string str = console::get_input<std::string>("ISBN");

        std::cout << validate(str) << std::endl;
    };
};
};