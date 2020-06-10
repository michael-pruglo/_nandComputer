cmake_minimum_required(VERSION 3.16)
project(NandComputer)

set(CMAKE_CXX_STANDARD 20)

add_executable(NandComputer main.cpp hardware/LogicGates.cpp hardware/LogicGates.hpp tests/TestLogicGates.cpp tests/TestLogicGates.hpp tests/Timer.cpp tests/Timer.hpp tests/Random.cpp tests/Random.hpp hardware/Adders.cpp hardware/Adders.hpp)