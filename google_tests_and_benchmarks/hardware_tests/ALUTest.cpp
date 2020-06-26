#include "HardwareTestManager.hpp"
#include "ALUStandards.hpp"
#include "src/hardware/ALU.hpp"

#include "InputGenerator.hpp"
HARDWARE_PARTIAL_TEST_V(ALU, ALU1, _alu, _alu, 18'000*COEF, generateBus32(), generateBus32())
HARDWARE_PARTIAL_TEST_V(ALU, ALU2, _alu, _alu, 10'000*COEF, generateBus32(), generateBus32(), generateBool(), generateBool(), generateBool(), generateBool(), generateBool(), generateBool())

