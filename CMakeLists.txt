cmake_minimum_required(VERSION 3.16)
project(NandComputer)

set(CMAKE_CXX_STANDARD 20)

add_executable(NandComputer main.cpp tests/Timer.cpp tests/Timer.hpp tests/Random.cpp tests/Random.hpp hardware/Adders.cpp hardware/Adders.hpp hardware/BasicGates.cpp hardware/BasicGates.hpp tests/TestBasicGates.cpp tests/TestBasicGates.hpp hardware/Hardware.hpp tests/TestAdders.cpp tests/TestAdders.hpp tests/TestHardware.cpp tests/TestHardware.hpp)