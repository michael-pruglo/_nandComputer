#include "BasicGatesStandards.hpp"
#include "src/hardware/BasicGates.hpp"

TEST(BasicGatesTestSuite, Nand)      { Standards::HardwareStandards::BasicGatesStandards::_nand      (Hardware::BasicGates::_nand); }
TEST(BasicGatesTestSuite, Not)       { Standards::HardwareStandards::BasicGatesStandards::_not       (Hardware::BasicGates::_not); }
TEST(BasicGatesTestSuite, And)       { Standards::HardwareStandards::BasicGatesStandards::_and       (Hardware::BasicGates::_and); }
TEST(BasicGatesTestSuite, Or)        { Standards::HardwareStandards::BasicGatesStandards::_or        (Hardware::BasicGates::_or); }
TEST(BasicGatesTestSuite, Xor)       { Standards::HardwareStandards::BasicGatesStandards::_xor       (Hardware::BasicGates::_xor); }
TEST(BasicGatesTestSuite, Mux)       { Standards::HardwareStandards::BasicGatesStandards::_mux       (Hardware::BasicGates::_mux); }
TEST(BasicGatesTestSuite, Dmux)      { Standards::HardwareStandards::BasicGatesStandards::_dmux      (Hardware::BasicGates::_dmux); }
TEST(BasicGatesTestSuite, Dmux4way)  { Standards::HardwareStandards::BasicGatesStandards::_dmux4way  (Hardware::BasicGates::_dmux4way); }
TEST(BasicGatesTestSuite, Dmux8way)  { Standards::HardwareStandards::BasicGatesStandards::_dmux8way  (Hardware::BasicGates::_dmux8way); }



#include "InputGenerator.hpp"
const int THOROUGHNESS = 100'000;

TEST(BasicGatesTestSuite, Not32)     { for ( int i = THOROUGHNESS; i--; Standards::HardwareStandards::BasicGatesStandards::_not32        (Hardware::BasicGates::_not32,     generateBus32()) ); }
TEST(BasicGatesTestSuite, And32)     { for ( int i = THOROUGHNESS; i--; Standards::HardwareStandards::BasicGatesStandards::_and32        (Hardware::BasicGates::_and32,     generateBus32(), generateBus32()) ); }
TEST(BasicGatesTestSuite, Or32)      { for ( int i = THOROUGHNESS; i--; Standards::HardwareStandards::BasicGatesStandards::_or32         (Hardware::BasicGates::_or32,      generateBus32(), generateBus32()) ); }
TEST(BasicGatesTestSuite, Mux32)     { for ( int i = THOROUGHNESS; i--; Standards::HardwareStandards::BasicGatesStandards::_mux32        (Hardware::BasicGates::_mux32,     generateBus32(), generateBus32()) ); }
TEST(BasicGatesTestSuite, And8way)   { for ( int i = THOROUGHNESS; i--; Standards::HardwareStandards::BasicGatesStandards::_and8way      (Hardware::BasicGates::_and8way,   generateBus8()) ); }
TEST(BasicGatesTestSuite, Or8way)    { for ( int i = THOROUGHNESS; i--; Standards::HardwareStandards::BasicGatesStandards::_or8way       (Hardware::BasicGates::_or8way,    generateBus8()) ); }
TEST(BasicGatesTestSuite, Mux4way32) { for ( int i = THOROUGHNESS; i--; Standards::HardwareStandards::BasicGatesStandards::_mux4way32    (Hardware::BasicGates::_mux4way32, generateBus32(), generateBus32(), generateBus32(), generateBus32()) ); }
TEST(BasicGatesTestSuite, Mux8way32) { for ( int i = THOROUGHNESS; i--; Standards::HardwareStandards::BasicGatesStandards::_mux8way32    (Hardware::BasicGates::_mux8way32, generateBus32(), generateBus32(), generateBus32(), generateBus32(), generateBus32(), generateBus32(), generateBus32(), generateBus32()) ); }