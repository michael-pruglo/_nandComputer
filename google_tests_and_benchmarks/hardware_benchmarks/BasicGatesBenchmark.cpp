#include <benchmark/benchmark.h>
#include "src/hardware/BasicGates.hpp"

static void BM_BasicGates_nand      (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_nand(0, 0); } }
static void BM_BasicGates_not       (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_not(0); } }
static void BM_BasicGates_and       (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_and(0, 0); } }
static void BM_BasicGates_or        (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_or(0, 0); } }
static void BM_BasicGates_xor       (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_xor(0, 0); } }
static void BM_BasicGates_mux       (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_mux(0, 0, 0); } }
static void BM_BasicGates_dmux      (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_dmux(0, 0); } }
static void BM_BasicGates_not32     (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_not32(0); } }
static void BM_BasicGates_and32     (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_and32(0, 0); } }
static void BM_BasicGates_or32      (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_or32(0, 0); } }
static void BM_BasicGates_mux32     (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_mux32(0, 0, 0); } }
static void BM_BasicGates_and8way   (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_and8way(0); } }
static void BM_BasicGates_or8way    (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_or8way(0); } }
static void BM_BasicGates_mux4way32 (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_mux4way32(0, 0, 0, 0, 0, 0); } }
static void BM_BasicGates_mux8way32 (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_mux8way32(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0); } }
static void BM_BasicGates_dmux4way  (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_dmux4way(0, 0, 0); } }
static void BM_BasicGates_dmux8way  (benchmark::State& state) { for (auto _ : state) { Hardware::BasicGates::_dmux8way(0, 0, 0, 0); } }