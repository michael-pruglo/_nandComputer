project(google_tests)
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${NandComputer_SOURCE_DIR})

add_executable(google_Tests_run hardware/BasicGatesTest.cpp hardware/BasicGatesStandards.hpp)
target_link_libraries(google_Tests_run ${NandComputer_SOURCE_DIR})
target_link_libraries(google_Tests_run gtest gtest_main)

