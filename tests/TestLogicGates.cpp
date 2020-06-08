//
// Created by Michael on 06/08/20.
//

#include <iostream>
#include "TestLogicGates.hpp"
#include "../hardware/LogicGates.hpp"
#include "Timer.hpp"


bool TestLogicGates::test(const std::string& name,
                          const GateFunction& fun,
                          const TestLogicGates::TruthTable& table,
                          bool verbose)
{
    if (verbose) std::cout<<"\ttesting "<<name<<" : ";
    bool res = testGate(fun, table);
    if (verbose) std::cout<<(res? "SUCCESS" : "FAILURE")<<"\ttime:"<<Timer<std::chrono::nanoseconds>::exhaustive(10'000'000, fun, table[0].first)<<"ns\n";
    return res;
}

bool TestLogicGates::testGate(const GateFunction& fun, const TestLogicGates::TruthTable& table)
{
    for (auto& [in, expected]: table)
    {
        auto out = fun(in);
        if (out != expected)
        {
            std::cout<<"\t\tFAILED TEST: ("; for (auto x:in) std::cout<<x<<","; std::cout<<")->"<<out<<", expected "<<expected<<"\n";
            return false;
        }
    }
    return true;
}

bool TestLogicGates::full(bool verbose)
{
    std::cout<<"TestLogicGates::full scan: ";
    if (verbose) std::cout<<"\n";


    int testNo = 0, goodNo = 0;
    for (auto& fun: {
        test_nand,
        test_not,
        test_and,
        test_or,
        test_xor,
        test_mux,
        })
    {
        goodNo += fun(verbose);
        ++testNo;
    }


    if (!verbose)
        std::cout<<(goodNo==testNo?"SUCCESS":"FAILURE")<<"\n";
    else
    {
        std::cout<<"====TestLogicGates::full scan finished====\n";
        std::cout<<"RESULTS:\n";
        std::cout<<"    #  "<<testNo<<"\n";
        std::cout<<"    +  "<<goodNo<<"\n";
        std::cout<<"    -  "<<testNo-goodNo<<"\n";
    }

    return goodNo == testNo;
}

bool TestLogicGates::test_nand(bool verbose)
{
    return test("_nand", GateFunction(LogicGates::_nand), {
            {{0, 0}, 1},
            {{0, 1}, 1},
            {{1, 0}, 1},
            {{1, 1}, 0}
        }, verbose);
}

bool TestLogicGates::test_not(bool verbose)
{
    return test("_not", GateFunction(LogicGates::_not), {
            {{0}, 1},
            {{1}, 0}
    }, verbose);
}

bool TestLogicGates::test_and(bool verbose)
{
    return test("_and", GateFunction(LogicGates::_and), {
            {{0, 0}, 0},
            {{0, 1}, 0},
            {{1, 0}, 0},
            {{1, 1}, 1}
    }, verbose);
}

bool TestLogicGates::test_or(bool verbose)
{
    return test("_or", GateFunction(LogicGates::_or), {
            {{0, 0}, 0},
            {{0, 1}, 1},
            {{1, 0}, 1},
            {{1, 1}, 1}
    }, verbose);
}

bool TestLogicGates::test_xor(bool verbose)
{
    return test("_xor", GateFunction(LogicGates::_xor), {
            {{0, 0}, 0},
            {{0, 1}, 1},
            {{1, 0}, 1},
            {{1, 1}, 0}
    }, verbose);
}

bool TestLogicGates::test_mux(bool verbose)
{
    return test("_mux", GateFunction(LogicGates::_mux), {
            {{0, 0, 0}, 0},
            {{0, 1, 0}, 0},
            {{1, 0, 0}, 1},
            {{1, 1, 0}, 1},
            {{0, 0, 1}, 0},
            {{0, 1, 1}, 1},
            {{1, 0, 1}, 0},
            {{1, 1, 1}, 1}
    }, verbose);
}
