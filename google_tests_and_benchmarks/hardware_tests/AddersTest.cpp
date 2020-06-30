#include "HardwareTestManager.hpp"
#include "AddersStandards.hpp"
#include "src/hardware/Adders.hpp"

ADDER_TRUTHTABLE_TEST  (HalfAdder,   _half_adder)
ADDER_TRUTHTABLE_TEST_V(HalfAdderv2, _half_adder, _half_adder_v2)
ADDER_TRUTHTABLE_TEST  (FullAdder,   _full_adder)
ADDER_TRUTHTABLE_TEST_V(FullAdderv2, _full_adder, _full_adder_v2)
#undef ADDER_TRUTHTABLE_TEST
#undef ADDER_TRUTHTABLE_TEST_V


#include "InputGenerator.hpp"

ADDER_PARTIAL_TEST(Add16,             _add16, 180'000*COEF,   generateBus16(),  generateBus16() )
ADDER_PARTIAL_TEST(Add16MinusOne,     _add16, 1,              0xFF'FFu,   1 )
ADDER_PARTIAL_TEST(Add16MinusOne2,    _add16, 1,              0xFF'FFu,   0 )
ADDER_PARTIAL_TEST(Add16MinusTwo,     _add16, 1,              0xFF'FEu,   2 )
ADDER_PARTIAL_TEST(Add16Loop,         _add16, 1,              0xFF'F0u,   24 )
ADDER_PARTIAL_TEST(Add16SuperMinus,   _add16, 1,              0xFF'FFu,   0xFF'FFu )
ADDER_PARTIAL_TEST(Add16Zero,         _add16, 1,              0,                0 )

ADDER_PARTIAL_TEST(Inc16,             _inc16, 600'000*COEF,   generateBus16() )
ADDER_PARTIAL_TEST(Inc16MinusOne,     _inc16, 1,              0xFF'FFu )
ADDER_PARTIAL_TEST(Inc16MinusTwo,     _inc16, 1,              0xFF'FEu )
ADDER_PARTIAL_TEST(Inc16Zero,         _inc16, 1,              0 )


ADDER_PARTIAL_TEST(Add32,             _add32, 180'000*COEF,   generateBus32(),  generateBus32() )
ADDER_PARTIAL_TEST(Add32MinusOne,     _add32, 1,              0xFF'FF'FF'FFu,   1 )
ADDER_PARTIAL_TEST(Add32MinusOne2,    _add32, 1,              0xFF'FF'FF'FFu,   0 )
ADDER_PARTIAL_TEST(Add32MinusTwo,     _add32, 1,              0xFF'FF'FF'FEu,   2 )
ADDER_PARTIAL_TEST(Add32Loop,         _add32, 1,              0xFF'FF'FF'F0u,   24 )
ADDER_PARTIAL_TEST(Add32SuperMinus,   _add32, 1,              0xFF'FF'FF'FFu,   0xFF'FF'FF'FFu )
ADDER_PARTIAL_TEST(Add32Zero,         _add32, 1,              0,                0 )

ADDER_PARTIAL_TEST(Inc32,             _inc32, 600'000*COEF,   generateBus32() )
ADDER_PARTIAL_TEST(Inc32MinusOne,     _inc32, 1,              0xFF'FF'FF'FFu )
ADDER_PARTIAL_TEST(Inc32MinusTwo,     _inc32, 1,              0xFF'FF'FF'FEu )
ADDER_PARTIAL_TEST(Inc32Zero,         _inc32, 1,              0 )
#undef ADDER_PARTIAL_TEST
#undef ADDER_PARTIAL_TEST_V
