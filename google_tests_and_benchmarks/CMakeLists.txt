project(google_benchmark)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${NandComputer_SOURCE_DIR})

add_executable(google_benchmark_run hardware_benchmarks/BasicGatesBenchmark.cpp)
target_link_libraries(google_benchmark_run gtest gtest_main)

include(FetchContent)
FetchContent_Declare(googlebenchmark GIT_REPOSITORY https://github.com/google/benchmark)
FetchContent_MakeAvailable(googlebenchmark)
target_link_libraries(google_benchmark_run benchmark::benchmark)

project(google_test)
add_executable(google_test hardware_tests/AddersStandards.hpp hardware_tests/AddersTest.cpp hardware_tests/BasicGatesStandards.hpp hardware_tests/BasicGatesTest.cpp hardware_tests/InputGenerator.hpp)
target_link_libraries(google_test gtest gtest_main)
