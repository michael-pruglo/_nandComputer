//
// Created by Michael on 06/10/20.
//

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

#endif //NANDCOMPUTER_BASICGATES_HPP
