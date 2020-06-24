project(google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${NandComputer_SOURCE_DIR})

add_executable(google_Tests_run hardware_tests/BasicGatesTest.cpp hardware_tests/BasicGatesStandards.hpp hardware_tests/AddersStandards.hpp hardware_tests/AddersTest.cpp hardware_tests/InputGenerator.hpp)
target_link_libraries(google_Tests_run gtest gtest_main)

