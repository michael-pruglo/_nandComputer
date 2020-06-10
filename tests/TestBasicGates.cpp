//
// Created by Michael on 06/10/20.
//

#include "TestBasicGates.hpp"

#include <iostream>
#include <cassert>
#include <iomanip>
#include "Random.hpp"
#include "../hardware/BasicGates.hpp"

using namespace Hardware;

bool TestBasicGates::full(bool verbose)
{
    std::cout<<"TestBasicGates::full scan: ";
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
            test_and8way,
            test_or8way,
            test_mux4way32,
            test_mux8way32,
            test_dmux4way,
            test_dmux8way
    })
    {
        fun(verbose);
        ++testNo;
    }


    if (!verbose)
        std::cout<<"OK\n";
    else
    {
        std::cout<<"====TestBasicGates::full scan finished====\n";
        std::cout<<"    # of tests passed: "<<testNo<<"\n";
    }

    return true;
}

bool TestBasicGates::test_nand(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _nand: ";
    auto gate = BasicGates::_nand;
    assert(gate(0, 0) == 1);
    assert(gate(0, 1) == 1);
    assert(gate(1, 0) == 1);
    assert(gate(1, 1) == 0);
    if (verbose) std::cout<<"OK.\ttesting time: "<<std::setw(10)<<timens2arg(gate)<<" ns\n";
    return true;
}

bool TestBasicGates::test_not(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _not: ";
    auto gate = BasicGates::_not;
    assert(gate(0) == 1);
    assert(gate(1) == 0);
    if (verbose) std::cout<<"OK.\ttesting time: "<<std::setw(10)<<timens1arg(gate)<<" ns\n";
    return true;
}

bool TestBasicGates::test_and(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _and: ";
    auto gate = BasicGates::_and;
    assert(gate(0, 0) == 0);
    assert(gate(0, 1) == 0);
    assert(gate(1, 0) == 0);
    assert(gate(1, 1) == 1);
    if (verbose) std::cout<<"OK.\ttesting time: "<<std::setw(10)<<timens2arg(gate)<<" ns\n";
    return true;
}

bool TestBasicGates::test_or(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _or: ";
    auto gate = BasicGates::_or;
    assert(gate(0, 0) == 0);
    assert(gate(0, 1) == 1);
    assert(gate(1, 0) == 1);
    assert(gate(1, 1) == 1);
    if (verbose) std::cout<<"OK.\ttesting time: "<<std::setw(10)<<timens2arg(gate)<<" ns\n";
    return true;
}

bool TestBasicGates::test_xor(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _xor: ";
    int v = 1;
    auto gate = BasicGates::_xor;
    assert(gate(0, 0) == 0);
    assert(gate(0, 1) == 1);
    assert(gate(1, 0) == 1);
    assert(gate(1, 1) == 0);
    if (verbose) std::cout<<"OK.\ttesting time: "<<std::setw(10)<<timens2arg(gate)<<" ns\n";
    return true;
}

bool TestBasicGates::test_mux(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _mux: ";
    auto gate = BasicGates::_mux;
    assert(gate(0, 0, 0) == 0);
    assert(gate(0, 1, 0) == 0);
    assert(gate(1, 0, 0) == 1);
    assert(gate(1, 1, 0) == 1);
    assert(gate(0, 0, 1) == 0);
    assert(gate(0, 1, 1) == 1);
    assert(gate(1, 0, 1) == 0);
    assert(gate(1, 1, 1) == 1);
    if (verbose) std::cout<<"OK.\ttesting time: "<<std::setw(10)<<timens3arg(gate)<<" ns\n";
    return true;
}

bool TestBasicGates::test_dmux(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _dmux: ";
    auto gate = BasicGates::_dmux;
    assert((gate(0, 0) == std::array<bool, 2>{0, 0}));
    assert((gate(0, 1) == std::array<bool, 2>{0, 0}));
    assert((gate(1, 0) == std::array<bool, 2>{1, 0}));
    assert((gate(1, 1) == std::array<bool, 2>{0, 1}));
    if (verbose) std::cout<<"OK.\ttesting time: "<<std::setw(10)<<timens2arg(gate)<<" ns\n";
    return true;
}

bool TestBasicGates::test_not32(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _not32: ";
    auto gate = BasicGates::_not32;
    auto rng = Random<uint32_t>();
    for (int i = 0; i < RANDOM_AMOUNT_N; ++i) {
        uint32_t n = rng.get();
        assert (gate(n) == ~n);
    }
    if (verbose) std::cout<<"OK.\ttesting time: "<<std::setw(10)<<timens1arg(gate)<<" ns\n";
    return true;
}

bool TestBasicGates::test_and32(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _and32: ";
    auto gate = BasicGates::_and32;
    auto rng = Random<uint32_t>();
    for (int i = 0; i < RANDOM_AMOUNT_N; ++i) {
        uint32_t a = rng.get();
        uint32_t b = rng.get();
        assert (gate(a, b) == (a&b));
    }
    if (verbose) std::cout<<"OK.\ttesting time: "<<std::setw(10)<<timens2arg(gate)<<" ns\n";
    return true;
}

bool TestBasicGates::test_or32(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _or32: ";
    auto gate = BasicGates::_or32;
    auto rng = Random<uint32_t>();
    for (int i = 0; i < RANDOM_AMOUNT_N; ++i) {
        uint32_t a = rng.get();
        uint32_t b = rng.get();
        assert (gate(a, b) == (a|b));
    }
    if (verbose) std::cout<<"OK.\ttesting time: "<<std::setw(10)<<timens2arg(gate)<<" ns\n";
    return true;
}

bool TestBasicGates::test_mux32(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _mux32: ";
    auto gate = BasicGates::_mux32;
    auto rng = Random<uint32_t>();
    for (int i = 0; i < RANDOM_AMOUNT_N; ++i) {
        uint32_t a = rng.get();
        uint32_t b = rng.get();
        assert (gate(a, b, 0) == a);
        assert (gate(a, b, 1) == b);
    }
    if (verbose) std::cout<<"OK.\ttesting time: "<<std::setw(10)<<timens3arg(gate)<<" ns\n";
    return true;
}

bool TestBasicGates::test_and8way(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _and8way: ";
    auto gate = BasicGates::_and8way;
    auto rng = Random<uint8_t>();
    for (int i = 0; i < RANDOM_AMOUNT_N; ++i) {
        uint8_t a = rng.get();
        assert (gate(a) == (__builtin_popcount(a)==8));
    }
    if (verbose) std::cout<<"OK.\ttesting time: "<<std::setw(10)<<timens1arg(gate)<<" ns\n";
    return true;
}

bool TestBasicGates::test_or8way(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _or8way: ";
    auto gate = BasicGates::_or8way;
    auto rng = Random<uint8_t>();
    for (int i = 0; i < RANDOM_AMOUNT_N; ++i) {
        uint8_t a = rng.get();
        assert (gate(a) == (__builtin_popcount(a)>0));
    }
    if (verbose) std::cout<<"OK.\ttesting time: "<<std::setw(10)<<timens1arg(gate)<<" ns\n";
    return true;
}

bool TestBasicGates::test_mux4way32(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _mux4way32: ";
    auto gate = BasicGates::_mux4way32;
    auto rng = Random<uint32_t>();
    for (int i = 0; i < RANDOM_AMOUNT_N; ++i) {
        uint32_t a = rng.get();
        uint32_t b = rng.get();
        uint32_t c = rng.get();
        uint32_t d = rng.get();
        assert (gate(a, b, c, d, 0, 0) == a);
        assert (gate(a, b, c, d, 0, 1) == c);
        assert (gate(a, b, c, d, 1, 0) == b);
        assert (gate(a, b, c, d, 1, 1) == d);
    }
    if (verbose) std::cout<<"OK.\ttesting time: "<<std::setw(10)<<timens(gate, 0,0,0,0,0,0)<<" ns\n";
    return true;
}

bool TestBasicGates::test_mux8way32(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _mux8way32: ";
    auto gate = BasicGates::_mux8way32;
    auto rng = Random<uint32_t>();
    for (int i = 0; i < RANDOM_AMOUNT_N; ++i) {
        uint32_t a = rng.get();
        uint32_t b = rng.get();
        uint32_t c = rng.get();
        uint32_t d = rng.get();
        uint32_t e = rng.get();
        uint32_t f = rng.get();
        uint32_t g = rng.get();
        uint32_t h = rng.get();
        assert (gate(a, b, c, d, e, f, g, h, 0, 0, 0) == a);
        assert (gate(a, b, c, d, e, f, g, h, 0, 0, 1) == e);
        assert (gate(a, b, c, d, e, f, g, h, 0, 1, 0) == c);
        assert (gate(a, b, c, d, e, f, g, h, 0, 1, 1) == g);
        assert (gate(a, b, c, d, e, f, g, h, 1, 0, 0) == b);
        assert (gate(a, b, c, d, e, f, g, h, 1, 0, 1) == f);
        assert (gate(a, b, c, d, e, f, g, h, 1, 1, 0) == d);
        assert (gate(a, b, c, d, e, f, g, h, 1, 1, 1) == h);
    }
    if (verbose) std::cout<<"OK.\ttesting time: "<<std::setw(10)<<timens(gate, 0,0,0,0,0,0,0,0,0,0,0)<<" ns\n";
    return true;
}

bool TestBasicGates::test_dmux4way(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _dmux4way: ";
    auto gate = BasicGates::_dmux4way;
    assert((gate(0, 0, 0) == std::array<bool, 4>{0, 0, 0, 0}));
    assert((gate(0, 0, 1) == std::array<bool, 4>{0, 0, 0, 0}));
    assert((gate(0, 1, 0) == std::array<bool, 4>{0, 0, 0, 0}));
    assert((gate(0, 1, 1) == std::array<bool, 4>{0, 0, 0, 0}));
    assert((gate(1, 0, 0) == std::array<bool, 4>{1, 0, 0, 0}));
    assert((gate(1, 0, 1) == std::array<bool, 4>{0, 0, 1, 0}));
    assert((gate(1, 1, 0) == std::array<bool, 4>{0, 1, 0, 0}));
    assert((gate(1, 1, 1) == std::array<bool, 4>{0, 0, 0, 1}));
    if (verbose) std::cout<<"OK.\ttesting time: "<<std::setw(10)<<timens3arg(gate)<<" ns\n";
    return true;
}

bool TestBasicGates::test_dmux8way(bool verbose)
{
    if (verbose) std::cout<<"\ttesting _dmux8way: ";
    auto gate = BasicGates::_dmux8way;
    assert((gate(0, 0, 0, 0) == std::array<bool, 8>{0, 0, 0, 0, 0, 0, 0, 0}));
    assert((gate(0, 0, 0, 1) == std::array<bool, 8>{0, 0, 0, 0, 0, 0, 0, 0}));
    assert((gate(0, 0, 1, 0) == std::array<bool, 8>{0, 0, 0, 0, 0, 0, 0, 0}));
    assert((gate(0, 0, 1, 1) == std::array<bool, 8>{0, 0, 0, 0, 0, 0, 0, 0}));
    assert((gate(0, 1, 0, 0) == std::array<bool, 8>{0, 0, 0, 0, 0, 0, 0, 0}));
    assert((gate(0, 1, 0, 1) == std::array<bool, 8>{0, 0, 0, 0, 0, 0, 0, 0}));
    assert((gate(0, 1, 1, 0) == std::array<bool, 8>{0, 0, 0, 0, 0, 0, 0, 0}));
    assert((gate(0, 1, 1, 1) == std::array<bool, 8>{0, 0, 0, 0, 0, 0, 0, 0}));
    assert((gate(1, 0, 0, 0) == std::array<bool, 8>{1, 0, 0, 0, 0, 0, 0, 0}));
    assert((gate(1, 0, 0, 1) == std::array<bool, 8>{0, 0, 0, 0, 1, 0, 0, 0}));
    assert((gate(1, 0, 1, 0) == std::array<bool, 8>{0, 0, 1, 0, 0, 0, 0, 0}));
    assert((gate(1, 0, 1, 1) == std::array<bool, 8>{0, 0, 0, 0, 0, 0, 1, 0}));
    assert((gate(1, 1, 0, 0) == std::array<bool, 8>{0, 1, 0, 0, 0, 0, 0, 0}));
    assert((gate(1, 1, 0, 1) == std::array<bool, 8>{0, 0, 0, 0, 0, 1, 0, 0}));
    assert((gate(1, 1, 1, 0) == std::array<bool, 8>{0, 0, 0, 1, 0, 0, 0, 0}));
    assert((gate(1, 1, 1, 1) == std::array<bool, 8>{0, 0, 0, 0, 0, 0, 0, 1}));
    if (verbose) std::cout<<"OK.\ttesting time: "<<std::setw(10)<<timens(gate, 0,0,0,0)<<" ns\n";
    return true;
}
