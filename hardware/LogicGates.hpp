//
// Created by Michael on 06/08/20.
//

#ifndef NANDCOMPUTER_LOGICGATES_HPP
#define NANDCOMPUTER_LOGICGATES_HPP

#include <array>

class LogicGates
{
public:
    static inline bool _nand(bool a, bool b);

    ///1 bit
    static bool _not(bool a);
    static bool _and(bool a, bool b);
    static bool _or(bool a, bool b);

    static bool _xor(bool a, bool b);

    static bool _mux(bool a, bool b, bool sel);
    static std::array<bool, 2> _dmux(bool in, bool sel);


    ///32 bit
    static __int32 _not32(__int32 a, __int32 b);
    static __int32 _and32(__int32 a, __int32 b);
    static __int32 _or32(__int32 a, __int32 b);

    static __int32 _mux32(__int32 a, __int32 b, bool sel);




    ///multi-way
    static bool _and8way(__int8 in);
    static bool _or8way(__int8 in);

    static __int32 _mux4way32(__int32 a, __int32 b, __int32 c, __int32 d,
                              bool sel0, bool sel1);
    static __int32 _mux8way32(__int32 a, __int32 b, __int32 c, __int32 d,
                              __int32 e, __int32 f, __int32 g, __int32 h,
                              bool sel0, bool sel2, bool sel3);
    static std::array<bool, 4> _dmux4way(bool in, bool sel0, bool sel1);
    static std::array<bool, 8> _dmux8way(bool in, bool sel0, bool sel1, bool sel2);
};


#endif //NANDCOMPUTER_LOGICGATES_HPP
