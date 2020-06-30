#include "HardwareBenchmarkManager.hpp"
#include "src/hardware/Adders.hpp"

#ifdef REGISTER_BM_ADDERS
    ADDER_BENCHMARK(_half_adder,    (0, 0))->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
    ADDER_BENCHMARK(_full_adder,    (0,0,0))->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
    ADDER_BENCHMARK(_add16,         (0,0))->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
    ADDER_BENCHMARK(_inc16,         (0))->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
    ADDER_BENCHMARK(_add32,         (0,0))->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
    ADDER_BENCHMARK(_inc32,         (0))->Repetitions(REPS_PRIORITY)->DisplayAggregatesOnly(true);
#endif
#undef ADDER_BENCHMARK