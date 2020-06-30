#ifndef NANDCOMPUTER_ALU_HPP
#define NANDCOMPUTER_ALU_HPP

#include <tuple>
#include "Hardware.hpp"
#include "BasicGates.hpp"
#include "Adders.hpp"

namespace Hardware::ALU
{
    std::tuple<Bus16,bool,bool> _alu(Bus16 x, Bus16 y,
                                     bool zx, bool nx, bool zy, bool ny, bool f, bool no);
}

///Implementation
namespace Hardware::ALU
{
    using namespace Hardware::BasicGates;
    using namespace Hardware::Adders;

    inline Bus16 _prepare16(Bus16 in, bool z, bool n) {
        bool tmp = _xnor(z, n);
        return    _mux(   n, tmp, (in &    0x8000u)   ) <<15u
                | _mux(   n, tmp, (in &    0x4000u)   ) <<14u
                | _mux(   n, tmp, (in &    0x2000u)   ) <<13u
                | _mux(   n, tmp, (in &    0x1000u)   ) <<12u
                | _mux(   n, tmp, (in &     0x800u)   ) <<11u
                | _mux(   n, tmp, (in &     0x400u)   ) <<10u
                | _mux(   n, tmp, (in &     0x200u)   ) << 9u
                | _mux(   n, tmp, (in &     0x100u)   ) << 8u
                | _mux(   n, tmp, (in &      0x80u)   ) << 7u
                | _mux(   n, tmp, (in &      0x40u)   ) << 6u
                | _mux(   n, tmp, (in &      0x20u)   ) << 5u
                | _mux(   n, tmp, (in &      0x10u)   ) << 4u
                | _mux(   n, tmp, (in &       0x8u)   ) << 3u
                | _mux(   n, tmp, (in &       0x4u)   ) << 2u
                | _mux(   n, tmp, (in &       0x2u)   ) << 1u
                | _mux(   n, tmp, (in &       0x1u)   ) << 0u
                ;
    }
    inline Bus16 _neg_if16(Bus16 in, bool n) {
        return    _xor( in &    0x8000u, n ) <<15u
                | _xor( in &    0x4000u, n ) <<14u
                | _xor( in &    0x2000u, n ) <<13u
                | _xor( in &    0x1000u, n ) <<12u
                | _xor( in &     0x800u, n ) <<11u
                | _xor( in &     0x400u, n ) <<10u
                | _xor( in &     0x200u, n ) << 9u
                | _xor( in &     0x100u, n ) << 8u
                | _xor( in &      0x80u, n ) << 7u
                | _xor( in &      0x40u, n ) << 6u
                | _xor( in &      0x20u, n ) << 5u
                | _xor( in &      0x10u, n ) << 4u
                | _xor( in &       0x8u, n ) << 3u
                | _xor( in &       0x4u, n ) << 2u
                | _xor( in &       0x2u, n ) << 1u
                | _xor( in &       0x1u, n ) << 0u
                ;
    }
    std::tuple<Bus16,bool,bool> _alu(Bus16 x, Bus16 y,
                                     bool zx, bool nx, bool zy, bool ny, bool f, bool no)
    {
        x = _prepare16(x, zx, nx);
        y = _prepare16(y, zy, ny);
        Bus16 out = _mux16(_and16(x, y), _add16(x, y), f);
        out = _neg_if16(out, no);

        bool zr = _is_zero16(out);
        bool ng = out&0x80'00;
        return std::tuple<Bus16,bool,bool>{out, zr, ng};
    }
}
#endif //NANDCOMPUTER_ALU_HPP
