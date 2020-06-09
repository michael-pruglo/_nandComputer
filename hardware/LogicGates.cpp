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
bool LogicGates::_xor_v2(bool a, bool b)
{
    return _or(_and(a, _not(b)), _and(_not(a), b));
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
LogicGates::Bus32 LogicGates::_and32_v2(LogicGates::Bus32 a, LogicGates::Bus32 b)
{
    for (unsigned i = 32; i--; )
        a = a & ~(1u<<i) | _and(a>>i&1u, b>>i&1u) << i;
    return a;
}
LogicGates::Bus32 LogicGates::_and32_v3(LogicGates::Bus32 a, LogicGates::Bus32 b)
{
    a = a & ~(1u<<31u) | _and(a>>31u&1u, b>>31u&1u) << 31u;
    a = a & ~(1u<<30u) | _and(a>>30u&1u, b>>30u&1u) << 30u;
    a = a & ~(1u<<29u) | _and(a>>29u&1u, b>>29u&1u) << 29u;
    a = a & ~(1u<<28u) | _and(a>>28u&1u, b>>28u&1u) << 28u;
    a = a & ~(1u<<27u) | _and(a>>27u&1u, b>>27u&1u) << 27u;
    a = a & ~(1u<<26u) | _and(a>>26u&1u, b>>26u&1u) << 26u;
    a = a & ~(1u<<25u) | _and(a>>25u&1u, b>>25u&1u) << 25u;
    a = a & ~(1u<<24u) | _and(a>>24u&1u, b>>24u&1u) << 24u;
    a = a & ~(1u<<23u) | _and(a>>23u&1u, b>>23u&1u) << 23u;
    a = a & ~(1u<<22u) | _and(a>>22u&1u, b>>22u&1u) << 22u;
    a = a & ~(1u<<21u) | _and(a>>21u&1u, b>>21u&1u) << 21u;
    a = a & ~(1u<<20u) | _and(a>>20u&1u, b>>20u&1u) << 20u;
    a = a & ~(1u<<19u) | _and(a>>19u&1u, b>>19u&1u) << 19u;
    a = a & ~(1u<<18u) | _and(a>>18u&1u, b>>18u&1u) << 18u;
    a = a & ~(1u<<17u) | _and(a>>17u&1u, b>>17u&1u) << 17u;
    a = a & ~(1u<<16u) | _and(a>>16u&1u, b>>16u&1u) << 16u;
    a = a & ~(1u<<15u) | _and(a>>15u&1u, b>>15u&1u) << 15u;
    a = a & ~(1u<<14u) | _and(a>>14u&1u, b>>14u&1u) << 14u;
    a = a & ~(1u<<13u) | _and(a>>13u&1u, b>>13u&1u) << 13u;
    a = a & ~(1u<<12u) | _and(a>>12u&1u, b>>12u&1u) << 12u;
    a = a & ~(1u<<11u) | _and(a>>11u&1u, b>>11u&1u) << 11u;
    a = a & ~(1u<<10u) | _and(a>>10u&1u, b>>10u&1u) << 10u;
    a = a & ~(1u<<9u) | _and(a>>9u&1u, b>>9u&1u) << 9u;
    a = a & ~(1u<<8u) | _and(a>>8u&1u, b>>8u&1u) << 8u;
    a = a & ~(1u<<7u) | _and(a>>7u&1u, b>>7u&1u) << 7u;
    a = a & ~(1u<<6u) | _and(a>>6u&1u, b>>6u&1u) << 6u;
    a = a & ~(1u<<5u) | _and(a>>5u&1u, b>>5u&1u) << 5u;
    a = a & ~(1u<<4u) | _and(a>>4u&1u, b>>4u&1u) << 4u;
    a = a & ~(1u<<3u) | _and(a>>3u&1u, b>>3u&1u) << 3u;
    a = a & ~(1u<<2u) | _and(a>>2u&1u, b>>2u&1u) << 2u;
    a = a & ~(1u<<1u) | _and(a>>1u&1u, b>>1u&1u) << 1u;
    a = a & ~(1u<<0u) | _and(a>>0u&1u, b>>0u&1u) << 0u;
    return a;
}
LogicGates::Bus32 LogicGates::_and32_v4(LogicGates::Bus32 a, LogicGates::Bus32 b)
{
    a = a & 0x7fffffff | _and(a>>31u&1u, b>>31u&1u) << 31u;
    a = a & 0xbfffffff | _and(a>>30u&1u, b>>30u&1u) << 30u;
    a = a & 0xdfffffff | _and(a>>29u&1u, b>>29u&1u) << 29u;
    a = a & 0xefffffff | _and(a>>28u&1u, b>>28u&1u) << 28u;
    a = a & 0xf7ffffff | _and(a>>27u&1u, b>>27u&1u) << 27u;
    a = a & 0xfbffffff | _and(a>>26u&1u, b>>26u&1u) << 26u;
    a = a & 0xfdffffff | _and(a>>25u&1u, b>>25u&1u) << 25u;
    a = a & 0xfeffffff | _and(a>>24u&1u, b>>24u&1u) << 24u;
    a = a & 0xff7fffff | _and(a>>23u&1u, b>>23u&1u) << 23u;
    a = a & 0xffbfffff | _and(a>>22u&1u, b>>22u&1u) << 22u;
    a = a & 0xffdfffff | _and(a>>21u&1u, b>>21u&1u) << 21u;
    a = a & 0xffefffff | _and(a>>20u&1u, b>>20u&1u) << 20u;
    a = a & 0xfff7ffff | _and(a>>19u&1u, b>>19u&1u) << 19u;
    a = a & 0xfffbffff | _and(a>>18u&1u, b>>18u&1u) << 18u;
    a = a & 0xfffdffff | _and(a>>17u&1u, b>>17u&1u) << 17u;
    a = a & 0xfffeffff | _and(a>>16u&1u, b>>16u&1u) << 16u;
    a = a & 0xffff7fff | _and(a>>15u&1u, b>>15u&1u) << 15u;
    a = a & 0xffffbfff | _and(a>>14u&1u, b>>14u&1u) << 14u;
    a = a & 0xffffdfff | _and(a>>13u&1u, b>>13u&1u) << 13u;
    a = a & 0xffffefff | _and(a>>12u&1u, b>>12u&1u) << 12u;
    a = a & 0xfffff7ff | _and(a>>11u&1u, b>>11u&1u) << 11u;
    a = a & 0xfffffbff | _and(a>>10u&1u, b>>10u&1u) << 10u;
    a = a & 0xfffffdff | _and(a>>9u&1u, b>>9u&1u) << 9u;
    a = a & 0xfffffeff | _and(a>>8u&1u, b>>8u&1u) << 8u;
    a = a & 0xffffff7f | _and(a>>7u&1u, b>>7u&1u) << 7u;
    a = a & 0xffffffbf | _and(a>>6u&1u, b>>6u&1u) << 6u;
    a = a & 0xffffffdf | _and(a>>5u&1u, b>>5u&1u) << 5u;
    a = a & 0xffffffef | _and(a>>4u&1u, b>>4u&1u) << 4u;
    a = a & 0xfffffff7 | _and(a>>3u&1u, b>>3u&1u) << 3u;
    a = a & 0xfffffffb | _and(a>>2u&1u, b>>2u&1u) << 2u;
    a = a & 0xfffffffd | _and(a>>1u&1u, b>>1u&1u) << 1u;
    a = a & 0xfffffffe | _and(a>>0u&1u, b>>0u&1u) << 0u;
    return a;
}
LogicGates::Bus32 LogicGates::_and32_v5(LogicGates::Bus32 a, LogicGates::Bus32 b)
{
    return a&b;
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