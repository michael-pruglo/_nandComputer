#include "HardwareBenchmarkManager.hpp"
#include "src/hardware/ALU.hpp"

#ifdef REGISTER_BM_ALU
    HARDWARE_BENCHMARK(ALU, _alu,       (122,2374, 0,0,1,0,0,0))->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
    HARDWARE_BENCHMARK(ALU, _prepare16, (122, 0, 0))->Repetitions(REPS)->DisplayAggregatesOnly(true);
    HARDWARE_BENCHMARK(ALU, _neg_if16,  (122, 0))->Repetitions(REPS)->DisplayAggregatesOnly(true);
#endif