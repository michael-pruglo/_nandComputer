#include "HardwareTestManager.hpp"
#include "ALUStandards.hpp"
#include "src/hardware/ALU.hpp"

#include "InputGenerator.hpp"
HARDWARE_PARTIAL_TEST_V(ALU, Prepare16, _prepare16, _prepare16, 100'000*COEF, generateBus16(), generateBool(), generateBool())
HARDWARE_PARTIAL_TEST_V(ALU, NegIf16, _neg_if16, _neg_if16, 100'000*COEF, generateBus16(), generateBool())

HARDWARE_PARTIAL_TEST_V(ALU, ALU1, _alu, _alu, 18'000*COEF, generateBus16(), generateBus16())
HARDWARE_PARTIAL_TEST_V(ALU, ALU2, _alu, _alu, 10'000*COEF, generateBus16(), generateBus16(), generateBool(), generateBool(), generateBool(), generateBool(), generateBool(), generateBool())
