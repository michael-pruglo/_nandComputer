#ifndef NANDCOMPUTER_ALUSTANDARDS_HPP
#define NANDCOMPUTER_ALUSTANDARDS_HPP

#include <gtest/gtest.h>
#include "src/hardware/Hardware.hpp"

#include <bitset>
#include <src/hardware/ALU.hpp>

namespace Standards::HardwareStandards::ALUStandards
{
    typedef std::tuple<Hardware::Bus16,bool,bool> ReturnType;
    typedef ReturnType(*ALUFunc)(Hardware::Bus16,Hardware::Bus16,bool,bool,bool,bool,bool,bool);

    inline bool __ng(Hardware::Bus16 in) { return in&0x80'00; }

    void _prepare16(Hardware::Bus16(*gate)(Hardware::Bus16, bool, bool),
                    Hardware::Bus16 in, bool z, bool n)
    {
        Hardware::Bus16 out = z ? 0 : in;
        out = n ? ~out : out;
        EXPECT_EQ( (gate(in, z, n)), out );
    }
    void _neg_if16(Hardware::Bus16(*gate)(Hardware::Bus16, bool),
                   Hardware::Bus16 in, bool n)
    {
        EXPECT_EQ( (gate(in, n)), Hardware::Bus16 (n?~in:in) );
    }

    void _alu(ALUFunc gate, Hardware::Bus16 x, Hardware::Bus16 y)
    {
        EXPECT_EQ(   (gate(x,y,  1, 0,    1, 0,    1, 0)),    (ReturnType{     0,   bool(                        1),  bool(    0) })   );
        EXPECT_EQ(   (gate(x,y,  1, 1,    1, 1,    1, 1)),    (ReturnType{     1,   bool(                        0),  bool(    0) })   );
        EXPECT_EQ(   (gate(x,y,  1, 1,    1, 0,    1, 0)),    (ReturnType{    -1,   bool(                        0),  bool(    1) })   );
        EXPECT_EQ(   (gate(x,y,  0, 0,    1, 1,    0, 0)),    (ReturnType{     x,   bool(Hardware::Bus16(    x)==0),  __ng(    x) })   );
        EXPECT_EQ(   (gate(x,y,  1, 1,    0, 0,    0, 0)),    (ReturnType{     y,   bool(Hardware::Bus16(    y)==0),  __ng(    y) })   );
        EXPECT_EQ(   (gate(x,y,  0, 0,    1, 1,    0, 1)),    (ReturnType{    ~x,   bool(Hardware::Bus16(   ~x)==0),  __ng(   ~x) })   );
        EXPECT_EQ(   (gate(x,y,  1, 1,    0, 0,    0, 1)),    (ReturnType{    ~y,   bool(Hardware::Bus16(   ~y)==0),  __ng(   ~y) })   );
        EXPECT_EQ(   (gate(x,y,  0, 0,    1, 1,    1, 1)),    (ReturnType{    -x,   bool(Hardware::Bus16(   -x)==0),  __ng(   -x) })   );
        EXPECT_EQ(   (gate(x,y,  1, 1,    0, 0,    1, 1)),    (ReturnType{    -y,   bool(Hardware::Bus16(   -y)==0),  __ng(   -y) })   );
        EXPECT_EQ(   (gate(x,y,  0, 1,    1, 1,    1, 1)),    (ReturnType{   x+1,   bool(Hardware::Bus16(  x+1)==0),  __ng(  x+1) })   );
        EXPECT_EQ(   (gate(x,y,  1, 1,    0, 1,    1, 1)),    (ReturnType{   y+1,   bool(Hardware::Bus16(  y+1)==0),  __ng(  y+1) })   );
        EXPECT_EQ(   (gate(x,y,  0, 0,    1, 1,    1, 0)),    (ReturnType{   x-1,   bool(Hardware::Bus16(  x-1)==0),  __ng(  x-1) })   );
        EXPECT_EQ(   (gate(x,y,  1, 1,    0, 0,    1, 0)),    (ReturnType{   y-1,   bool(Hardware::Bus16(  y-1)==0),  __ng(  y-1) })   );
        EXPECT_EQ(   (gate(x,y,  0, 0,    0, 0,    1, 0)),    (ReturnType{   x+y,   bool(Hardware::Bus16(  x+y)==0),  __ng(  x+y) })   );
        EXPECT_EQ(   (gate(x,y,  0, 1,    0, 0,    1, 1)),    (ReturnType{   x-y,   bool(Hardware::Bus16(  x-y)==0),  __ng(  x-y) })   );
        EXPECT_EQ(   (gate(x,y,  0, 0,    0, 1,    1, 1)),    (ReturnType{   y-x,   bool(Hardware::Bus16(  y-x)==0),  __ng(  y-x) })   );
        EXPECT_EQ(   (gate(x,y,  0, 0,    0, 0,    0, 0)),    (ReturnType{ (x&y),   bool(Hardware::Bus16((x&y))==0),  __ng((x&y)) })   );
        EXPECT_EQ(   (gate(x,y,  0, 1,    0, 1,    0, 1)),    (ReturnType{ (x|y),   bool(Hardware::Bus16((x|y))==0),  __ng((x|y)) })   );
    }

    void _alu(ALUFunc gate,
              Hardware::Bus16 x, Hardware::Bus16 y,
              bool zx, bool nx, bool zy, bool ny, bool f, bool no)
    {
        auto given = gate(x,y,zx,nx,zy,ny,f,no);
        _alu(gate, x, y);
        if (zx) x = 0;
        if (nx) x = ~x;
        if (zy) y = 0;
        if (ny) y = ~y;
        Hardware::Bus16 res = f ? x+y : x&y;
        if (no) res = ~res;
        EXPECT_EQ(given, (ReturnType{res, res==0, __ng(res)}));
    }
}

#endif //NANDCOMPUTER_ALUSTANDARDS_HPP
