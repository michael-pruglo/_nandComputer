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
HARDWARE_TRUTHTABLE_TEST_V(SequentialChips, RAM8, _RAM, _RAM<8>())
HARDWARE_TRUTHTABLE_TEST_V(SequentialChips, RAM64, _RAM, _RAM<64>())
HARDWARE_TRUTHTABLE_TEST_V(SequentialChips, RAM512, _RAM, _RAM<512>())
HARDWARE_TRUTHTABLE_TEST_V(SequentialChips, RAM4k, _RAM, _RAM<4'096>())
HARDWARE_TRUTHTABLE_TEST_V(SequentialChips, RAM32k, _RAM, _RAM<32'768>())
