#include "HardwareTestManager.hpp"
#include "ALUStandards.hpp"
#include "src/hardware/ALU.hpp"

#include "InputGenerator.hpp"
HARDWARE_PARTIAL_TEST_V(ALU, Prepare32, _prepare32, _prepare32, 100'000*COEF, generateBus32(), generateBool(), generateBool())
HARDWARE_PARTIAL_TEST_V(ALU, Prepare32v2, _prepare32, _prepare32_v2, 100'000*COEF, generateBus32(), generateBool(), generateBool())
HARDWARE_PARTIAL_TEST_V(ALU, NegIf32, _neg_if32, _neg_if32, 100'000*COEF, generateBus32(), generateBool())
HARDWARE_PARTIAL_TEST_V(ALU, NegIf32v2, _neg_if32, _neg_if32_v2, 100'000*COEF, generateBus32(), generateBool())

HARDWARE_PARTIAL_TEST_V(ALU, ALU1, _alu, _alu, 18'000*COEF, generateBus32(), generateBus32())
HARDWARE_PARTIAL_TEST_V(ALU, ALU2, _alu, _alu, 10'000*COEF, generateBus32(), generateBus32(), generateBool(), generateBool(), generateBool(), generateBool(), generateBool(), generateBool())

HARDWARE_PARTIAL_TEST_V(ALU, ALUv21, _alu, _alu_v2, 18'000*COEF, generateBus32(), generateBus32())
HARDWARE_PARTIAL_TEST_V(ALU, ALUv22, _alu, _alu_v2, 10'000*COEF, generateBus32(), generateBus32(), generateBool(), generateBool(), generateBool(), generateBool(), generateBool(), generateBool())

