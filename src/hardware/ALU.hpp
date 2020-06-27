#ifndef NANDCOMPUTER_ALU_HPP
#define NANDCOMPUTER_ALU_HPP

#include <tuple>
#include "Hardware.hpp"
#include "BasicGates.hpp"
#include "Adders.hpp"

namespace Hardware::ALU
{
    using namespace Hardware::BasicGates;
    using namespace Hardware::Adders;

    inline Bus32 _prepare32(Bus32 in, bool z, bool n) {
        z = _not(z);
        return    _xor(  _and(in &0x80000000u, z),  n  ) <<31u //TODO: xnor
                | _xor(  _and(in &0x40000000u, z),  n  ) <<30u
                | _xor(  _and(in &0x20000000u, z),  n  ) <<29u
                | _xor(  _and(in &0x10000000u, z),  n  ) <<28u
                | _xor(  _and(in & 0x8000000u, z),  n  ) <<27u
                | _xor(  _and(in & 0x4000000u, z),  n  ) <<26u
                | _xor(  _and(in & 0x2000000u, z),  n  ) <<25u
                | _xor(  _and(in & 0x1000000u, z),  n  ) <<24u
                | _xor(  _and(in &  0x800000u, z),  n  ) <<23u
                | _xor(  _and(in &  0x400000u, z),  n  ) <<22u
                | _xor(  _and(in &  0x200000u, z),  n  ) <<21u
                | _xor(  _and(in &  0x100000u, z),  n  ) <<20u
                | _xor(  _and(in &   0x80000u, z),  n  ) <<19u
                | _xor(  _and(in &   0x40000u, z),  n  ) <<18u
                | _xor(  _and(in &   0x20000u, z),  n  ) <<17u
                | _xor(  _and(in &   0x10000u, z),  n  ) <<16u
                | _xor(  _and(in &    0x8000u, z),  n  ) <<15u
                | _xor(  _and(in &    0x4000u, z),  n  ) <<14u
                | _xor(  _and(in &    0x2000u, z),  n  ) <<13u
                | _xor(  _and(in &    0x1000u, z),  n  ) <<12u
                | _xor(  _and(in &     0x800u, z),  n  ) <<11u
                | _xor(  _and(in &     0x400u, z),  n  ) <<10u
                | _xor(  _and(in &     0x200u, z),  n  ) << 9u
                | _xor(  _and(in &     0x100u, z),  n  ) << 8u
                | _xor(  _and(in &      0x80u, z),  n  ) << 7u
                | _xor(  _and(in &      0x40u, z),  n  ) << 6u
                | _xor(  _and(in &      0x20u, z),  n  ) << 5u
                | _xor(  _and(in &      0x10u, z),  n  ) << 4u
                | _xor(  _and(in &       0x8u, z),  n  ) << 3u
                | _xor(  _and(in &       0x4u, z),  n  ) << 2u
                | _xor(  _and(in &       0x2u, z),  n  ) << 1u
                | _xor(  _and(in &       0x1u, z),  n  ) << 0u
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


    inline Bus32 _zero_if32_v2(Bus32 in, bool z) { return _mux32(in, 0, z); }
    inline Bus32 _neg_if32_v2(Bus32 in, bool n) { return _mux32(in, _not32(in), n); }
    inline Bus32 _prepare32_v2(Bus32 in, bool z, bool n) { return _neg_if32_v2(_zero_if32_v2(in, z), n); }

    std::tuple<Bus32,bool,bool> _alu_v2(Bus32 x, Bus32 y,
                                        bool zx, bool nx, bool zy, bool ny, bool f, bool no)
    {
        x = _prepare32_v2(x, zx, nx);
        y = _prepare32_v2(y, zy, ny);
        Bus32 out = _mux32(_and32(x, y), _add32(x, y), f);
        out = _neg_if32_v2(out, no);

        bool zr = _is_zero32(out);
        bool ng = out&0x80'00'00'00;
        return std::tuple<Bus32,bool,bool>{out, zr, ng};
    }
}

#endif //NANDCOMPUTER_ALU_HPP
