//
// Created by Michael on 06/08/20.
//

#include "LogicGates.hpp"

bool LogicGates::_nand(bool a, bool b)
{
    return !(a&b);
}

bool LogicGates::_not(bool a)
{
    return _nand(a, a);
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
