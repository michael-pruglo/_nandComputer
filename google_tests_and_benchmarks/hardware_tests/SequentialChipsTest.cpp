#include "HardwareTestManager.hpp"
#include "SequentialChipsStandards.hpp"
#include "src/hardware/SequentialChips.hpp"

#include "InputGenerator.hpp"
HARDWARE_TRUTHTABLE_TEST_V(SequentialChips, DFF, _dff, _dff())
HARDWARE_TRUTHTABLE_TEST_V(SequentialChips, Bit, _bit, _bit())
HARDWARE_PARTIAL_TEST_V(SequentialChips, Register32, _register32, _register32(), 10*COEF, {
    generateBus32(),
    generateBus32(),
    generateBus32(),
    generateBus32(),
    generateBus32(),
    generateBus32(),
    generateBus32(),
    generateBus32(),
    generateBus32(),
    generateBus32()
})
