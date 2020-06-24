#include "BasicGatesStandards.hpp"
#include "src/hardware/BasicGates.hpp"
#include "src/hardware/BasicGates.cpp"

TEST(BasicGatesTestSuite, Nand)             { Standards::_nand      (Hardware::BasicGates::_nand); }
TEST(BasicGatesTestSuite, NandInline)       { Standards::_nand      (Hardware::BasicGates::_nand_inline); }

TEST(BasicGatesTestSuite, Not)              { Standards::_not       (Hardware::BasicGates::_not); }
TEST(BasicGatesTestSuite, NotInline)        { Standards::_not       (Hardware::BasicGates::_not_inline); }

TEST(BasicGatesTestSuite, And)              { Standards::_and       (Hardware::BasicGates::_and); }
TEST(BasicGatesTestSuite, AndInline)        { Standards::_and       (Hardware::BasicGates::_and_inline); }

TEST(BasicGatesTestSuite, Or)               { Standards::_or        (Hardware::BasicGates::_or); }
TEST(BasicGatesTestSuite, OrInline)         { Standards::_or        (Hardware::BasicGates::_or_inline); }

TEST(BasicGatesTestSuite, Xor)              { Standards::_xor       (Hardware::BasicGates::_xor); }
TEST(BasicGatesTestSuite, XorInline)        { Standards::_xor       (Hardware::BasicGates::_xor_inline); }

TEST(BasicGatesTestSuite, Mux)              { Standards::_mux       (Hardware::BasicGates::_mux); }
TEST(BasicGatesTestSuite, MuxInline)        { Standards::_mux       (Hardware::BasicGates::_mux_inline); }

TEST(BasicGatesTestSuite, Dmux)             { Standards::_dmux      (Hardware::BasicGates::_dmux); }
TEST(BasicGatesTestSuite, DmuxInline)       { Standards::_dmux      (Hardware::BasicGates::_dmux_inline); }

TEST(BasicGatesTestSuite, Dmux4way)         { Standards::_dmux4way  (Hardware::BasicGates::_dmux4way); }
TEST(BasicGatesTestSuite, Dmux4wayInline)   { Standards::_dmux4way  (Hardware::BasicGates::_dmux4way_inline); }

TEST(BasicGatesTestSuite, Dmux8way)         { Standards::_dmux8way  (Hardware::BasicGates::_dmux8way); }
TEST(BasicGatesTestSuite, Dmux8wayInline)   { Standards::_dmux8way  (Hardware::BasicGates::_dmux8way_inline); }






const int THOROUGHNESS = 1'000'000;

#include <random>
std::mt19937 rng = std::mt19937(std::random_device()());
std::uniform_int_distribution<Hardware::Bus32> uniformBus32Distribution;
std::uniform_int_distribution<Hardware::Bus8>  uniformBus8Distribution;
Hardware::Bus32 generateBus32() { return uniformBus32Distribution(rng); }
Hardware::Bus8  generateBus8()  { return uniformBus8Distribution(rng); }

TEST(BasicGatesTestSuite, Not32)            { for ( int i = THOROUGHNESS; i--; Standards::_not32    (Hardware::BasicGates::_not32,              generateBus32()) ); }
TEST(BasicGatesTestSuite, Not32Inline)      { for ( int i = THOROUGHNESS; i--; Standards::_not32    (Hardware::BasicGates::_not32_inline,       generateBus32()) ); }
                                                                                                                                                
TEST(BasicGatesTestSuite, And32)            { for ( int i = THOROUGHNESS; i--; Standards::_and32    (Hardware::BasicGates::_and32,              generateBus32(), generateBus32()) ); }
TEST(BasicGatesTestSuite, And32Inline)      { for ( int i = THOROUGHNESS; i--; Standards::_and32    (Hardware::BasicGates::_and32_inline,       generateBus32(), generateBus32()) ); }
                                                                                                                                                
TEST(BasicGatesTestSuite, Or32)             { for ( int i = THOROUGHNESS; i--; Standards::_or32     (Hardware::BasicGates::_or32,               generateBus32(), generateBus32()) ); }
TEST(BasicGatesTestSuite, Or32Inline)       { for ( int i = THOROUGHNESS; i--; Standards::_or32     (Hardware::BasicGates::_or32_inline,        generateBus32(), generateBus32()) ); }
                                                                                                                                                
TEST(BasicGatesTestSuite, Mux32)            { for (int i = THOROUGHNESS; i--; Standards::_mux32     (Hardware::BasicGates::_mux32,              generateBus32(), generateBus32()) ); }
TEST(BasicGatesTestSuite, Mux32Inline)      { for (int i = THOROUGHNESS; i--; Standards::_mux32     (Hardware::BasicGates::_mux32_inline,       generateBus32(), generateBus32()) ); }
                                                                                                                                                
TEST(BasicGatesTestSuite, And8way)          { for (int i = THOROUGHNESS; i--; Standards::_and8way   (Hardware::BasicGates::_and8way,            generateBus8()) ); }
TEST(BasicGatesTestSuite, And8wayInline)    { for (int i = THOROUGHNESS; i--; Standards::_and8way   (Hardware::BasicGates::_and8way_inline,     generateBus8()) ); }
                                                                                                                                                
TEST(BasicGatesTestSuite, Or8way)           { for (int i = THOROUGHNESS; i--; Standards::_or8way    (Hardware::BasicGates::_or8way,             generateBus8()) ); }
TEST(BasicGatesTestSuite, Or8wayInline)     { for (int i = THOROUGHNESS; i--; Standards::_or8way    (Hardware::BasicGates::_or8way_inline,      generateBus8()) ); }

TEST(BasicGatesTestSuite, Mux4way32)        { for (int i = THOROUGHNESS; i--; Standards::_mux4way32 (Hardware::BasicGates::_mux4way32,          generateBus32(), generateBus32(), generateBus32(), generateBus32()) ); }
TEST(BasicGatesTestSuite, Mux4way32Inline)  { for (int i = THOROUGHNESS; i--; Standards::_mux4way32 (Hardware::BasicGates::_mux4way32_inline,   generateBus32(), generateBus32(), generateBus32(), generateBus32()) ); }

TEST(BasicGatesTestSuite, Mux8way32)        { for (int i = THOROUGHNESS; i--; Standards::_mux8way32 (Hardware::BasicGates::_mux8way32,          generateBus32(), generateBus32(), generateBus32(), generateBus32(), generateBus32(), generateBus32(), generateBus32(), generateBus32()) ); }
TEST(BasicGatesTestSuite, Mux8way32Inline)  { for (int i = THOROUGHNESS; i--; Standards::_mux8way32 (Hardware::BasicGates::_mux8way32_inline,   generateBus32(), generateBus32(), generateBus32(), generateBus32(), generateBus32(), generateBus32(), generateBus32(), generateBus32()) ); }




