cmake_minimum_required(VERSION 3.16)
project(NandComputer)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(google_tests_and_benchmarks)

add_executable(NandComputer src/main.cpp src/hardware/Adders.hpp src/hardware/BasicGates.hpp src/hardware/Hardware.hpp src/hardware/ALU.hpp src/hardware/SequentialChips.hpp)

MATH(EXPR stack_size "16 * 1024 * 1024") # 16 Mb
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--stack,${stack_size}")