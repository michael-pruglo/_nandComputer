#include "AddersBenchmark.cpp"
#include "BasicGatesBenchmark.cpp"


BENCHMARK(BM_Adders_half_adder   );
BENCHMARK(BM_Adders_full_adder   );
BENCHMARK(BM_Adders_full_adder_v2);
BENCHMARK(BM_Adders_add32        );
BENCHMARK(BM_Adders_inc32        );
BENCHMARK(BM_Adders_inc32_v2     );

BENCHMARK(BM_BasicGates_nand);
BENCHMARK(BM_BasicGates_not);
BENCHMARK(BM_BasicGates_and);
BENCHMARK(BM_BasicGates_or);
BENCHMARK(BM_BasicGates_xor);
BENCHMARK(BM_BasicGates_mux);
BENCHMARK(BM_BasicGates_dmux);
BENCHMARK(BM_BasicGates_not32);
BENCHMARK(BM_BasicGates_and32);
BENCHMARK(BM_BasicGates_or32);
BENCHMARK(BM_BasicGates_mux32);
BENCHMARK(BM_BasicGates_and8way);
BENCHMARK(BM_BasicGates_or8way);
BENCHMARK(BM_BasicGates_mux4way32);
BENCHMARK(BM_BasicGates_mux8way32);
BENCHMARK(BM_BasicGates_dmux4way);
BENCHMARK(BM_BasicGates_dmux8way);




BENCHMARK_MAIN();