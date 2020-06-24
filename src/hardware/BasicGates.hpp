#ifndef NANDCOMPUTER_BASICGATES_HPP
#define NANDCOMPUTER_BASICGATES_HPP

#include <array>
#include "Hardware.hpp"

namespace Hardware::BasicGates
{
    ///1 bit
                   bool _nand(bool a,  bool b);

                   bool _not (bool in);
                   bool _and (bool a,  bool b);
                   bool _or  (bool a,  bool b);

                   bool _xor (bool a,  bool b);

                   bool _mux (bool a,  bool b,   bool sel);
    std::array<bool, 2> _dmux(bool in, bool sel);



    ///32 bit
                  Bus32 _not32(Bus32 in);
                  Bus32 _and32(Bus32 a,  Bus32 b);
                  Bus32 _or32 (Bus32 a,  Bus32 b);

                  Bus32 _mux32(Bus32 a,  Bus32 b, bool sel);



    ///multi-way
                   bool _and8way  (Bus8 in);
                   bool _or8way   (Bus8 in);

                  Bus32 _mux4way32(Bus32 a, Bus32 b, Bus32 c, Bus32 d,
                                   bool sel0, bool sel1);
                  Bus32 _mux8way32(Bus32 a, Bus32 b, Bus32 c, Bus32 d,
                                   Bus32 e, Bus32 f, Bus32 g, Bus32 h,
                                   bool sel0, bool sel1, bool sel2);
    std::array<bool, 4> _dmux4way (bool in, bool sel0, bool sel1);
    std::array<bool, 8> _dmux8way (bool in, bool sel0, bool sel1, bool sel2);
};


/// Inline variants
namespace Hardware::BasicGates
{
    inline bool _nand_inline(bool a, bool b)
    {
        return !(a&b);
    }

    inline bool _not_inline(bool in)
    {
        return _nand_inline(in, in);
    }

    inline bool _and_inline(bool a, bool b)
    {
        return _not_inline(_nand_inline(a, b));
    }

    inline bool _or_inline(bool a, bool b)
    {
        return _nand_inline(_not_inline(a), _not_inline(b));
    }

    inline bool _xor_inline(bool a, bool b)
    {
        return _and_inline(_or_inline(a, b), _nand_inline(a, b));
    }

    inline bool _mux_inline(bool a, bool b, bool sel)
    {
        return _nand_inline(_nand_inline(sel, b), _nand_inline(_not(sel), a));
    }

    inline std::array<bool, 2> _dmux_inline(bool in, bool sel)
    {
        return {
                _and_inline(_not_inline(sel), in),
                _and_inline(            sel , in)
        };
    }

    inline Bus32 _not32_inline(Bus32 in)
    {
        return      _not_inline(  in &0x80000000u  ) <<31u
                  | _not_inline(  in &0x40000000u  ) <<30u
                  | _not_inline(  in &0x20000000u  ) <<29u
                  | _not_inline(  in &0x10000000u  ) <<28u
                  | _not_inline(  in & 0x8000000u  ) <<27u
                  | _not_inline(  in & 0x4000000u  ) <<26u
                  | _not_inline(  in & 0x2000000u  ) <<25u
                  | _not_inline(  in & 0x1000000u  ) <<24u
                  | _not_inline(  in &  0x800000u  ) <<23u
                  | _not_inline(  in &  0x400000u  ) <<22u
                  | _not_inline(  in &  0x200000u  ) <<21u
                  | _not_inline(  in &  0x100000u  ) <<20u
                  | _not_inline(  in &   0x80000u  ) <<19u
                  | _not_inline(  in &   0x40000u  ) <<18u
                  | _not_inline(  in &   0x20000u  ) <<17u
                  | _not_inline(  in &   0x10000u  ) <<16u
                  | _not_inline(  in &    0x8000u  ) <<15u
                  | _not_inline(  in &    0x4000u  ) <<14u
                  | _not_inline(  in &    0x2000u  ) <<13u
                  | _not_inline(  in &    0x1000u  ) <<12u
                  | _not_inline(  in &     0x800u  ) <<11u
                  | _not_inline(  in &     0x400u  ) <<10u
                  | _not_inline(  in &     0x200u  ) << 9u
                  | _not_inline(  in &     0x100u  ) << 8u
                  | _not_inline(  in &      0x80u  ) << 7u
                  | _not_inline(  in &      0x40u  ) << 6u
                  | _not_inline(  in &      0x20u  ) << 5u
                  | _not_inline(  in &      0x10u  ) << 4u
                  | _not_inline(  in &       0x8u  ) << 3u
                  | _not_inline(  in &       0x4u  ) << 2u
                  | _not_inline(  in &       0x2u  ) << 1u
                  | _not_inline(  in &       0x1u  ) << 0u
                ;
    }

    inline Bus32 _and32_inline(Bus32 a, Bus32 b)
    {
        return      _and_inline(  a &0x80000000u,  b &0x80000000u  ) <<31u
                  | _and_inline(  a &0x40000000u,  b &0x40000000u  ) <<30u
                  | _and_inline(  a &0x20000000u,  b &0x20000000u  ) <<29u
                  | _and_inline(  a &0x10000000u,  b &0x10000000u  ) <<28u
                  | _and_inline(  a & 0x8000000u,  b & 0x8000000u  ) <<27u
                  | _and_inline(  a & 0x4000000u,  b & 0x4000000u  ) <<26u
                  | _and_inline(  a & 0x2000000u,  b & 0x2000000u  ) <<25u
                  | _and_inline(  a & 0x1000000u,  b & 0x1000000u  ) <<24u
                  | _and_inline(  a &  0x800000u,  b &  0x800000u  ) <<23u
                  | _and_inline(  a &  0x400000u,  b &  0x400000u  ) <<22u
                  | _and_inline(  a &  0x200000u,  b &  0x200000u  ) <<21u
                  | _and_inline(  a &  0x100000u,  b &  0x100000u  ) <<20u
                  | _and_inline(  a &   0x80000u,  b &   0x80000u  ) <<19u
                  | _and_inline(  a &   0x40000u,  b &   0x40000u  ) <<18u
                  | _and_inline(  a &   0x20000u,  b &   0x20000u  ) <<17u
                  | _and_inline(  a &   0x10000u,  b &   0x10000u  ) <<16u
                  | _and_inline(  a &    0x8000u,  b &    0x8000u  ) <<15u
                  | _and_inline(  a &    0x4000u,  b &    0x4000u  ) <<14u
                  | _and_inline(  a &    0x2000u,  b &    0x2000u  ) <<13u
                  | _and_inline(  a &    0x1000u,  b &    0x1000u  ) <<12u
                  | _and_inline(  a &     0x800u,  b &     0x800u  ) <<11u
                  | _and_inline(  a &     0x400u,  b &     0x400u  ) <<10u
                  | _and_inline(  a &     0x200u,  b &     0x200u  ) << 9u
                  | _and_inline(  a &     0x100u,  b &     0x100u  ) << 8u
                  | _and_inline(  a &      0x80u,  b &      0x80u  ) << 7u
                  | _and_inline(  a &      0x40u,  b &      0x40u  ) << 6u
                  | _and_inline(  a &      0x20u,  b &      0x20u  ) << 5u
                  | _and_inline(  a &      0x10u,  b &      0x10u  ) << 4u
                  | _and_inline(  a &       0x8u,  b &       0x8u  ) << 3u
                  | _and_inline(  a &       0x4u,  b &       0x4u  ) << 2u
                  | _and_inline(  a &       0x2u,  b &       0x2u  ) << 1u
                  | _and_inline(  a &       0x1u,  b &       0x1u  ) << 0u
                ;
    }

    inline Bus32 _or32_inline(Bus32 a, Bus32 b)
    {
        return      _or_inline(  a &0x80000000u,  b &0x80000000u  ) <<31u
                  | _or_inline(  a &0x40000000u,  b &0x40000000u  ) <<30u
                  | _or_inline(  a &0x20000000u,  b &0x20000000u  ) <<29u
                  | _or_inline(  a &0x10000000u,  b &0x10000000u  ) <<28u
                  | _or_inline(  a & 0x8000000u,  b & 0x8000000u  ) <<27u
                  | _or_inline(  a & 0x4000000u,  b & 0x4000000u  ) <<26u
                  | _or_inline(  a & 0x2000000u,  b & 0x2000000u  ) <<25u
                  | _or_inline(  a & 0x1000000u,  b & 0x1000000u  ) <<24u
                  | _or_inline(  a &  0x800000u,  b &  0x800000u  ) <<23u
                  | _or_inline(  a &  0x400000u,  b &  0x400000u  ) <<22u
                  | _or_inline(  a &  0x200000u,  b &  0x200000u  ) <<21u
                  | _or_inline(  a &  0x100000u,  b &  0x100000u  ) <<20u
                  | _or_inline(  a &   0x80000u,  b &   0x80000u  ) <<19u
                  | _or_inline(  a &   0x40000u,  b &   0x40000u  ) <<18u
                  | _or_inline(  a &   0x20000u,  b &   0x20000u  ) <<17u
                  | _or_inline(  a &   0x10000u,  b &   0x10000u  ) <<16u
                  | _or_inline(  a &    0x8000u,  b &    0x8000u  ) <<15u
                  | _or_inline(  a &    0x4000u,  b &    0x4000u  ) <<14u
                  | _or_inline(  a &    0x2000u,  b &    0x2000u  ) <<13u
                  | _or_inline(  a &    0x1000u,  b &    0x1000u  ) <<12u
                  | _or_inline(  a &     0x800u,  b &     0x800u  ) <<11u
                  | _or_inline(  a &     0x400u,  b &     0x400u  ) <<10u
                  | _or_inline(  a &     0x200u,  b &     0x200u  ) << 9u
                  | _or_inline(  a &     0x100u,  b &     0x100u  ) << 8u
                  | _or_inline(  a &      0x80u,  b &      0x80u  ) << 7u
                  | _or_inline(  a &      0x40u,  b &      0x40u  ) << 6u
                  | _or_inline(  a &      0x20u,  b &      0x20u  ) << 5u
                  | _or_inline(  a &      0x10u,  b &      0x10u  ) << 4u
                  | _or_inline(  a &       0x8u,  b &       0x8u  ) << 3u
                  | _or_inline(  a &       0x4u,  b &       0x4u  ) << 2u
                  | _or_inline(  a &       0x2u,  b &       0x2u  ) << 1u
                  | _or_inline(  a &       0x1u,  b &       0x1u  ) << 0u
                ;
    }

    inline Bus32 _mux32_inline(Bus32 a, Bus32 b, bool sel)
    {
        return      _mux_inline(  a &0x80000000u,  b &0x80000000u,  sel  ) <<31u
                  | _mux_inline(  a &0x40000000u,  b &0x40000000u,  sel  ) <<30u
                  | _mux_inline(  a &0x20000000u,  b &0x20000000u,  sel  ) <<29u
                  | _mux_inline(  a &0x10000000u,  b &0x10000000u,  sel  ) <<28u
                  | _mux_inline(  a & 0x8000000u,  b & 0x8000000u,  sel  ) <<27u
                  | _mux_inline(  a & 0x4000000u,  b & 0x4000000u,  sel  ) <<26u
                  | _mux_inline(  a & 0x2000000u,  b & 0x2000000u,  sel  ) <<25u
                  | _mux_inline(  a & 0x1000000u,  b & 0x1000000u,  sel  ) <<24u
                  | _mux_inline(  a &  0x800000u,  b &  0x800000u,  sel  ) <<23u
                  | _mux_inline(  a &  0x400000u,  b &  0x400000u,  sel  ) <<22u
                  | _mux_inline(  a &  0x200000u,  b &  0x200000u,  sel  ) <<21u
                  | _mux_inline(  a &  0x100000u,  b &  0x100000u,  sel  ) <<20u
                  | _mux_inline(  a &   0x80000u,  b &   0x80000u,  sel  ) <<19u
                  | _mux_inline(  a &   0x40000u,  b &   0x40000u,  sel  ) <<18u
                  | _mux_inline(  a &   0x20000u,  b &   0x20000u,  sel  ) <<17u
                  | _mux_inline(  a &   0x10000u,  b &   0x10000u,  sel  ) <<16u
                  | _mux_inline(  a &    0x8000u,  b &    0x8000u,  sel  ) <<15u
                  | _mux_inline(  a &    0x4000u,  b &    0x4000u,  sel  ) <<14u
                  | _mux_inline(  a &    0x2000u,  b &    0x2000u,  sel  ) <<13u
                  | _mux_inline(  a &    0x1000u,  b &    0x1000u,  sel  ) <<12u
                  | _mux_inline(  a &     0x800u,  b &     0x800u,  sel  ) <<11u
                  | _mux_inline(  a &     0x400u,  b &     0x400u,  sel  ) <<10u
                  | _mux_inline(  a &     0x200u,  b &     0x200u,  sel  ) << 9u
                  | _mux_inline(  a &     0x100u,  b &     0x100u,  sel  ) << 8u
                  | _mux_inline(  a &      0x80u,  b &      0x80u,  sel  ) << 7u
                  | _mux_inline(  a &      0x40u,  b &      0x40u,  sel  ) << 6u
                  | _mux_inline(  a &      0x20u,  b &      0x20u,  sel  ) << 5u
                  | _mux_inline(  a &      0x10u,  b &      0x10u,  sel  ) << 4u
                  | _mux_inline(  a &       0x8u,  b &       0x8u,  sel  ) << 3u
                  | _mux_inline(  a &       0x4u,  b &       0x4u,  sel  ) << 2u
                  | _mux_inline(  a &       0x2u,  b &       0x2u,  sel  ) << 1u
                  | _mux_inline(  a &       0x1u,  b &       0x1u,  sel  ) << 0u
                ;
    }

    inline bool _and8way_inline(Bus8 in)
    {
        return  _and_inline(in &0x80u,
                _and_inline(in &0x40u,
                _and_inline(in &0x20u,
                _and_inline(in &0x10u,
                _and_inline(in & 0x8u,
                _and_inline(in & 0x4u,
                _and_inline(in & 0x2u,
                            in & 0x1u )))))));
    }

    inline bool _or8way_inline(Bus8 in)
    {
        return  _or_inline(in &0x80u,
                _or_inline(in &0x40u,
                _or_inline(in &0x20u,
                _or_inline(in &0x10u,
                _or_inline(in & 0x8u,
                _or_inline(in & 0x4u,
                _or_inline(in & 0x2u,
                           in & 0x1u )))))));
    }

    inline Bus32
    _mux4way32_inline(Bus32 a, Bus32 b, Bus32 c, Bus32 d,
               bool sel0, bool sel1)
    {
        return _mux32_inline(_mux32_inline(a,b,sel0), _mux32_inline(c,d,sel0), sel1);
    }

    inline Bus32
    _mux8way32_inline(Bus32 a, Bus32 b, Bus32 c, Bus32 d,
               Bus32 e, Bus32 f, Bus32 g, Bus32 h,
               bool sel0, bool sel1, bool sel2)
    {
        return _mux32_inline(_mux4way32_inline(a,b,c,d,sel0,sel1), _mux4way32_inline(e,f,g,h,sel0,sel1), sel2);
    }

    inline std::array<bool, 4> _dmux4way_inline(bool in, bool sel0, bool sel1)
    {
        auto [v0, v1] = _dmux_inline(in, sel0);
        return {
                _mux_inline(v0, 0, sel1),
                _mux_inline(v1, 0, sel1),
                _mux_inline(0, v0, sel1),
                _mux_inline(0, v1, sel1)
        };
    }

    inline std::array<bool, 8> _dmux8way_inline(bool in, bool sel0, bool sel1, bool sel2)
    {
        auto [v0, v1, v2, v3] = _dmux4way_inline(in, sel0, sel1);
        return {
                _mux_inline(v0, 0, sel2),
                _mux_inline(v1, 0, sel2),
                _mux_inline(v2, 0, sel2),
                _mux_inline(v3, 0, sel2),
                _mux_inline(0, v0, sel2),
                _mux_inline(0, v1, sel2),
                _mux_inline(0, v2, sel2),
                _mux_inline(0, v3, sel2)
        };
    }
};

#endif //NANDCOMPUTER_BASICGATES_HPP
