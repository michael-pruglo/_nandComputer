//
// Created by Michael on 06/11/20.
//

#ifndef NANDCOMPUTER_TESTADDERS_HPP
#define NANDCOMPUTER_TESTADDERS_HPP


class TestAdders
{
public:
    static bool full(bool verbose = false);

    static bool test_half_adder(bool verbose = false);
    static bool test_full_adder(bool verbose = false);
    static bool test_add32(bool verbose = false);
    static bool test_inc32(bool verbose = false);


private:
    static const int RANDOM_AMOUNT_N = 100'000;
    static const int EXHAUSTIVE_TIME_N = 2'000'000;
};


#endif //NANDCOMPUTER_TESTADDERS_HPP
