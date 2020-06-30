#include "HardwareTestManager.hpp"
#include "SequentialChipsStandards.hpp"
#include "src/hardware/SequentialChips.hpp"

#include "InputGenerator.hpp"
HARDWARE_TRUTHTABLE_TEST_V(SequentialChips, DFF, _dff, _dff())
HARDWARE_TRUTHTABLE_TEST_V(SequentialChips, Bit, _bit, _bit())
HARDWARE_PARTIAL_TEST_V(SequentialChips, Register16, _register16, _register16(), 10*COEF, {
    generateBus16(),
    generateBus16(),
    generateBus16(),
    generateBus16(),
    generateBus16(),
    generateBus16(),
    generateBus16(),
    generateBus16(),
    generateBus16(),
    generateBus16()
})
HARDWARE_TRUTHTABLE_TEST_V(SequentialChips, RAM8, _RAM, _RAM<8>())
HARDWARE_TRUTHTABLE_TEST_V(SequentialChips, RAM64, _RAM, _RAM<64>())
HARDWARE_TRUTHTABLE_TEST_V(SequentialChips, RAM512, _RAM, _RAM<512>())
HARDWARE_TRUTHTABLE_TEST_V(SequentialChips, RAM4k, _RAM, _RAM<4'096>())
HARDWARE_TRUTHTABLE_TEST_V(SequentialChips, RAM32k, _RAM, _RAM<32'768>())

HARDWARE_PARTIAL_TEST_V(SequentialChips, Counter16, _counter16, _counter16(), 150'000*COEF, generateBus16(), generateBool(), generateBool(), generateBool())
HARDWARE_PARTIAL_TEST_V(SequentialChips, Counter16inc0, _counter16, _counter16(), 1, 0, 1, 0, 0)
HARDWARE_PARTIAL_TEST_V(SequentialChips, Counter16stay, _counter16, _counter16(), 1, 0xFF'FF, 0, 0, 0)
HARDWARE_PARTIAL_TEST_V(SequentialChips, Counter16reset, _counter16, _counter16(), 1, 0xFF'FF, 0, 0, 1)
HARDWARE_PARTIAL_TEST_V(SequentialChips, Counter16load, _counter16, _counter16(), 1, 0xFF'FF, 0, 1, 0)
HARDWARE_PARTIAL_TEST_V(SequentialChips, Counter16011, _counter16, _counter16(), 1, 0xFF'FF, 0, 1, 1)
HARDWARE_PARTIAL_TEST_V(SequentialChips, Counter16incmax, _counter16, _counter16(), 1, 0xFF'FF, 1, 0, 0)
HARDWARE_PARTIAL_TEST_V(SequentialChips, Counter16101, _counter16, _counter16(), 1, 0xFF'FF, 1, 0, 1)
HARDWARE_PARTIAL_TEST_V(SequentialChips, Counter16110, _counter16, _counter16(), 1, 0xFF'FF, 1, 1, 0)
HARDWARE_PARTIAL_TEST_V(SequentialChips, Counter16111, _counter16, _counter16(), 1, 0xFF'FF, 1, 1, 1)
