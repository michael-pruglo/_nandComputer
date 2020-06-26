#include "HardwareBenchmarkManager.hpp"
#include "src/hardware/BasicGates.hpp"

#ifdef REGISTER_BM_BASICGATES
    BASICGATE_BENCHMARK(_nand,      (0, 0)); //TODO: benchmark it on a range of arguments
    BASICGATE_BENCHMARK(_not,       (0));
    BASICGATE_BENCHMARK(_and,       (0, 0));
    BASICGATE_BENCHMARK(_or,        (0, 0));
    BASICGATE_BENCHMARK(_xor,       (0, 0));
    BASICGATE_BENCHMARK(_mux,       (0, 0, 0));
    BASICGATE_BENCHMARK(_dmux,      (0, 0));
    BASICGATE_BENCHMARK(_not32,     (0));
    BASICGATE_BENCHMARK(_and32,     (0, 0));
    BASICGATE_BENCHMARK(_or32,      (0, 0));
    BASICGATE_BENCHMARK(_mux32,     (0, 0, 0));
    BASICGATE_BENCHMARK(_is_zero32, (0));
    BASICGATE_BENCHMARK(_is_nzero32,(0));
    BASICGATE_BENCHMARK(_and8way,   (0));
    BASICGATE_BENCHMARK(_or8way,    (0));
    BASICGATE_BENCHMARK(_mux4way32, (0, 0, 0, 0, 0, 0));
    BASICGATE_BENCHMARK(_mux8way32, (0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    BASICGATE_BENCHMARK(_dmux4way,  (0, 0, 0));
    BASICGATE_BENCHMARK(_dmux8way,  (0, 0, 0, 0));
#endif
#undef BASICGATE_BENCHMARK
