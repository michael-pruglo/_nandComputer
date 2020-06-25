#include <benchmark/benchmark.h>
#include "src/hardware/BasicGates.hpp"
#include "src/hardware/BasicGates.cpp"

static void BM_nand             (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_nand(0, 0); } }
static void BM_not              (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_not(0); } }
static void BM_and              (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_and(0, 0); } }
static void BM_or               (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_or(0, 0); } }
static void BM_xor              (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_xor(0, 0); } }
static void BM_mux              (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_mux(0, 0, 0); } }
static void BM_dmux             (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_dmux(0, 0); } }
static void BM_not32            (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_not32(0); } }
static void BM_and32            (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_and32(0, 0); } }
static void BM_or32             (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_or32(0, 0); } }
static void BM_mux32            (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_mux32(0, 0, 0); } }
static void BM_and8way          (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_and8way(0); } }
static void BM_or8way           (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_or8way(0); } }
static void BM_mux4way32        (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_mux4way32(0, 0, 0, 0, 0, 0); } }
static void BM_mux8way32        (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_mux8way32(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); } }
static void BM_dmux4way         (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_dmux4way(0, 0, 0); } }
static void BM_dmux8way         (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_dmux8way(0, 0, 0, 0); } }

static void BM_nand_inline      (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_nand_inline(0, 0); } }
static void BM_not_inline       (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_not_inline(0); } }
static void BM_and_inline       (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_and_inline(0, 0); } }
static void BM_or_inline        (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_or_inline(0, 0); } }
static void BM_xor_inline       (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_xor_inline(0, 0); } }
static void BM_mux_inline       (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_mux_inline(0, 0, 0); } }
static void BM_dmux_inline      (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_dmux_inline(0, 0); } }
static void BM_not32_inline     (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_not32_inline(0); } }
static void BM_and32_inline     (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_and32_inline(0, 0); } }
static void BM_or32_inline      (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_or32_inline(0, 0); } }
static void BM_mux32_inline     (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_mux32_inline(0, 0, 0); } }
static void BM_and8way_inline   (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_and8way_inline(0); } }
static void BM_or8way_inline    (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_or8way_inline(0); } }
static void BM_mux4way32_inline (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_mux4way32_inline(0, 0, 0, 0, 0, 0); } }
static void BM_mux8way32_inline (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_mux8way32_inline(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); } }
static void BM_dmux4way_inline  (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_dmux4way_inline(0, 0, 0); } }
static void BM_dmux8way_inline  (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_dmux8way_inline(0, 0, 0, 0); } }



BENCHMARK(BM_nand            );
BENCHMARK(BM_nand_inline     );
BENCHMARK(BM_not             );
BENCHMARK(BM_not_inline      );
BENCHMARK(BM_and             );
BENCHMARK(BM_and_inline      );
BENCHMARK(BM_or              );
BENCHMARK(BM_or_inline       );
BENCHMARK(BM_xor             );
BENCHMARK(BM_xor_inline      );
BENCHMARK(BM_mux             );
BENCHMARK(BM_mux_inline      );
BENCHMARK(BM_dmux            );
BENCHMARK(BM_dmux_inline     );
BENCHMARK(BM_not32           );
BENCHMARK(BM_not32_inline    );
BENCHMARK(BM_and32           );
BENCHMARK(BM_and32_inline    );
BENCHMARK(BM_or32            );
BENCHMARK(BM_or32_inline     );
BENCHMARK(BM_mux32           );
BENCHMARK(BM_mux32_inline    );
BENCHMARK(BM_and8way         );
BENCHMARK(BM_and8way_inline  );
BENCHMARK(BM_or8way          );
BENCHMARK(BM_or8way_inline   );
BENCHMARK(BM_mux4way32       );
BENCHMARK(BM_mux4way32_inline);
BENCHMARK(BM_mux8way32       );
BENCHMARK(BM_mux8way32_inline);
BENCHMARK(BM_dmux4way        );
BENCHMARK(BM_dmux4way_inline );
BENCHMARK(BM_dmux8way        );
BENCHMARK(BM_dmux8way_inline );


BENCHMARK_MAIN();