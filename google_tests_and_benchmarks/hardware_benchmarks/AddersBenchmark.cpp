#include "HardwareBenchmarkManager.hpp"
#include "src/hardware/Adders.hpp"

const int REPS = 10;
#ifdef REGISTER_BM_ADDERS
    ADDER_BENCHMARK(_half_adder,    (0, 0))->Repetitions(REPS)->DisplayAggregatesOnly(true);
    ADDER_BENCHMARK(_full_adder,    (0,0,0))->Repetitions(REPS)->DisplayAggregatesOnly(true);
    ADDER_BENCHMARK(_full_adder_v2, (0,0,0))->Repetitions(REPS)->DisplayAggregatesOnly(true);
    ADDER_BENCHMARK(_add32,         (0,0))->Repetitions(REPS)->DisplayAggregatesOnly(true);
    ADDER_BENCHMARK(_inc32,         (0))->Repetitions(REPS)->DisplayAggregatesOnly(true);
#endif
#undef ADDER_BENCHMARK