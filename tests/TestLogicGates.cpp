//
// Created by Michael on 06/08/20.
//

#include <iostream>
#include <cassert>
#include "TestLogicGates.hpp"
#include "Random.hpp"
#include "../hardware/LogicGates.hpp"

bool TestLogicGates::full(bool verbose)
{
    std::cout<<"TestLogicGates::full scan: ";
    if (verbose) std::cout<<"\n";


    int testNo = 0;
    for (auto& fun: {
        test_nand,
        test_not,
        test_and,
        test_or,
        test_xor,
        test_mux,
        test_dmux,
        test_not32,
        test_and32,
        test_or32,
        test_mux32,
        })
    {
        fun(verbose);
        ++testNo;
    }


    if (!verbose)
        std::cout<<"OK\n";
    else
    {
        std::cout<<"====TestLogicGates::full scan finished====\n";
        std::cout<<"    # of tests passed: "<<testNo<<"\n";
    }

    return true;
}

bool TestLogicGates::test_nand(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _nand: ";
    auto gate = LogicGates::_nand;
    assert(gate(0, 0) == 1);
    assert(gate(0, 1) == 1);
    assert(gate(1, 0) == 1);
    assert(gate(1, 1) == 0);
    if (verbose) std::cout<<"OK.\ttesting time: "<<timens2arg(gate)<<"ns\n";
    return true;
}

bool TestLogicGates::test_not(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _not: ";
    auto gate = LogicGates::_not;
    assert(gate(0) == 1);
    assert(gate(1) == 0);
    if (verbose) std::cout<<"OK.\ttesting time: "<<timens1arg(gate)<<"ns\n";
    return true;
}

bool TestLogicGates::test_and(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _and: ";
    auto gate = LogicGates::_and;
    assert(gate(0, 0) == 0);
    assert(gate(0, 1) == 0);
    assert(gate(1, 0) == 0);
    assert(gate(1, 1) == 1);
    if (verbose) std::cout<<"OK.\ttesting time: "<<timens2arg(gate)<<"ns\n";
    return true;
}

bool TestLogicGates::test_or(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _or: ";
    auto gate = LogicGates::_or;
    assert(gate(0, 0) == 0);
    assert(gate(0, 1) == 1);
    assert(gate(1, 0) == 1);
    assert(gate(1, 1) == 1);
    if (verbose) std::cout<<"OK.\ttesting time: "<<timens2arg(gate)<<"ns\n";
    return true;
}

bool TestLogicGates::test_xor(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _xor: ";
    auto gate = LogicGates::_xor;
    assert(gate(0, 0) == 0);
    assert(gate(0, 1) == 1);
    assert(gate(1, 0) == 1);
    assert(gate(1, 1) == 0);
    if (verbose) std::cout<<"OK.\ttesting time: "<<timens2arg(gate)<<"ns\n";
    return true;
}

bool TestLogicGates::test_mux(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _mux: ";
    auto gate = LogicGates::_mux;
    assert(gate(0, 0, 0) == 0);
    assert(gate(0, 1, 0) == 0);
    assert(gate(1, 0, 0) == 1);
    assert(gate(1, 1, 0) == 1);
    assert(gate(0, 0, 1) == 0);
    assert(gate(0, 1, 1) == 1);
    assert(gate(1, 0, 1) == 0);
    assert(gate(1, 1, 1) == 1);
    if (verbose) std::cout<<"OK.\ttesting time: "<<timens3arg(gate)<<"ns\n";
    return true;
}

bool TestLogicGates::test_dmux(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _dmux: ";
    auto gate = LogicGates::_dmux;
    assert((gate(0, 0) == std::array<bool, 2>{0, 0}));
    assert((gate(0, 1) == std::array<bool, 2>{0, 0}));
    assert((gate(1, 0) == std::array<bool, 2>{1, 0}));
    assert((gate(1, 1) == std::array<bool, 2>{0, 1}));
    if (verbose) std::cout<<"OK.\ttesting time: "<<timens2arg(gate)<<"ns\n";
    return true;
}

bool TestLogicGates::test_not32(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _not32: ";
    auto gate = LogicGates::_not32;
    auto rng = Random<uint32_t>();
    for (int i = 0; i < RANDOM_AMOUNT_N; ++i) {
        uint32_t n = rng.get();
        assert (gate(n) == ~n);
    }
    if (verbose) std::cout<<"OK.\ttesting time: "<<timens1arg(gate)<<"ns\n";
    return true;
}

bool TestLogicGates::test_and32(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _and32: ";
    auto gate = LogicGates::_and32;
    auto rng = Random<uint32_t>();
    for (int i = 0; i < RANDOM_AMOUNT_N; ++i) {
        uint32_t a = rng.get();
        uint32_t b = rng.get();
        assert (gate(a, b) == (a&b));
    }
    if (verbose) std::cout<<"OK.\ttesting time: "<<timens2arg(gate)<<"ns\n";
    return true;
}

bool TestLogicGates::test_or32(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _or32: ";
    auto gate = LogicGates::_or32;
    auto rng = Random<uint32_t>();
    for (int i = 0; i < RANDOM_AMOUNT_N; ++i) {
        uint32_t a = rng.get();
        uint32_t b = rng.get();
        assert (gate(a, b) == (a|b));
    }
    if (verbose) std::cout<<"OK.\ttesting time: "<<timens2arg(gate)<<"ns\n";
    return true;
}

bool TestLogicGates::test_mux32(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _mux32: ";
    auto gate = LogicGates::_mux32;
    auto rng = Random<uint32_t>();
    for (int i = 0; i < RANDOM_AMOUNT_N; ++i) {
        uint32_t a = rng.get();
        uint32_t b = rng.get();
        assert (gate(a, b, 0) == a);
        assert (gate(a, b, 1) == b);
    }
    if (verbose) std::cout<<"OK.\ttesting time: "<<timens3arg(gate)<<"ns\n";
    return true;
}
