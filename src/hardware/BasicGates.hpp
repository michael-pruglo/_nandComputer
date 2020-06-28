#ifndef NANDCOMPUTER_BASICGATES_HPP
#define NANDCOMPUTER_BASICGATES_HPP

#include <array>
#include "Hardware.hpp"

namespace Hardware::BasicGates
{
    ///1 bit
    inline                bool _nand(bool a,  bool b);

    inline                bool _not (bool in);
    inline                bool _and (bool a,  bool b);
    inline                bool _or  (bool a,  bool b);

    inline                bool _xor (bool a,  bool b);
    inline                bool _xnor (bool a,  bool b);

    inline                bool _mux (bool a,  bool b,   bool sel);
    inline std::array<bool, 2> _dmux(bool in, bool sel);



    ///32 bit
    inline               Bus32 _not32(Bus32 in);
    inline               Bus32 _and32(Bus32 a,  Bus32 b);
    inline               Bus32 _or32 (Bus32 a,  Bus32 b);

    inline               Bus32 _mux32(Bus32 a,  Bus32 b, bool sel);

    inline                bool _is_zero32(Bus32 in);
    inline                bool _is_nzero32(Bus32 in);



    ///multi-way
    inline                bool _nand3way (bool a, bool b, bool c);
    inline                bool _and8way  (Bus8 in);
    inline                bool _or8way   (Bus8 in);

    inline               Bus32 _mux4way32(Bus32 a, Bus32 b, Bus32 c, Bus32 d,
                                          bool sel0, bool sel1);
    inline               Bus32 _mux8way32(Bus32 a, Bus32 b, Bus32 c, Bus32 d,
                                          Bus32 e, Bus32 f, Bus32 g, Bus32 h,
                                          bool sel0, bool sel1, bool sel2);
    inline std::array<bool, 4> _dmux4way (bool in, bool sel0, bool sel1);
    inline std::array<bool, 8> _dmux8way (bool in, bool sel0, bool sel1, bool sel2);
};



///Implementation
namespace Hardware::BasicGates
{
    inline bool _nand(bool a, bool b)
    {
        return !(a & b);
    }

    inline bool _nand_v2(bool a, bool b)
    {
        if (a) return !b; else return true;
    }

    inline bool _nand_v3(bool a, bool b)
    {
        return a ? !b : true;
    }

    inline bool _not(bool in)
    {
        return _nand(in, in);
    }

    inline bool _and(bool a, bool b)
    {
        bool tmp = _nand(a, b);
        return _nand(tmp, tmp);
    }

    inline bool _and_v2(bool a, bool b)
    {
        return _not(_nand(a, b));
    }

    inline bool _or(bool a, bool b)
    {
        return _nand(_nand(a, a), _nand(b, b));
    }

    inline bool _or_v2(bool a, bool b)
    {
        return _nand(_not(a), _not(b));
    }

    inline bool _xor(bool a, bool b)
    {
        bool tmp = _nand(a, b);
        return _nand(_nand(a, tmp), _nand(tmp, b));
    }

    inline bool _xor_v2(bool a, bool b)
    {
        return _and(_or(a, b), _nand(a, b));
    }

    inline bool _xnor(bool a, bool b)
    {
        bool nandab = _nand(a, b);
        bool tmpa = _nand(a, nandab);
        bool tmpb = _nand(b, nandab);
        bool t = _nand(tmpa, tmpb);
        return _nand(t, t);
    }

    inline bool _xnor_v2(bool a, bool b)
    {
        return _not(_xor(a, b));
    }

    inline bool _mux(bool a, bool b, bool sel)
    {
        return _nand(_nand(sel, b), _nand(_nand(sel, sel), a));
    }

    inline bool _mux_v2(bool a, bool b, bool sel)
    {
        return _nand(_nand(sel, b), _nand(_not(sel), a));
    }

    inline std::array<bool, 2> _dmux(bool in, bool sel)
    {
        return {
                _and(_nand(sel, sel), in),
                _and(sel, in)
        };
    }

    inline std::array<bool, 2> _dmux_v2(bool in, bool sel)
    {
        return {
                _and(_not(sel), in),
                _and(sel, in)
        };
    }

    inline Bus32 _not32(Bus32 in)
    {
        return _not(in & 0x80000000u) << 31u
               | _not(in & 0x40000000u) << 30u
               | _not(in & 0x20000000u) << 29u
               | _not(in & 0x10000000u) << 28u
               | _not(in & 0x8000000u) << 27u
               | _not(in & 0x4000000u) << 26u
               | _not(in & 0x2000000u) << 25u
               | _not(in & 0x1000000u) << 24u
               | _not(in & 0x800000u) << 23u
               | _not(in & 0x400000u) << 22u
               | _not(in & 0x200000u) << 21u
               | _not(in & 0x100000u) << 20u
               | _not(in & 0x80000u) << 19u
               | _not(in & 0x40000u) << 18u
               | _not(in & 0x20000u) << 17u
               | _not(in & 0x10000u) << 16u
               | _not(in & 0x8000u) << 15u
               | _not(in & 0x4000u) << 14u
               | _not(in & 0x2000u) << 13u
               | _not(in & 0x1000u) << 12u
               | _not(in & 0x800u) << 11u
               | _not(in & 0x400u) << 10u
               | _not(in & 0x200u) << 9u
               | _not(in & 0x100u) << 8u
               | _not(in & 0x80u) << 7u
               | _not(in & 0x40u) << 6u
               | _not(in & 0x20u) << 5u
               | _not(in & 0x10u) << 4u
               | _not(in & 0x8u) << 3u
               | _not(in & 0x4u) << 2u
               | _not(in & 0x2u) << 1u
               | _not(in & 0x1u) << 0u;
    }

    inline Bus32 _and32(Bus32 a, Bus32 b)
    {
        return _and(a & 0x80000000u, b & 0x80000000u) << 31u
               | _and(a & 0x40000000u, b & 0x40000000u) << 30u
               | _and(a & 0x20000000u, b & 0x20000000u) << 29u
               | _and(a & 0x10000000u, b & 0x10000000u) << 28u
               | _and(a & 0x8000000u, b & 0x8000000u) << 27u
               | _and(a & 0x4000000u, b & 0x4000000u) << 26u
               | _and(a & 0x2000000u, b & 0x2000000u) << 25u
               | _and(a & 0x1000000u, b & 0x1000000u) << 24u
               | _and(a & 0x800000u, b & 0x800000u) << 23u
               | _and(a & 0x400000u, b & 0x400000u) << 22u
               | _and(a & 0x200000u, b & 0x200000u) << 21u
               | _and(a & 0x100000u, b & 0x100000u) << 20u
               | _and(a & 0x80000u, b & 0x80000u) << 19u
               | _and(a & 0x40000u, b & 0x40000u) << 18u
               | _and(a & 0x20000u, b & 0x20000u) << 17u
               | _and(a & 0x10000u, b & 0x10000u) << 16u
               | _and(a & 0x8000u, b & 0x8000u) << 15u
               | _and(a & 0x4000u, b & 0x4000u) << 14u
               | _and(a & 0x2000u, b & 0x2000u) << 13u
               | _and(a & 0x1000u, b & 0x1000u) << 12u
               | _and(a & 0x800u, b & 0x800u) << 11u
               | _and(a & 0x400u, b & 0x400u) << 10u
               | _and(a & 0x200u, b & 0x200u) << 9u
               | _and(a & 0x100u, b & 0x100u) << 8u
               | _and(a & 0x80u, b & 0x80u) << 7u
               | _and(a & 0x40u, b & 0x40u) << 6u
               | _and(a & 0x20u, b & 0x20u) << 5u
               | _and(a & 0x10u, b & 0x10u) << 4u
               | _and(a & 0x8u, b & 0x8u) << 3u
               | _and(a & 0x4u, b & 0x4u) << 2u
               | _and(a & 0x2u, b & 0x2u) << 1u
               | _and(a & 0x1u, b & 0x1u) << 0u;
    }

    inline Bus32 _or32(Bus32 a, Bus32 b)
    {
        return _or(a & 0x80000000u, b & 0x80000000u) << 31u
               | _or(a & 0x40000000u, b & 0x40000000u) << 30u
               | _or(a & 0x20000000u, b & 0x20000000u) << 29u
               | _or(a & 0x10000000u, b & 0x10000000u) << 28u
               | _or(a & 0x8000000u, b & 0x8000000u) << 27u
               | _or(a & 0x4000000u, b & 0x4000000u) << 26u
               | _or(a & 0x2000000u, b & 0x2000000u) << 25u
               | _or(a & 0x1000000u, b & 0x1000000u) << 24u
               | _or(a & 0x800000u, b & 0x800000u) << 23u
               | _or(a & 0x400000u, b & 0x400000u) << 22u
               | _or(a & 0x200000u, b & 0x200000u) << 21u
               | _or(a & 0x100000u, b & 0x100000u) << 20u
               | _or(a & 0x80000u, b & 0x80000u) << 19u
               | _or(a & 0x40000u, b & 0x40000u) << 18u
               | _or(a & 0x20000u, b & 0x20000u) << 17u
               | _or(a & 0x10000u, b & 0x10000u) << 16u
               | _or(a & 0x8000u, b & 0x8000u) << 15u
               | _or(a & 0x4000u, b & 0x4000u) << 14u
               | _or(a & 0x2000u, b & 0x2000u) << 13u
               | _or(a & 0x1000u, b & 0x1000u) << 12u
               | _or(a & 0x800u, b & 0x800u) << 11u
               | _or(a & 0x400u, b & 0x400u) << 10u
               | _or(a & 0x200u, b & 0x200u) << 9u
               | _or(a & 0x100u, b & 0x100u) << 8u
               | _or(a & 0x80u, b & 0x80u) << 7u
               | _or(a & 0x40u, b & 0x40u) << 6u
               | _or(a & 0x20u, b & 0x20u) << 5u
               | _or(a & 0x10u, b & 0x10u) << 4u
               | _or(a & 0x8u, b & 0x8u) << 3u
               | _or(a & 0x4u, b & 0x4u) << 2u
               | _or(a & 0x2u, b & 0x2u) << 1u
               | _or(a & 0x1u, b & 0x1u) << 0u;
    }

    inline Bus32 _mux32(Bus32 a, Bus32 b, bool sel)
    {
        return _mux(a & 0x80000000u, b & 0x80000000u, sel) << 31u
               | _mux(a & 0x40000000u, b & 0x40000000u, sel) << 30u
               | _mux(a & 0x20000000u, b & 0x20000000u, sel) << 29u
               | _mux(a & 0x10000000u, b & 0x10000000u, sel) << 28u
               | _mux(a & 0x8000000u, b & 0x8000000u, sel) << 27u
               | _mux(a & 0x4000000u, b & 0x4000000u, sel) << 26u
               | _mux(a & 0x2000000u, b & 0x2000000u, sel) << 25u
               | _mux(a & 0x1000000u, b & 0x1000000u, sel) << 24u
               | _mux(a & 0x800000u, b & 0x800000u, sel) << 23u
               | _mux(a & 0x400000u, b & 0x400000u, sel) << 22u
               | _mux(a & 0x200000u, b & 0x200000u, sel) << 21u
               | _mux(a & 0x100000u, b & 0x100000u, sel) << 20u
               | _mux(a & 0x80000u, b & 0x80000u, sel) << 19u
               | _mux(a & 0x40000u, b & 0x40000u, sel) << 18u
               | _mux(a & 0x20000u, b & 0x20000u, sel) << 17u
               | _mux(a & 0x10000u, b & 0x10000u, sel) << 16u
               | _mux(a & 0x8000u, b & 0x8000u, sel) << 15u
               | _mux(a & 0x4000u, b & 0x4000u, sel) << 14u
               | _mux(a & 0x2000u, b & 0x2000u, sel) << 13u
               | _mux(a & 0x1000u, b & 0x1000u, sel) << 12u
               | _mux(a & 0x800u, b & 0x800u, sel) << 11u
               | _mux(a & 0x400u, b & 0x400u, sel) << 10u
               | _mux(a & 0x200u, b & 0x200u, sel) << 9u
               | _mux(a & 0x100u, b & 0x100u, sel) << 8u
               | _mux(a & 0x80u, b & 0x80u, sel) << 7u
               | _mux(a & 0x40u, b & 0x40u, sel) << 6u
               | _mux(a & 0x20u, b & 0x20u, sel) << 5u
               | _mux(a & 0x10u, b & 0x10u, sel) << 4u
               | _mux(a & 0x8u, b & 0x8u, sel) << 3u
               | _mux(a & 0x4u, b & 0x4u, sel) << 2u
               | _mux(a & 0x2u, b & 0x2u, sel) << 1u
               | _mux(a & 0x1u, b & 0x1u, sel) << 0u;
    }

    inline bool _is_zero32(Bus32 in)
    {
        return _not(_is_nzero32(in));
    }

    inline bool _is_nzero32(Bus32 in)
    {
        return _or((in & 0x80000000u),
                   _or((in & 0x40000000u),
                       _or((in & 0x20000000u),
                           _or((in & 0x10000000u),
                               _or((in & 0x8000000u),
                                   _or((in & 0x4000000u),
                                       _or((in & 0x2000000u),
                                           _or((in & 0x1000000u),
                                               _or((in & 0x800000u),
                                                   _or((in & 0x400000u),
                                                       _or((in & 0x200000u),
                                                           _or((in & 0x100000u),
                                                               _or((in & 0x80000u),
                                                                   _or((in & 0x40000u),
                                                                       _or((in & 0x20000u),
                                                                           _or((in & 0x10000u),
                                                                               _or((in & 0x8000u),
                                                                                   _or((in & 0x4000u),
                                                                                       _or((in & 0x2000u),
                                                                                           _or((in & 0x1000u),
                                                                                               _or((in & 0x800u),
                                                                                                   _or((in & 0x400u),
                                                                                                       _or((in &
                                                                                                            0x200u),
                                                                                                           _or((in &
                                                                                                                0x100u),
                                                                                                               _or((in &
                                                                                                                    0x80u),
                                                                                                                   _or((in &
                                                                                                                        0x40u),
                                                                                                                       _or((in &
                                                                                                                            0x20u),
                                                                                                                           _or((in &
                                                                                                                                0x10u),
                                                                                                                               _or((in &
                                                                                                                                    0x8u),
                                                                                                                                   _or((in &
                                                                                                                                        0x4u),
                                                                                                                                       _or((in &
                                                                                                                                            0x2u),
                                                                                                                                           (in &
                                                                                                                                            0x1u))))))))))))))))))))))))))))))));
    }

    inline bool _nand3way(bool a, bool b, bool c)
    {
        return !(a&b&c);
    }

    inline bool _and8way(Bus8 in)
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

    inline bool _or8way(Bus8 in)
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

    inline Bus32
    _mux4way32(Bus32 a, Bus32 b, Bus32 c, Bus32 d,
               bool sel0, bool sel1)
    {
        return _mux32(_mux32(a,b,sel0), _mux32(c,d,sel0), sel1);
    }

    inline Bus32
    _mux8way32(Bus32 a, Bus32 b, Bus32 c, Bus32 d,
               Bus32 e, Bus32 f, Bus32 g, Bus32 h,
               bool sel0, bool sel1, bool sel2)
    {
        return _mux32(_mux4way32(a,b,c,d,sel0,sel1), _mux4way32(e,f,g,h,sel0,sel1), sel2);
    }

    inline std::array<bool, 4> _dmux4way(bool in, bool sel0, bool sel1)
    {
        auto [v0, v1] = _dmux(in, sel0);
        return {
                _mux(v0, 0, sel1),
                _mux(v1, 0, sel1),
                _mux(0, v0, sel1),
                _mux(0, v1, sel1)
        };
    }

    inline std::array<bool, 8> _dmux8way(bool in, bool sel0, bool sel1, bool sel2)
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

} //namespace Hardware::BasicGates


#endif //NANDCOMPUTER_BASICGATES_HPP
