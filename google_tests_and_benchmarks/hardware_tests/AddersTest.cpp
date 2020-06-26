#include "HardwareTestManager.hpp"
#include "AddersStandards.hpp"
#include "src/hardware/Adders.hpp"

ADDER_TRUTHTABLE_TEST  (HalfAdder,   _half_adder)
ADDER_TRUTHTABLE_TEST  (FullAdder,   _full_adder)
ADDER_TRUTHTABLE_TEST_V(FullAdderv2, _full_adder, _full_adder_v2)
#undef ADDER_TRUTHTABLE_TEST
#undef ADDER_TRUTHTABLE_TEST_V


#include "InputGenerator.hpp"

ADDER_PARTIAL_TEST  (Add32,   _add32,            400'000, generateBus32(), generateBus32() )
ADDER_PARTIAL_TEST  (Inc32,   _inc32,            500'000, generateBus32() )
ADDER_PARTIAL_TEST_V(Inc32v2, _inc32, _inc32_v2, 500'000, generateBus32() )
#undef ADDER_PARTIAL_TEST
#undef ADDER_PARTIAL_TEST_V
