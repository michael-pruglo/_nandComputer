//
// Created by Michael on 06/10/20.
//

#include "Adders.hpp"

std::array<bool, 2> Adders::_half_adder(bool a, bool b)
{
    return {
        _xor(a, b),
        _and(a, b)
    };
}
