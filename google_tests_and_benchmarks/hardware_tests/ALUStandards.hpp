#ifndef NANDCOMPUTER_ALUSTANDARDS_HPP
#define NANDCOMPUTER_ALUSTANDARDS_HPP

#include <gtest/gtest.h>
#include "src/hardware/Hardware.hpp"

#include <bitset>
#include <src/hardware/ALU.hpp>

namespace Standards::HardwareStandards::ALUStandards
{
    typedef std::tuple<Hardware::Bus32,bool,bool> ReturnType;
    typedef ReturnType(*ALUFunc)(Hardware::Bus32,Hardware::Bus32,bool,bool,bool,bool,bool,bool);

    inline bool __ng(Hardware::Bus32 in) { return in&0x80'00'00'00; }

    void _alu(ALUFunc gate, Hardware::Bus32 x, Hardware::Bus32 y)
    {
        EXPECT_EQ(   (gate(x,y,  1, 0,    1, 0,    1, 0)),    (ReturnType{     0,   bool(       1),  bool(    0) })   );
        EXPECT_EQ(   (gate(x,y,  1, 1,    1, 1,    1, 1)),    (ReturnType{     1,   bool(       0),  bool(    0) })   );
        EXPECT_EQ(   (gate(x,y,  1, 1,    1, 0,    1, 0)),    (ReturnType{    -1,   bool(       0),  bool(    1) })   );
        EXPECT_EQ(   (gate(x,y,  0, 0,    1, 1,    0, 0)),    (ReturnType{     x,   bool(    x==0),  __ng(    x) })   );
        EXPECT_EQ(   (gate(x,y,  1, 1,    0, 0,    0, 0)),    (ReturnType{     y,   bool(    y==0),  __ng(    y) })   );
        EXPECT_EQ(   (gate(x,y,  0, 0,    1, 1,    0, 1)),    (ReturnType{    ~x,   bool(   ~x==0),  __ng(   ~x) })   );
        EXPECT_EQ(   (gate(x,y,  1, 1,    0, 0,    0, 1)),    (ReturnType{    ~y,   bool(   ~y==0),  __ng(   ~y) })   );
        EXPECT_EQ(   (gate(x,y,  0, 0,    1, 1,    1, 1)),    (ReturnType{    -x,   bool(   -x==0),  __ng(   -x) })   );
        EXPECT_EQ(   (gate(x,y,  1, 1,    0, 0,    1, 1)),    (ReturnType{    -y,   bool(   -y==0),  __ng(   -y) })   );
        EXPECT_EQ(   (gate(x,y,  0, 1,    1, 1,    1, 1)),    (ReturnType{   x+1,   bool(  x+1==0),  __ng(  x+1) })   );
        EXPECT_EQ(   (gate(x,y,  1, 1,    0, 1,    1, 1)),    (ReturnType{   y+1,   bool(  y+1==0),  __ng(  y+1) })   );
        EXPECT_EQ(   (gate(x,y,  0, 0,    1, 1,    1, 0)),    (ReturnType{   x-1,   bool(  x-1==0),  __ng(  x-1) })   );
        EXPECT_EQ(   (gate(x,y,  1, 1,    0, 0,    1, 0)),    (ReturnType{   y-1,   bool(  y-1==0),  __ng(  y-1) })   );
        EXPECT_EQ(   (gate(x,y,  0, 0,    0, 0,    1, 0)),    (ReturnType{   x+y,   bool(  x+y==0),  __ng(  x+y) })   );
        EXPECT_EQ(   (gate(x,y,  0, 1,    0, 0,    1, 1)),    (ReturnType{   x-y,   bool(  x-y==0),  __ng(  x-y) })   );
        EXPECT_EQ(   (gate(x,y,  0, 0,    0, 1,    1, 1)),    (ReturnType{   y-x,   bool(  y-x==0),  __ng(  y-x) })   );
        EXPECT_EQ(   (gate(x,y,  0, 0,    0, 0,    0, 0)),    (ReturnType{ (x&y),   bool((x&y)==0),  __ng((x&y)) })   );
        EXPECT_EQ(   (gate(x,y,  0, 1,    0, 1,    0, 1)),    (ReturnType{ (x|y),   bool((x|y)==0),  __ng((x|y)) })   );
    }

    void _alu(ALUFunc gate,
              Hardware::Bus32 x, Hardware::Bus32 y,
              bool zx, bool nx, bool zy, bool ny, bool f, bool no)
    {
        auto given = gate(x,y,zx,nx,zy,ny,f,no);
        _alu(gate, x, y);
        if (zx) x = 0;
        if (nx) x = ~x;
        if (zy) y = 0;
        if (ny) y = ~y;
        Hardware::Bus32 res = f ? x+y : x&y;
        if (no) res = ~res;
        EXPECT_EQ(given, (ReturnType{res, res==0, __ng(res)}));
    }
}

#endif //NANDCOMPUTER_ALUSTANDARDS_HPP
