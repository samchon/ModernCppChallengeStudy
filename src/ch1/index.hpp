#pragma once

#include "divisible.hpp"
#include "gcd.hpp"
#include "lcm.hpp"
#include "prime.hpp"
#include "sexy.hpp"
#include "abundant.hpp"
#include "amicable.hpp"
#include "armstrong.hpp"
#include "factors.hpp"
#include "gray.hpp"
#include "roman.hpp"
#include "collatz.hpp"
#include "pi.hpp"
#include "isbn.hpp";

namespace ch1
{
    void main()
    {
        divisible::main();
        gcd::main();
        lcm::main();
        prime::main();
        sexy::main();
        abundant::main();
        amicable::main();
        armstrong::main();
        factors::main();
        gray::main(); // Failed
        roman::main();
        collatz::main();
        isbn::main();
        pi::main();
    };
};