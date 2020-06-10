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
    return {
        _and(_not(sel), in),
        _and(     sel , in)
    };
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
    return    _not(  in &0x80000000u  ) <<31u
            | _not(  in &0x40000000u  ) <<30u
            | _not(  in &0x20000000u  ) <<29u
            | _not(  in &0x10000000u  ) <<28u
            | _not(  in & 0x8000000u  ) <<27u
            | _not(  in & 0x4000000u  ) <<26u
            | _not(  in & 0x2000000u  ) <<25u
            | _not(  in & 0x1000000u  ) <<24u
            | _not(  in &  0x800000u  ) <<23u
            | _not(  in &  0x400000u  ) <<22u
            | _not(  in &  0x200000u  ) <<21u
            | _not(  in &  0x100000u  ) <<20u
            | _not(  in &   0x80000u  ) <<19u
            | _not(  in &   0x40000u  ) <<18u
            | _not(  in &   0x20000u  ) <<17u
            | _not(  in &   0x10000u  ) <<16u
            | _not(  in &    0x8000u  ) <<15u
            | _not(  in &    0x4000u  ) <<14u
            | _not(  in &    0x2000u  ) <<13u
            | _not(  in &    0x1000u  ) <<12u
            | _not(  in &     0x800u  ) <<11u
            | _not(  in &     0x400u  ) <<10u
            | _not(  in &     0x200u  ) << 9u
            | _not(  in &     0x100u  ) << 8u
            | _not(  in &      0x80u  ) << 7u
            | _not(  in &      0x40u  ) << 6u
            | _not(  in &      0x20u  ) << 5u
            | _not(  in &      0x10u  ) << 4u
            | _not(  in &       0x8u  ) << 3u
            | _not(  in &       0x4u  ) << 2u
            | _not(  in &       0x2u  ) << 1u
            | _not(  in &       0x1u  ) << 0u
            ;
}

LogicGates::Bus32 LogicGates::_and32(LogicGates::Bus32 a, LogicGates::Bus32 b)
{
    return    _and(  a &0x80000000u,  b &0x80000000u  ) <<31u
            | _and(  a &0x40000000u,  b &0x40000000u  ) <<30u
            | _and(  a &0x20000000u,  b &0x20000000u  ) <<29u
            | _and(  a &0x10000000u,  b &0x10000000u  ) <<28u
            | _and(  a & 0x8000000u,  b & 0x8000000u  ) <<27u
            | _and(  a & 0x4000000u,  b & 0x4000000u  ) <<26u
            | _and(  a & 0x2000000u,  b & 0x2000000u  ) <<25u
            | _and(  a & 0x1000000u,  b & 0x1000000u  ) <<24u
            | _and(  a &  0x800000u,  b &  0x800000u  ) <<23u
            | _and(  a &  0x400000u,  b &  0x400000u  ) <<22u
            | _and(  a &  0x200000u,  b &  0x200000u  ) <<21u
            | _and(  a &  0x100000u,  b &  0x100000u  ) <<20u
            | _and(  a &   0x80000u,  b &   0x80000u  ) <<19u
            | _and(  a &   0x40000u,  b &   0x40000u  ) <<18u
            | _and(  a &   0x20000u,  b &   0x20000u  ) <<17u
            | _and(  a &   0x10000u,  b &   0x10000u  ) <<16u
            | _and(  a &    0x8000u,  b &    0x8000u  ) <<15u
            | _and(  a &    0x4000u,  b &    0x4000u  ) <<14u
            | _and(  a &    0x2000u,  b &    0x2000u  ) <<13u
            | _and(  a &    0x1000u,  b &    0x1000u  ) <<12u
            | _and(  a &     0x800u,  b &     0x800u  ) <<11u
            | _and(  a &     0x400u,  b &     0x400u  ) <<10u
            | _and(  a &     0x200u,  b &     0x200u  ) << 9u
            | _and(  a &     0x100u,  b &     0x100u  ) << 8u
            | _and(  a &      0x80u,  b &      0x80u  ) << 7u
            | _and(  a &      0x40u,  b &      0x40u  ) << 6u
            | _and(  a &      0x20u,  b &      0x20u  ) << 5u
            | _and(  a &      0x10u,  b &      0x10u  ) << 4u
            | _and(  a &       0x8u,  b &       0x8u  ) << 3u
            | _and(  a &       0x4u,  b &       0x4u  ) << 2u
            | _and(  a &       0x2u,  b &       0x2u  ) << 1u
            | _and(  a &       0x1u,  b &       0x1u  ) << 0u
            ;
}

LogicGates::Bus32 LogicGates::_or32(LogicGates::Bus32 a, LogicGates::Bus32 b)
{
    return    _or(  a &0x80000000u,  b &0x80000000u  ) <<31u
            | _or(  a &0x40000000u,  b &0x40000000u  ) <<30u
            | _or(  a &0x20000000u,  b &0x20000000u  ) <<29u
            | _or(  a &0x10000000u,  b &0x10000000u  ) <<28u
            | _or(  a & 0x8000000u,  b & 0x8000000u  ) <<27u
            | _or(  a & 0x4000000u,  b & 0x4000000u  ) <<26u
            | _or(  a & 0x2000000u,  b & 0x2000000u  ) <<25u
            | _or(  a & 0x1000000u,  b & 0x1000000u  ) <<24u
            | _or(  a &  0x800000u,  b &  0x800000u  ) <<23u
            | _or(  a &  0x400000u,  b &  0x400000u  ) <<22u
            | _or(  a &  0x200000u,  b &  0x200000u  ) <<21u
            | _or(  a &  0x100000u,  b &  0x100000u  ) <<20u
            | _or(  a &   0x80000u,  b &   0x80000u  ) <<19u
            | _or(  a &   0x40000u,  b &   0x40000u  ) <<18u
            | _or(  a &   0x20000u,  b &   0x20000u  ) <<17u
            | _or(  a &   0x10000u,  b &   0x10000u  ) <<16u
            | _or(  a &    0x8000u,  b &    0x8000u  ) <<15u
            | _or(  a &    0x4000u,  b &    0x4000u  ) <<14u
            | _or(  a &    0x2000u,  b &    0x2000u  ) <<13u
            | _or(  a &    0x1000u,  b &    0x1000u  ) <<12u
            | _or(  a &     0x800u,  b &     0x800u  ) <<11u
            | _or(  a &     0x400u,  b &     0x400u  ) <<10u
            | _or(  a &     0x200u,  b &     0x200u  ) << 9u
            | _or(  a &     0x100u,  b &     0x100u  ) << 8u
            | _or(  a &      0x80u,  b &      0x80u  ) << 7u
            | _or(  a &      0x40u,  b &      0x40u  ) << 6u
            | _or(  a &      0x20u,  b &      0x20u  ) << 5u
            | _or(  a &      0x10u,  b &      0x10u  ) << 4u
            | _or(  a &       0x8u,  b &       0x8u  ) << 3u
            | _or(  a &       0x4u,  b &       0x4u  ) << 2u
            | _or(  a &       0x2u,  b &       0x2u  ) << 1u
            | _or(  a &       0x1u,  b &       0x1u  ) << 0u
            ;
}

LogicGates::Bus32 LogicGates::_mux32(LogicGates::Bus32 a, LogicGates::Bus32 b, bool sel)
{
    return    _mux(  a &0x80000000u,  b &0x80000000u,  sel  ) <<31u
            | _mux(  a &0x40000000u,  b &0x40000000u,  sel  ) <<30u
            | _mux(  a &0x20000000u,  b &0x20000000u,  sel  ) <<29u
            | _mux(  a &0x10000000u,  b &0x10000000u,  sel  ) <<28u
            | _mux(  a & 0x8000000u,  b & 0x8000000u,  sel  ) <<27u
            | _mux(  a & 0x4000000u,  b & 0x4000000u,  sel  ) <<26u
            | _mux(  a & 0x2000000u,  b & 0x2000000u,  sel  ) <<25u
            | _mux(  a & 0x1000000u,  b & 0x1000000u,  sel  ) <<24u
            | _mux(  a &  0x800000u,  b &  0x800000u,  sel  ) <<23u
            | _mux(  a &  0x400000u,  b &  0x400000u,  sel  ) <<22u
            | _mux(  a &  0x200000u,  b &  0x200000u,  sel  ) <<21u
            | _mux(  a &  0x100000u,  b &  0x100000u,  sel  ) <<20u
            | _mux(  a &   0x80000u,  b &   0x80000u,  sel  ) <<19u
            | _mux(  a &   0x40000u,  b &   0x40000u,  sel  ) <<18u
            | _mux(  a &   0x20000u,  b &   0x20000u,  sel  ) <<17u
            | _mux(  a &   0x10000u,  b &   0x10000u,  sel  ) <<16u
            | _mux(  a &    0x8000u,  b &    0x8000u,  sel  ) <<15u
            | _mux(  a &    0x4000u,  b &    0x4000u,  sel  ) <<14u
            | _mux(  a &    0x2000u,  b &    0x2000u,  sel  ) <<13u
            | _mux(  a &    0x1000u,  b &    0x1000u,  sel  ) <<12u
            | _mux(  a &     0x800u,  b &     0x800u,  sel  ) <<11u
            | _mux(  a &     0x400u,  b &     0x400u,  sel  ) <<10u
            | _mux(  a &     0x200u,  b &     0x200u,  sel  ) << 9u
            | _mux(  a &     0x100u,  b &     0x100u,  sel  ) << 8u
            | _mux(  a &      0x80u,  b &      0x80u,  sel  ) << 7u
            | _mux(  a &      0x40u,  b &      0x40u,  sel  ) << 6u
            | _mux(  a &      0x20u,  b &      0x20u,  sel  ) << 5u
            | _mux(  a &      0x10u,  b &      0x10u,  sel  ) << 4u
            | _mux(  a &       0x8u,  b &       0x8u,  sel  ) << 3u
            | _mux(  a &       0x4u,  b &       0x4u,  sel  ) << 2u
            | _mux(  a &       0x2u,  b &       0x2u,  sel  ) << 1u
            | _mux(  a &       0x1u,  b &       0x1u,  sel  ) << 0u
            ;
}

bool LogicGates::_and8way(LogicGates::Bus8 in)
{
    return  _and(in &0x80u,
            _and(in &0x40u,
            _and(in &0x20u,
            _and(in &0x10u,
            _and(in & 0x8u,
            _and(in & 0x4u,
            _and(in & 0x2u,
                 in & 0x1u )))))));
}

bool LogicGates::_or8way(LogicGates::Bus8 in)
{
    return  _or(in &0x80u,
            _or(in &0x40u,
            _or(in &0x20u,
            _or(in &0x10u,
            _or(in & 0x8u,
            _or(in & 0x4u,
            _or(in & 0x2u,
                in & 0x1u )))))));
}

LogicGates::Bus32
LogicGates::_mux4way32(LogicGates::Bus32 a, LogicGates::Bus32 b, LogicGates::Bus32 c, LogicGates::Bus32 d,
                        bool sel0, bool sel1)
{
    return _mux32(_mux32(a,b,sel0), _mux32(c,d,sel0), sel1);
}

LogicGates::Bus32
LogicGates::_mux8way32(LogicGates::Bus32 a, LogicGates::Bus32 b, LogicGates::Bus32 c, LogicGates::Bus32 d,
                       LogicGates::Bus32 e, LogicGates::Bus32 f, LogicGates::Bus32 g, LogicGates::Bus32 h,
                       bool sel0, bool sel1, bool sel2)
{
    return _mux32(_mux4way32(a,b,c,d,sel0,sel1), _mux4way32(e,f,g,h,sel0,sel1), sel2);
}

std::array<bool, 4> LogicGates::_dmux4way(bool in, bool sel0, bool sel1)
{
    auto [v0, v1] = _dmux(in, sel0);
    return {
            _mux(v0, 0, sel1),
            _mux(v1, 0, sel1),
            _mux(0, v0, sel1),
            _mux(0, v1, sel1)
    };
}

std::array<bool, 8> LogicGates::_dmux8way(bool in, bool sel0, bool sel1, bool sel2)
{
    auto [v0, v1, v2, v3] = _dmux4way(in, sel0, sel1);
    return {
            _mux(v0, 0, sel2),
            _mux(v1, 0, sel2),
            _mux(v2, 0, sel2),
            _mux(v3, 0, sel2),
            _mux(0, v0, sel2),
            _mux(0, v1, sel2),
            _mux(0, v2, sel2),
            _mux(0, v3, sel2)
    };
}