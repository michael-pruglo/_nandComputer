#ifndef NANDCOMPUTER_ALU_HPP
#define NANDCOMPUTER_ALU_HPP

#include <tuple>
#include "Hardware.hpp"
#include "BasicGates.hpp"
#include "Adders.hpp"

namespace Hardware::ALU
{
    std::tuple<Bus32,bool,bool> _alu(Bus32 x, Bus32 y,
                                     bool zx, bool nx, bool zy, bool ny, bool f, bool no);
}

///Implementation
namespace Hardware::ALU
{
    using namespace Hardware::BasicGates;
    using namespace Hardware::Adders;

    inline Bus32 _prepare32(Bus32 in, bool z, bool n) {
        bool tmp = _xnor(z, n);
        return    _mux(   n, tmp, (in &0x80000000u)   ) <<31u
                  | _mux(   n, tmp, (in &0x40000000u)   ) <<30u
                  | _mux(   n, tmp, (in &0x20000000u)   ) <<29u
                  | _mux(   n, tmp, (in &0x10000000u)   ) <<28u
                  | _mux(   n, tmp, (in & 0x8000000u)   ) <<27u
                  | _mux(   n, tmp, (in & 0x4000000u)   ) <<26u
                  | _mux(   n, tmp, (in & 0x2000000u)   ) <<25u
                  | _mux(   n, tmp, (in & 0x1000000u)   ) <<24u
                  | _mux(   n, tmp, (in &  0x800000u)   ) <<23u
                  | _mux(   n, tmp, (in &  0x400000u)   ) <<22u
                  | _mux(   n, tmp, (in &  0x200000u)   ) <<21u
                  | _mux(   n, tmp, (in &  0x100000u)   ) <<20u
                  | _mux(   n, tmp, (in &   0x80000u)   ) <<19u
                  | _mux(   n, tmp, (in &   0x40000u)   ) <<18u
                  | _mux(   n, tmp, (in &   0x20000u)   ) <<17u
                  | _mux(   n, tmp, (in &   0x10000u)   ) <<16u
                  | _mux(   n, tmp, (in &    0x8000u)   ) <<15u
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
    inline Bus32 _neg_if32(Bus32 in, bool n) {
        return    _xor( in &0x80000000u, n ) <<31u
                | _xor( in &0x40000000u, n ) <<30u
                | _xor( in &0x20000000u, n ) <<29u
                | _xor( in &0x10000000u, n ) <<28u
                | _xor( in & 0x8000000u, n ) <<27u
                | _xor( in & 0x4000000u, n ) <<26u
                | _xor( in & 0x2000000u, n ) <<25u
                | _xor( in & 0x1000000u, n ) <<24u
                | _xor( in &  0x800000u, n ) <<23u
                | _xor( in &  0x400000u, n ) <<22u
                | _xor( in &  0x200000u, n ) <<21u
                | _xor( in &  0x100000u, n ) <<20u
                | _xor( in &   0x80000u, n ) <<19u
                | _xor( in &   0x40000u, n ) <<18u
                | _xor( in &   0x20000u, n ) <<17u
                | _xor( in &   0x10000u, n ) <<16u
                | _xor( in &    0x8000u, n ) <<15u
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
    std::tuple<Bus32,bool,bool> _alu(Bus32 x, Bus32 y,
                                     bool zx, bool nx, bool zy, bool ny, bool f, bool no)
    {
        x = _prepare32(x, zx, nx);
        y = _prepare32(y, zy, ny);
        Bus32 out = _mux32(_and32(x, y), _add32(x, y), f);
        out = _neg_if32(out, no);

        bool zr = _is_zero32(out);
        bool ng = out&0x80'00'00'00;
        return std::tuple<Bus32,bool,bool>{out, zr, ng};
    }
}
#endif //NANDCOMPUTER_ALU_HPP
