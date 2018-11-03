#pragma once

#include "stringify.hpp"
#include "binarify.hpp"
#include "capitalize.hpp"
#include "join.hpp"
#include "split.hpp"
#include "palindromic.hpp"
#include "license.hpp"
#include "uri.hpp"
#include "date.hpp"

namespace ch3
{
    void main()
    {
		stringify::main();
		binarify::main();
        capitalize::main();
		join::main();
		split::main();
		palindromic::main();
		license::main();
		uri::main();
		date::main();
    };
};