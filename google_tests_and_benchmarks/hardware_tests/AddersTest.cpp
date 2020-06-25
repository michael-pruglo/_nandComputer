#include "AddersStandards.hpp"
#include "src/hardware/Adders.hpp"
#include "src/hardware/Adders.cpp"

TEST(AddersTestSuite, HalfAdder)    { Standards::HardwareStandards::AddersStandards::_half_adder      (Hardware::Adders::_half_adder); }
TEST(AddersTestSuite, FullAdder)    { Standards::HardwareStandards::AddersStandards::_full_adder      (Hardware::Adders::_full_adder); }
TEST(AddersTestSuite, FullAdderv2)  { Standards::HardwareStandards::AddersStandards::_full_adder      (Hardware::Adders::_full_adder_v2); }


#include "InputGenerator.hpp"
const int THOROUGHNESS = 100'000;

TEST(AddersTestSuite, Add32)    { for ( int i = THOROUGHNESS; i--; Standards::HardwareStandards::AddersStandards::_add32        (Hardware::Adders::_add32,          generateBus32(), generateBus32()) ); }
TEST(AddersTestSuite, Inc32)    { for ( int i = THOROUGHNESS; i--; Standards::HardwareStandards::AddersStandards::_inc32        (Hardware::Adders::_inc32,          generateBus32()) ); }
