//
// Created by Michael on 06/08/20.
//

#ifndef NANDCOMPUTER_TESTLOGICGATES_HPP
#define NANDCOMPUTER_TESTLOGICGATES_HPP

#include <vector>
#include <functional>

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

private:
    struct GateFunction
    {
        std::function<bool(bool)> foo1;
        std::function<bool(bool,bool)> foo2;
        std::function<bool(bool,bool,bool)> foo3;
        GateFunction(std::function<bool(bool)> f1) : foo1(std::move(f1)) {}
        GateFunction(std::function<bool(bool,bool)> f2) : foo2(std::move(f2)) {}
        GateFunction(std::function<bool(bool,bool,bool)> f3) : foo3(std::move(f3)) {}
        bool operator()(std::vector<bool> args) const
        {
            if (args.size()==1) return foo1(args[0]);
            if (args.size()==2) return foo2(args[0], args[1]);
            if (args.size()==3) return foo3(args[0], args[1], args[2]);
        }
    };

    static const int EXHAUSTIVE_TIME_N = 1'000'000;
    typedef std::vector<std::pair<std::vector<bool>, bool>> TruthTable;
    static bool test(const std::string& name,
                     const GateFunction& fun,
                     const TestLogicGates::TruthTable& table,
                     bool verbose = false);
    static bool testGate(const GateFunction& fun, const TestLogicGates::TruthTable& table);
};


#endif //NANDCOMPUTER_TESTLOGICGATES_HPP
