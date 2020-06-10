//
// Created by Michael on 06/08/20.
//

#ifndef NANDCOMPUTER_LOGICGATES_HPP
#define NANDCOMPUTER_LOGICGATES_HPP

#include <array>
#include <bitset>

class LogicGates
{
public:
    typedef uint8_t Bus8;
    typedef uint32_t Bus32;
public:
    static inline bool _nand(bool a, bool b);

    ///1 bit
    static bool _not(bool in);
    static bool _and(bool a, bool b);
    static bool _or(bool a, bool b);

    static bool _xor(bool a, bool b);

    static bool _mux(bool a, bool b, bool sel);
    static std::array<bool, 2> _dmux(bool in, bool sel);


    ///32 bit
    static Bus32 _not32(Bus32 in);
    static Bus32 _and32(Bus32 a, Bus32 b);
    static Bus32 _or32(Bus32 a, Bus32 b);

    static Bus32 _mux32(Bus32 a, Bus32 b, bool sel);




    ///multi-way
    static bool _and8way(Bus8 in);
    static bool _or8way(Bus8 in);

    static Bus32 _mux4way32(Bus32 a, Bus32 b, Bus32 c, Bus32 d,
                            bool sel0, bool sel1);
    static Bus32 _mux8way32(Bus32 a, Bus32 b, Bus32 c, Bus32 d,
                            Bus32 e, Bus32 f, Bus32 g, Bus32 h,
                            bool sel0, bool sel1, bool sel2);
    static std::array<bool, 4> _dmux4way(bool in, bool sel0, bool sel1);
    static std::array<bool, 8> _dmux8way(bool in, bool sel0, bool sel1, bool sel2);

private:
    static inline void setbit(Bus32& n, unsigned i, bool val) { n = n & ~(1u<<i) | val << i; }
    static inline void setbit(Bus8& n, unsigned i, bool val) { n = n & ~(1u<<i) | val << i; }
    static inline bool getbit(Bus32& n, unsigned i) { return n>>i&1u; }
    static inline bool getbit(Bus8& n, unsigned i) { return n>>i&1u; }
};


#endif //NANDCOMPUTER_LOGICGATES_HPP
