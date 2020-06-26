#include "HardwareBenchmarkManager.hpp"
#include "src/hardware/ALU.hpp"

#ifdef REGISTER_BM_ALU
    HARDWARE_BENCHMARK(ALU, _alu, (state.range(0),state.range(1), state.range(2),state.range(3),state.range(4),state.range(5),state.range(6),state.range(7)))
        ->Ranges({
             {5478347,5478347},
             {823943,823943},
            {0,1},
            {0,1},
            {0,1},
            {0,1},
            {0,1},
            {0,1}
        })
        ->Repetitions(20)->DisplayAggregatesOnly(true);
#endif