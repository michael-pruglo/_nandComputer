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

HARDWARE_PARTIAL_TEST_V(SequentialChips, Counter32, _counter32, _counter32(), 150'000*COEF, generateBus32(), generateBool(), generateBool(), generateBool())
HARDWARE_PARTIAL_TEST_V(SequentialChips, Counter32inc0, _counter32, _counter32(), 1, 0, 1, 0, 0)
HARDWARE_PARTIAL_TEST_V(SequentialChips, Counter32stay, _counter32, _counter32(), 1, 0xFF'FF'FF'FF, 0, 0, 0)
HARDWARE_PARTIAL_TEST_V(SequentialChips, Counter32reset, _counter32, _counter32(), 1, 0xFF'FF'FF'FF, 0, 0, 1)
HARDWARE_PARTIAL_TEST_V(SequentialChips, Counter32load, _counter32, _counter32(), 1, 0xFF'FF'FF'FF, 0, 1, 0)
HARDWARE_PARTIAL_TEST_V(SequentialChips, Counter32011, _counter32, _counter32(), 1, 0xFF'FF'FF'FF, 0, 1, 1)
HARDWARE_PARTIAL_TEST_V(SequentialChips, Counter32incmax, _counter32, _counter32(), 1, 0xFF'FF'FF'FF, 1, 0, 0)
HARDWARE_PARTIAL_TEST_V(SequentialChips, Counter32101, _counter32, _counter32(), 1, 0xFF'FF'FF'FF, 1, 0, 1)
HARDWARE_PARTIAL_TEST_V(SequentialChips, Counter32110, _counter32, _counter32(), 1, 0xFF'FF'FF'FF, 1, 1, 0)
HARDWARE_PARTIAL_TEST_V(SequentialChips, Counter32111, _counter32, _counter32(), 1, 0xFF'FF'FF'FF, 1, 1, 1)
