#ifndef NANDCOMPUTER_HARDWAREBENCHMARKMANAGER_HPP
#define NANDCOMPUTER_HARDWAREBENCHMARKMANAGER_HPP

#include <benchmark/benchmark.h>

///Main benchmark session
//#define REGISTER_BM_BASICGATES
//#define REGISTER_BM_ADDERS
//#define REGISTER_BM_ALU
#define REGISTER_BM_SEQUENTIALCHIPS

const int REPS_UNIMPORTANT = 1;
const int REPS = 5; //10=3.5min for basicGates+adders+alu
const int REPS_PRIORITY = 100;



///Macro definitions for easy registration
#define HARDWARE_BENCHMARK(TYPE, NAME, PARAMS) \
    static void BM_##TYPE##NAME(benchmark::State& state) { for (auto _ : state) { Hardware::TYPE::NAME PARAMS; } } \
    BENCHMARK(BM_##TYPE##NAME)

#define     ADDER_BENCHMARK(NAME, PARAMS) HARDWARE_BENCHMARK(Adders,     NAME, PARAMS)
#define BASICGATE_BENCHMARK(NAME, PARAMS) HARDWARE_BENCHMARK(BasicGates, NAME, PARAMS)
#define SEQUENTIALCHIP_BENCHMARK(CLASSNAME, PARAMS)  \
    static void BM_SequentialChips##CLASSNAME(benchmark::State& state) { auto gate=Hardware::SequentialChips::CLASSNAME(); for (auto _ : state) { gate PARAMS; } } \
    BENCHMARK(BM_SequentialChips##CLASSNAME)



#endif //NANDCOMPUTER_HARDWAREBENCHMARKMANAGER_HPP
