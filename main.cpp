#include <iostream>
#include <memory>
#include "hardware/BasicGates.hpp"
#include "tests/TestAdders.hpp"
#include "experimental/Testcases.hpp"

int foo(int l, int j) { return j*l*2; }
int bar(int l, int j) { return j*l<<1; }
Input<int, int> gen() {return Input<int, int>(3, 5);}

int main()
{
    //TestBasicGates::full(true);
    //TestAdders::full(true);

    Testcase<bool, bool,bool> tc1(&Hardware::BasicGates::_nand, &Hardware::BasicGates::_nand_tt);
    //Testcase tc2(&Hardware::BasicGates::_nand, &Hardware::BasicGates::_nand_tt);

    std::cout<<"testcase 1: "<<tc1.run()<<"\n";
    //std::cout<<"testcase 2: "<<tc2.run()<<"\n";


    return 0;
}
