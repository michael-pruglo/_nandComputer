#ifndef NANDCOMPUTER_BASICfSSTANDARDS_HPP
#define NANDCOMPUTER_BASICfSSTANDARDS_HPP

#include <gtest/gtest.h>
#include "src/hardware/Hardware.hpp"

namespace Standards::HardwareStandards::BasicGatesStandards
{
    typedef bool(*  UnaryBoolFunc)(bool);
    typedef bool(* BinaryBoolFunc)(bool, bool);
    typedef bool(*TernaryBoolFunc)(bool, bool, bool);

    typedef Hardware::Bus16(*  UnaryBus16Func)(Hardware::Bus16);
    typedef Hardware::Bus16(* BinaryBus16Func)(Hardware::Bus16, Hardware::Bus16);
    typedef Hardware::Bus32(*  UnaryBus32Func)(Hardware::Bus32);
    typedef Hardware::Bus32(* BinaryBus32Func)(Hardware::Bus32, Hardware::Bus32);


    void _nand(BinaryBoolFunc gate)
    {
        EXPECT_EQ(gate(0, 0), 1);
        EXPECT_EQ(gate(0, 1), 1);
        EXPECT_EQ(gate(1, 0), 1);
        EXPECT_EQ(gate(1, 1), 0);
    }
    void _nand3way(TernaryBoolFunc gate)
    {
        EXPECT_EQ(gate(0, 0, 0), 1);
        EXPECT_EQ(gate(0, 1, 0), 1);
        EXPECT_EQ(gate(1, 0, 0), 1);
        EXPECT_EQ(gate(1, 1, 0), 1);
        EXPECT_EQ(gate(0, 0, 1), 1);
        EXPECT_EQ(gate(0, 1, 1), 1);
        EXPECT_EQ(gate(1, 0, 1), 1);
        EXPECT_EQ(gate(1, 1, 1), 0);
    }

    void _not(UnaryBoolFunc gate)
    {
        EXPECT_EQ(gate(0), 1);
        EXPECT_EQ(gate(1), 0);
    }

    void _and(BinaryBoolFunc gate)
    {
        EXPECT_EQ(gate(0, 0), 0);
        EXPECT_EQ(gate(0, 1), 0);
        EXPECT_EQ(gate(1, 0), 0);
        EXPECT_EQ(gate(1, 1), 1);
    }

    void _or(BinaryBoolFunc gate)
    {
        EXPECT_EQ(gate(0, 0), 0);
        EXPECT_EQ(gate(0, 1), 1);
        EXPECT_EQ(gate(1, 0), 1);
        EXPECT_EQ(gate(1, 1), 1);
    }

    void _xor(BinaryBoolFunc gate)
    {
        EXPECT_EQ(gate(0, 0), 0);
        EXPECT_EQ(gate(0, 1), 1);
        EXPECT_EQ(gate(1, 0), 1);
        EXPECT_EQ(gate(1, 1), 0);
    }

    void _xnor(BinaryBoolFunc gate)
    {
        EXPECT_EQ(gate(0, 0), 1);
        EXPECT_EQ(gate(0, 1), 0);
        EXPECT_EQ(gate(1, 0), 0);
        EXPECT_EQ(gate(1, 1), 1);
    }

    void _mux(TernaryBoolFunc gate)
    {
        EXPECT_EQ(gate(0, 0, 0), 0);
        EXPECT_EQ(gate(0, 1, 0), 0);
        EXPECT_EQ(gate(1, 0, 0), 1);
        EXPECT_EQ(gate(1, 1, 0), 1);
        EXPECT_EQ(gate(0, 0, 1), 0);
        EXPECT_EQ(gate(0, 1, 1), 1);
        EXPECT_EQ(gate(1, 0, 1), 0);
        EXPECT_EQ(gate(1, 1, 1), 1);
    }

    void _dmux(std::array<bool, 2>(*gate)(bool,bool))
    {
        EXPECT_EQ((gate(0, 0)), (std::array<bool, 2>{0, 0}));
        EXPECT_EQ((gate(0, 1)), (std::array<bool, 2>{0, 0}));
        EXPECT_EQ((gate(1, 0)), (std::array<bool, 2>{1, 0}));
        EXPECT_EQ((gate(1, 1)), (std::array<bool, 2>{0, 1}));
    }


    void _not16(UnaryBus16Func gate, Hardware::Bus16 in)
    {
        EXPECT_EQ(gate(in), Hardware::Bus16(~in));
    }

    void _and16(BinaryBus16Func gate, Hardware::Bus16 a, Hardware::Bus16 b)
    {
        EXPECT_EQ(gate(a, b), (a&b));
    }

    void _or16(BinaryBus16Func gate, Hardware::Bus16 a, Hardware::Bus16 b)
    {
        EXPECT_EQ(gate(a, b), (a|b));
    }

    void _mux16(Hardware::Bus16(*gate)(Hardware::Bus16,Hardware::Bus16,bool),
                Hardware::Bus16 a,
                Hardware::Bus16 b)
    {
        EXPECT_EQ(gate(a, b, 0),   a);
        EXPECT_EQ(gate(a, b, 1),   b);
    }

    void _is_zero16(bool(*gate)(Hardware::Bus16), Hardware::Bus16 in)
    {
        EXPECT_EQ(gate(in), (in==0));
    }

    void _is_nzero16(bool(*gate)(Hardware::Bus16), Hardware::Bus16 in)
    {
        EXPECT_EQ(gate(in), (in!=0));
    }
    

    void _not32(UnaryBus32Func gate, Hardware::Bus32 in)
    {
        EXPECT_EQ(gate(in), ~in);
    }

    void _and32(BinaryBus32Func gate, Hardware::Bus32 a, Hardware::Bus32 b)
    {
        EXPECT_EQ(gate(a, b), (a&b));
    }

    void _or32(BinaryBus32Func gate, Hardware::Bus32 a, Hardware::Bus32 b)
    {
        EXPECT_EQ(gate(a, b), (a|b));
    }

    void _mux32(Hardware::Bus32(*gate)(Hardware::Bus32,Hardware::Bus32,bool),
                Hardware::Bus32 a,
                Hardware::Bus32 b)
    {
        EXPECT_EQ(gate(a, b, 0),   a);
        EXPECT_EQ(gate(a, b, 1),   b);
    }

    void _is_zero32(bool(*gate)(Hardware::Bus32), Hardware::Bus32 in)
    {
        EXPECT_EQ(gate(in), (in==0));
    }

    void _is_nzero32(bool(*gate)(Hardware::Bus32), Hardware::Bus32 in)
    {
        EXPECT_EQ(gate(in), (in!=0));
    }

    void _and8way(bool(*gate)(Hardware::Bus8), Hardware::Bus8 in)
    {
        EXPECT_EQ(gate(in), (__builtin_popcount(in)==8));
    }

    void _or8way(bool(*gate)(Hardware::Bus8), Hardware::Bus8 in)
    {
        EXPECT_EQ(gate(in), (__builtin_popcount(in)>0));
    }

    void _mux4way16(Hardware::Bus16(*gate)(Hardware::Bus16,Hardware::Bus16,Hardware::Bus16,Hardware::Bus16,bool,bool),
                    Hardware::Bus16 a,
                    Hardware::Bus16 b,
                    Hardware::Bus16 c,
                    Hardware::Bus16 d)
    {
        EXPECT_EQ(gate(a,b,c,d, 0, 0),   a);
        EXPECT_EQ(gate(a,b,c,d, 0, 1),   c);
        EXPECT_EQ(gate(a,b,c,d, 1, 0),   b);
        EXPECT_EQ(gate(a,b,c,d, 1, 1),   d);
    }

    void _mux8way16(Hardware::Bus16(*gate)(Hardware::Bus16,Hardware::Bus16,Hardware::Bus16,Hardware::Bus16,
                                           Hardware::Bus16,Hardware::Bus16,Hardware::Bus16,Hardware::Bus16,
                                           bool,bool,bool),
                    Hardware::Bus16 a,
                    Hardware::Bus16 b,
                    Hardware::Bus16 c,
                    Hardware::Bus16 d,
                    Hardware::Bus16 e,
                    Hardware::Bus16 f,
                    Hardware::Bus16 g,
                    Hardware::Bus16 h)
    {
        EXPECT_EQ(gate(a,b,c,d,e,f,g,h, 0, 0, 0),   a);
        EXPECT_EQ(gate(a,b,c,d,e,f,g,h, 0, 0, 1),   e);
        EXPECT_EQ(gate(a,b,c,d,e,f,g,h, 0, 1, 0),   c);
        EXPECT_EQ(gate(a,b,c,d,e,f,g,h, 0, 1, 1),   g);
        EXPECT_EQ(gate(a,b,c,d,e,f,g,h, 1, 0, 0),   b);
        EXPECT_EQ(gate(a,b,c,d,e,f,g,h, 1, 0, 1),   f);
        EXPECT_EQ(gate(a,b,c,d,e,f,g,h, 1, 1, 0),   d);
        EXPECT_EQ(gate(a,b,c,d,e,f,g,h, 1, 1, 1),   h);
    }


    void _mux4way32(Hardware::Bus32(*gate)(Hardware::Bus32,Hardware::Bus32,Hardware::Bus32,Hardware::Bus32,bool,bool),
                    Hardware::Bus32 a,
                    Hardware::Bus32 b,
                    Hardware::Bus32 c,
                    Hardware::Bus32 d)
    {
        EXPECT_EQ(gate(a,b,c,d, 0, 0),   a);
        EXPECT_EQ(gate(a,b,c,d, 0, 1),   c);
        EXPECT_EQ(gate(a,b,c,d, 1, 0),   b);
        EXPECT_EQ(gate(a,b,c,d, 1, 1),   d);
    }

    void _mux8way32(Hardware::Bus32(*gate)(Hardware::Bus32,Hardware::Bus32,Hardware::Bus32,Hardware::Bus32,
                                           Hardware::Bus32,Hardware::Bus32,Hardware::Bus32,Hardware::Bus32,
                                           bool,bool,bool),
                    Hardware::Bus32 a,
                    Hardware::Bus32 b,
                    Hardware::Bus32 c,
                    Hardware::Bus32 d,
                    Hardware::Bus32 e,
                    Hardware::Bus32 f,
                    Hardware::Bus32 g,
                    Hardware::Bus32 h)
    {
        EXPECT_EQ(gate(a,b,c,d,e,f,g,h, 0, 0, 0),   a);
        EXPECT_EQ(gate(a,b,c,d,e,f,g,h, 0, 0, 1),   e);
        EXPECT_EQ(gate(a,b,c,d,e,f,g,h, 0, 1, 0),   c);
        EXPECT_EQ(gate(a,b,c,d,e,f,g,h, 0, 1, 1),   g);
        EXPECT_EQ(gate(a,b,c,d,e,f,g,h, 1, 0, 0),   b);
        EXPECT_EQ(gate(a,b,c,d,e,f,g,h, 1, 0, 1),   f);
        EXPECT_EQ(gate(a,b,c,d,e,f,g,h, 1, 1, 0),   d);
        EXPECT_EQ(gate(a,b,c,d,e,f,g,h, 1, 1, 1),   h);
    }

    void _dmux4way(std::array<bool, 4>(*gate)(bool,bool,bool))
    {
        EXPECT_EQ((gate(0, 0, 0)), (std::array<bool, 4>{0, 0, 0, 0}));
        EXPECT_EQ((gate(0, 0, 1)), (std::array<bool, 4>{0, 0, 0, 0}));
        EXPECT_EQ((gate(0, 1, 0)), (std::array<bool, 4>{0, 0, 0, 0}));
        EXPECT_EQ((gate(0, 1, 1)), (std::array<bool, 4>{0, 0, 0, 0}));
        EXPECT_EQ((gate(1, 0, 0)), (std::array<bool, 4>{1, 0, 0, 0}));
        EXPECT_EQ((gate(1, 0, 1)), (std::array<bool, 4>{0, 0, 1, 0}));
        EXPECT_EQ((gate(1, 1, 0)), (std::array<bool, 4>{0, 1, 0, 0}));
        EXPECT_EQ((gate(1, 1, 1)), (std::array<bool, 4>{0, 0, 0, 1}));
    }

    void _dmux8way(std::array<bool, 8>(*gate)(bool,bool,bool,bool))
    {
        EXPECT_EQ((gate(0, 0, 0, 0)), (std::array<bool, 8>{0, 0, 0, 0, 0, 0, 0, 0}));
        EXPECT_EQ((gate(0, 0, 0, 1)), (std::array<bool, 8>{0, 0, 0, 0, 0, 0, 0, 0}));
        EXPECT_EQ((gate(0, 0, 1, 0)), (std::array<bool, 8>{0, 0, 0, 0, 0, 0, 0, 0}));
        EXPECT_EQ((gate(0, 0, 1, 1)), (std::array<bool, 8>{0, 0, 0, 0, 0, 0, 0, 0}));
        EXPECT_EQ((gate(0, 1, 0, 0)), (std::array<bool, 8>{0, 0, 0, 0, 0, 0, 0, 0}));
        EXPECT_EQ((gate(0, 1, 0, 1)), (std::array<bool, 8>{0, 0, 0, 0, 0, 0, 0, 0}));
        EXPECT_EQ((gate(0, 1, 1, 0)), (std::array<bool, 8>{0, 0, 0, 0, 0, 0, 0, 0}));
        EXPECT_EQ((gate(0, 1, 1, 1)), (std::array<bool, 8>{0, 0, 0, 0, 0, 0, 0, 0}));
        EXPECT_EQ((gate(1, 0, 0, 0)), (std::array<bool, 8>{1, 0, 0, 0, 0, 0, 0, 0}));
        EXPECT_EQ((gate(1, 0, 0, 1)), (std::array<bool, 8>{0, 0, 0, 0, 1, 0, 0, 0}));
        EXPECT_EQ((gate(1, 0, 1, 0)), (std::array<bool, 8>{0, 0, 1, 0, 0, 0, 0, 0}));
        EXPECT_EQ((gate(1, 0, 1, 1)), (std::array<bool, 8>{0, 0, 0, 0, 0, 0, 1, 0}));
        EXPECT_EQ((gate(1, 1, 0, 0)), (std::array<bool, 8>{0, 1, 0, 0, 0, 0, 0, 0}));
        EXPECT_EQ((gate(1, 1, 0, 1)), (std::array<bool, 8>{0, 0, 0, 0, 0, 1, 0, 0}));
        EXPECT_EQ((gate(1, 1, 1, 0)), (std::array<bool, 8>{0, 0, 0, 1, 0, 0, 0, 0}));
        EXPECT_EQ((gate(1, 1, 1, 1)), (std::array<bool, 8>{0, 0, 0, 0, 0, 0, 0, 1}));
    }

}

#endif //NANDCOMPUTER_BASICfSSTANDARDS_HPP
