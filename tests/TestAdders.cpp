//
// Created by Michael on 06/11/20.
//

#include "TestAdders.hpp"

#include <iostream>
#include <cassert>
#include <iomanip>
#include "Random.hpp"
#include "Timer.hpp"
#include "../hardware/Adders.hpp"

using namespace Hardware;

bool TestAdders::full(bool verbose)
{
    std::cout<<"TestAdders::full scan: ";
    if (verbose) std::cout<<"\n";


    int testNo = 0;
    for (auto& fun: {
            test_half_adder,
            test_full_adder,
            test_add32,
//            test_inc32,
    })
    {
        fun(verbose);
        ++testNo;
    }


    if (!verbose)
        std::cout<<"OK\n";
    else
    {
        std::cout<<"====TestAdders::full scan finished====\n";
        std::cout<<"    # of tests passed: "<<testNo<<"\n";
    }

    return true;
}

bool TestAdders::test_half_adder(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _half_adder: ";
    auto gate = Adders::_half_adder;
    assert((gate(0, 0) == std::array<bool, 2>{0, 0}));
    assert((gate(0, 1) == std::array<bool, 2>{1, 0}));
    assert((gate(1, 0) == std::array<bool, 2>{1, 0}));
    assert((gate(1, 1) == std::array<bool, 2>{0, 1}));
    if (verbose) std::cout<<"OK.\ttesting time: "<<std::setw(10)<<Timer<std::chrono::nanoseconds>::timens2arg(EXHAUSTIVE_TIME_N, gate)<<" ns\n";
    return true;
}

bool TestAdders::test_full_adder(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _full_adder: \n";
    int v = 1;
    for (auto gate : {
        Adders::_full_adder,
        Adders::_full_adder_v2,
    }) {
        if (verbose) std::cout<<"\t\tv"<<v++<<":  ";
        assert((gate(0, 0, 0) == std::array<bool, 2>{0, 0}));
        assert((gate(0, 0, 1) == std::array<bool, 2>{1, 0}));
        assert((gate(0, 1, 0) == std::array<bool, 2>{1, 0}));
        assert((gate(0, 1, 1) == std::array<bool, 2>{0, 1}));
        assert((gate(1, 0, 0) == std::array<bool, 2>{1, 0}));
        assert((gate(1, 0, 1) == std::array<bool, 2>{0, 1}));
        assert((gate(1, 1, 0) == std::array<bool, 2>{0, 1}));
        assert((gate(1, 1, 1) == std::array<bool, 2>{1, 1}));
        if (verbose) std::cout<<"OK.\ttesting time: "<<std::setw(10)<<Timer<std::chrono::nanoseconds>::timens3arg(EXHAUSTIVE_TIME_N, gate)<<" ns\n";
    }
    return true;
}

bool TestAdders::test_add32(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _add32: \n";
    int v = 1;
    auto rng = Random<uint32_t>();
    for (auto gate : {
            Adders::_add32,
            //Adders::_add32_v2,
    }) {
        if (verbose) std::cout<<"\t\tv"<<v++<<":  ";
        for (int i = 0; i < RANDOM_AMOUNT_N; ++i) {
            uint32_t a = rng.get();
            uint32_t b = rng.get();
            assert (gate(a, b) == a+b);
        }
        if (verbose) std::cout<<"OK.\ttesting time: "<<std::setw(10)<<Timer<std::chrono::nanoseconds>::timens2arg(EXHAUSTIVE_TIME_N, gate)<<" ns\n";
    }
    return true;
}

bool TestAdders::test_inc32(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _inc32: \n";
    int v = 1;
    auto rng = Random<uint32_t>();
    for (auto gate : {
            Adders::_inc32,
    }) {
        if (verbose) std::cout<<"\t\tv"<<v++<<":  ";
        for (int i = 0; i < RANDOM_AMOUNT_N; ++i) {
            uint32_t a = rng.get();
            assert (gate(a) == a+1);
        }
        if (verbose) std::cout<<"OK.\ttesting time: "<<std::setw(10)<<Timer<std::chrono::nanoseconds>::timens1arg(EXHAUSTIVE_TIME_N, gate)<<" ns\n";
    }
    return true;
}


