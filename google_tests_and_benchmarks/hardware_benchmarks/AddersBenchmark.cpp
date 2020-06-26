#include "HardwareBenchmarkManager.hpp"
#include "src/hardware/Adders.hpp"

#ifdef REGISTER_BM_ADDERS
    ADDER_BENCHMARK(_half_adder,    (0, 0));//->RangePair(0,1, 0,1);
    ADDER_BENCHMARK(_full_adder,    (0, 0, 0));
    ADDER_BENCHMARK(_full_adder_v2, (0, 0, 0));
    ADDER_BENCHMARK(_add32,         (0, 0));      
    ADDER_BENCHMARK(_inc32,         (0));//->Repetitions(10)->DisplayAggregatesOnly(true);
    ADDER_BENCHMARK(_inc32_v2,      (0)); 
#endif
#undef ADDER_BENCHMARK