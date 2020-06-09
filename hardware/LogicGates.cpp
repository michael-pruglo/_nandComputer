//
// Created by Michael on 06/08/20.
//

#include <iostream>
#include "LogicGates.hpp"

bool LogicGates::_nand(bool a, bool b)
{
    return !(a&b);
}

bool LogicGates::_not(bool in)
{
    return _nand(in, in);
}

bool LogicGates::_and(bool a, bool b)
{
    return _not(_nand(a, b));
}

bool LogicGates::_or(bool a, bool b)
{
    return _nand(_not(a), _not(b));
}

bool LogicGates::_xor(bool a, bool b)
{
    return _and(_or(a, b), _nand(a, b));
}

bool LogicGates::_mux(bool a, bool b, bool sel)
{
    return _nand(_nand(sel, b), _nand(_not(sel), a));
}

std::array<bool, 2> LogicGates::_dmux(bool in, bool sel)
{
    return {_and(_not(sel), in), _and(sel, in)};
}

std::string bits(uint32_t n)
{
    std::string res;
    for (unsigned i = 31; i; --i) {
        res.push_back(n & (1u << i) ? '1' : '0');
        if (i%8==0) res.push_back(' ');
    }
    return res;
}

LogicGates::Bus32 LogicGates::_not32(LogicGates::Bus32 in)
{
    for (unsigned i = 32; i--; )
        in = in & ~(1u<<i) | _not(in>>i&1u) << i;
    return in;
}
