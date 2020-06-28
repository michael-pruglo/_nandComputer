#include "HardwareBenchmarkManager.hpp"
#include "src/hardware/SequentialChips.hpp"

#ifdef REGISTER_BM_SEQUENTIALCHIPS
    SEQUENTIALCHIP_BENCHMARK(_dff, (0,0))->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
    SEQUENTIALCHIP_BENCHMARK(_bit, (0,0,0))->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
    SEQUENTIALCHIP_BENCHMARK(_register32, (0,0,0))->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
#endif