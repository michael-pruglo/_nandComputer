#include "HardwareBenchmarkManager.hpp"
#include "src/hardware/ALU.hpp"

const int REPS = 2;
const int REPSSM = 5;

#ifdef REGISTER_BM_ALU
    HARDWARE_BENCHMARK(ALU, _prepare32, (122, 0, 0))->Repetitions(REPSSM)->DisplayAggregatesOnly(true);
    HARDWARE_BENCHMARK(ALU, _neg_if32, (122, 0))->Repetitions(REPSSM)->DisplayAggregatesOnly(true);
    HARDWARE_BENCHMARK(ALU, _alu, (122,2374, 0,0,0,1,0,0))->Repetitions(REPS)->DisplayAggregatesOnly(true);
    HARDWARE_BENCHMARK(ALU, _prepare32_v2, (122, 0,0))->Repetitions(REPSSM)->DisplayAggregatesOnly(true);
    HARDWARE_BENCHMARK(ALU, _neg_if32_v2, (122, 0))->Repetitions(REPSSM)->DisplayAggregatesOnly(true);
    HARDWARE_BENCHMARK(ALU, _alu_v2, (122,2374, 0,0,1,0,0,0))->Repetitions(REPS)->DisplayAggregatesOnly(true);
//    HARDWARE_BENCHMARK(ALU, _alu, (state.range(0),state.range(1), state.range(2),state.range(3),state.range(4),state.range(5),state.range(6),state.range(7)))
//        ->Ranges({{5478347,5478347},{823943,823943},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1}})->Repetitions(20)->DisplayAggregatesOnly(true);
//    HARDWARE_BENCHMARK(ALU, _alu_v2, (state.range(0),state.range(1), state.range(2),state.range(3),state.range(4),state.range(5),state.range(6),state.range(7)))
//        ->Ranges({{5478347,5478347},{823943,823943},{0,1},{0,1},{0,1},{0,1},{0,1},{0,1}})->Repetitions(20)->DisplayAggregatesOnly(true);
#endif