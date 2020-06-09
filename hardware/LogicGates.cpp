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
    for (unsigned i = 32; i--; ) {
        res.push_back(n & (1u << i) ? '1' : '0');
        if (i%8==0) res.push_back(' ');
    }
    return res;
}

LogicGates::Bus32 LogicGates::_not32(LogicGates::Bus32 in)
{
    for (unsigned i = 32; i--; )
        setbit(in, i, _not(getbit(in,i)));
    return in;
}

LogicGates::Bus32 LogicGates::_and32(LogicGates::Bus32 a, LogicGates::Bus32 b)
{
    for (unsigned i = 32; i--; )
        setbit(a, i, _and(getbit(a,i), getbit(b,i)));
    return a;
}

LogicGates::Bus32 LogicGates::_or32(LogicGates::Bus32 a, LogicGates::Bus32 b)
{
    for (unsigned i = 32; i--; )
        setbit(a, i, _or(getbit(a,i), getbit(b,i)));
    return a;
}

LogicGates::Bus32 LogicGates::_mux32(LogicGates::Bus32 a, LogicGates::Bus32 b, bool sel)
{
    for (unsigned i = 32; i--; )
        setbit(a, i, _mux(getbit(a,i), getbit(b,i), sel));
    return a;
}

bool LogicGates::_and8way(LogicGates::Bus8 in)
{
    bool res = getbit(in, 7);
    for (unsigned i = 7; i--; )
        res = _and(res, getbit(in, i));
    return res;
}

bool LogicGates::_or8way(LogicGates::Bus8 in)
{
    bool res = getbit(in, 7);
    for (unsigned i = 7; i--; )
        res = _or(res, getbit(in, i));
    return res;
}

LogicGates::Bus32
LogicGates::_mux4way32(LogicGates::Bus32 a, LogicGates::Bus32 b, LogicGates::Bus32 c, LogicGates::Bus32 d,
                        bool sel0, bool sel1)
{
    return _mux32(_mux32(a,b,sel0), _mux32(c,d,sel0), sel1);
}

LogicGates::Bus32
LogicGates::_mux8way32(LogicGates::Bus32 a, LogicGates::Bus32 b, LogicGates::Bus32 c, LogicGates::Bus32 d,
                       LogicGates::Bus32 e, LogicGates::Bus32 f, LogicGates::Bus32 g, LogicGates::Bus32 h, bool sel0,
                       bool sel1, bool sel2)
{
    return _mux32(_mux4way32(a,b,c,d,sel0,sel1), _mux4way32(e,f,g,h,sel0,sel1), sel2);
}

std::array<bool, 4> LogicGates::_dmux4way(bool in, bool sel0, bool sel1)
{
    return {
            _mux(_dmux(in, sel0)[0], 0, sel1),
            _mux(_dmux(in, sel0)[1], 0, sel1),
            _mux(0, _dmux(in, sel0)[0], sel1),
            _mux(0, _dmux(in, sel0)[1], sel1)
    };
}

std::array<bool, 8> LogicGates::_dmux8way(bool in, bool sel0, bool sel1, bool sel2)
{
    return {
            _mux(_dmux4way(in, sel0, sel1)[0], 0, sel2),
            _mux(_dmux4way(in, sel0, sel1)[1], 0, sel2),
            _mux(_dmux4way(in, sel0, sel1)[2], 0, sel2),
            _mux(_dmux4way(in, sel0, sel1)[3], 0, sel2),
            _mux(0, _dmux4way(in, sel0, sel1)[0], sel2),
            _mux(0, _dmux4way(in, sel0, sel1)[1], sel2),
            _mux(0, _dmux4way(in, sel0, sel1)[2], sel2),
            _mux(0, _dmux4way(in, sel0, sel1)[3], sel2)
    };
}
