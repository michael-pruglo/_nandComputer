#include <iostream>
#include <memory>
#include "hardware/BasicGates.hpp"
#include "tests/TestAdders.hpp"
#include "experimental/Testcases.hpp"
#include "utility/Random.hpp"

int foo(int l, int j) { return j*l*2; }
int bar(int l, int j) { return j*l<<1; }
Input<int, int> gen() {return Input<int, int>(3, 5);}

int main()
{
    //TestBasicGates::full(true);
    //TestAdders::full(true);

    Random<Hardware::Bus32> randomForBus32;
    for (int i = 0; i < 100; ++i)
        std::cout<<randomForBus32.get()<<"\n";


    return 0;
}
