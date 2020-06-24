cmake_minimum_required(VERSION 3.16)
project(NandComputer)

set(CMAKE_CXX_STANDARD 20)

add_executable(NandComputer src/main.cpp src/hardware/Adders.cpp src/hardware/Adders.hpp src/hardware/BasicGates.cpp src/hardware/BasicGates.hpp src/hardware/Hardware.hpp)

add_subdirectory(google_tests)