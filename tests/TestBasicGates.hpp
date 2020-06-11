//
// Created by Michael on 06/10/20.
//

#ifndef NANDCOMPUTER_TESTBASICGATES_HPP
#define NANDCOMPUTER_TESTBASICGATES_HPP

class TestBasicGates
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

    static bool test_and8way(bool verbose = false);
    static bool test_or8way(bool verbose = false);
    static bool test_mux4way32(bool verbose = false);
    static bool test_mux8way32(bool verbose = false);
    static bool test_dmux4way(bool verbose = false);
    static bool test_dmux8way(bool verbose = false);

private:
    static const int RANDOM_AMOUNT_N = 100'000;
    static const int EXHAUSTIVE_TIME_N = 2'000'000;
};


#endif //NANDCOMPUTER_TESTBASICGATES_HPP
