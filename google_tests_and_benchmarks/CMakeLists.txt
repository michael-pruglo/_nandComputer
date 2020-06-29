project(google_benchmark)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${NandComputer_SOURCE_DIR})

add_executable(google_benchmark_run hardware_benchmarks/BasicGatesBenchmark.cpp hardware_benchmarks/AddersBenchmark.cpp hardware_benchmarks/HardwareBenchmarkManager.hpp BenchmarkMain.cpp hardware_benchmarks/ALUBenchmark.cpp hardware_benchmarks/SequentialChipsBenchmark.cpp)
target_link_libraries(google_benchmark_run gtest gtest_main)

include(FetchContent)
FetchContent_Declare(googlebenchmark GIT_REPOSITORY https://github.com/google/benchmark)
FetchContent_MakeAvailable(googlebenchmark)
target_link_libraries(google_benchmark_run benchmark::benchmark)

project(google_test)
add_executable(google_test hardware_tests/AddersStandards.hpp hardware_tests/AddersTest.cpp hardware_tests/BasicGatesStandards.hpp hardware_tests/BasicGatesTest.cpp hardware_tests/InputGenerator.hpp hardware_tests/HardwareTestManager.hpp hardware_tests/ALUStandards.hpp hardware_tests/ALUTest.cpp hardware_tests/SequentialChipsStandards.hpp hardware_tests/SequentialChipsTest.cpp)
target_link_libraries(google_test gtest gtest_main)

MATH(EXPR stack_size "16 * 1024 * 1024") # 16 Mb
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,${stack_size}")