#include "HardwareTestManager.hpp"
#include "BasicGatesStandards.hpp"
#include "src/hardware/BasicGates.hpp"

BASICGATE_TRUTHTABLE_TEST(Nand, _nand)
BASICGATE_TRUTHTABLE_TEST(Not, _not)
BASICGATE_TRUTHTABLE_TEST(And, _and)
BASICGATE_TRUTHTABLE_TEST(Or, _or)
BASICGATE_TRUTHTABLE_TEST(Xor, _xor)
BASICGATE_TRUTHTABLE_TEST(Mux, _mux)
BASICGATE_TRUTHTABLE_TEST(Dmux, _dmux)
BASICGATE_TRUTHTABLE_TEST(Dmux4way, _dmux4way)
BASICGATE_TRUTHTABLE_TEST(Dmux8way, _dmux8way)
#undef BASICGATE_TRUTHTABLE_TEST
#undef BASICGATE_TRUTHTABLE_TEST_V


#include "InputGenerator.hpp"

BASICGATE_PARTIAL_TEST(Not32,           _not32,     5'000'000*COEF,     generateBus32() )
BASICGATE_PARTIAL_TEST(Not32Zero,       _not32,     1,                  0 )
BASICGATE_PARTIAL_TEST(Not32MinusOne,   _not32,     1,                  0xFF'FF'FF'FFu )
BASICGATE_PARTIAL_TEST(And32,           _and32,     3'000'000*COEF,     generateBus32(), generateBus32() )
BASICGATE_PARTIAL_TEST(Or32,            _or32,      2'000'000*COEF,     generateBus32(), generateBus32() )
BASICGATE_PARTIAL_TEST(Mux32,           _mux32,     1'000'000*COEF,     generateBus32(), generateBus32() )
BASICGATE_PARTIAL_TEST(And8way,         _and8way,   6'000'000*COEF,     generateBus8() )
BASICGATE_PARTIAL_TEST(And8wayZero,     _and8way,   1,                  0 )
BASICGATE_PARTIAL_TEST(And8wayFull,     _and8way,   1,                  0xFFu )
BASICGATE_PARTIAL_TEST(Or8way,          _or8way,    6'000'000*COEF,     generateBus8() )
BASICGATE_PARTIAL_TEST(Or8wayZero,      _or8way,    1,                  0 )
BASICGATE_PARTIAL_TEST(Or8wayFull,      _or8way,    1,                  0xFFu )
BASICGATE_PARTIAL_TEST(Mux4way32,       _mux4way32, 200'000*COEF,       generateBus32(), generateBus32(), generateBus32(), generateBus32() )
BASICGATE_PARTIAL_TEST(Mux8way32,       _mux8way32, 40'000*COEF,        generateBus32(), generateBus32(), generateBus32(), generateBus32(), generateBus32(), generateBus32(), generateBus32(), generateBus32() )
#undef BASICGATE_PARTIAL_TEST
#undef BASICGATE_PARTIAL_TEST_V
