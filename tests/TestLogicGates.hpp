//
// Created by Michael on 06/08/20.
//

#ifndef NANDCOMPUTER_TESTLOGICGATES_HPP
#define NANDCOMPUTER_TESTLOGICGATES_HPP

#include <chrono>
#include "Timer.hpp"

class TestLogicGates
{
public:
    static bool full(bool verbose = false);

    static bool test_nand(bool verbose = false);
    static bool test_not(bool verbose = false);
    static bool test_and(bool verbose = false);
    static bool test_or(bool verbose = false);
    static bool test_xor(bool verbose = false);
    static bool test_mux(bool verbose = false);
    static bool test_dmux(bool verbose = false);

    static bool test_not32(bool verbose = false);
    static bool test_and32(bool verbose = false);
    static bool test_or32(bool verbose = false);
    static bool test_mux32(bool verbose = false);

private:
    static const int RANDOM_AMOUNT_N = 1'000'00;
    static const int EXHAUSTIVE_TIME_N = 1'000'00;

    template<typename F>
    static auto timens1arg(F&& foo)
    {
        long long res = 0;
        for (auto arg1: {0, 1})
            res += Timer<std::chrono::nanoseconds>::exhaustive(EXHAUSTIVE_TIME_N,
                    foo, arg1);
        return res/2;
    }
    template<typename F>
    static auto timens2arg(F&& foo)
    {
        long long res = 0;
        for (auto arg1: {0, 1})
        for (auto arg2: {0, 1})
            res += Timer<std::chrono::nanoseconds>::exhaustive(EXHAUSTIVE_TIME_N,
                    foo, arg1, arg2);
        return res/4;
    }
    template<typename F>
    static auto timens3arg(F&& foo)
    {
        long long res = 0;
        for (auto arg1: {0, 1})
        for (auto arg2: {0, 1})
        for (auto arg3: {0, 1})
            res += Timer<std::chrono::nanoseconds>::exhaustive(EXHAUSTIVE_TIME_N,
                    foo, arg1, arg2, arg3);
        return res/8;
    }
};


#endif //NANDCOMPUTER_TESTLOGICGATES_HPP
