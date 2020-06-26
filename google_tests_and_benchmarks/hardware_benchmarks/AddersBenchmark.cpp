#include <benchmark/benchmark.h>
#include "src/hardware/Adders.hpp"

static void BM_Adders_half_adder    (benchmark::State& state) { for (auto _ : state) { Hardware::Adders::_half_adder(0, 0); } }
static void BM_Adders_full_adder    (benchmark::State& state) { for (auto _ : state) { Hardware::Adders::_full_adder(0, 0, 0); } }
static void BM_Adders_full_adder_v2 (benchmark::State& state) { for (auto _ : state) { Hardware::Adders::_full_adder_v2(0, 0, 0); } }
static void BM_Adders_add32         (benchmark::State& state) { for (auto _ : state) { Hardware::Adders::_add32(0, 0); } }
static void BM_Adders_inc32         (benchmark::State& state) { for (auto _ : state) { Hardware::Adders::_inc32(0); } }
static void BM_Adders_inc32_v2      (benchmark::State& state) { for (auto _ : state) { Hardware::Adders::_inc32_v2(0); } }

