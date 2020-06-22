#include <iostream>
#include "tests/TestBasicGates.hpp"
#include "tests/TestAdders.hpp"
#include "experimental/Testcases.hpp"

int foo(int l, int j) { return j*l*2; }
int bar(int l, int j) { return j*l<<1; }
Input<int, int> gen() {return Input<int, int>(3, 5);}

int main()
{
    //TestBasicGates::full(true);
    //TestAdders::full(true);

    Testcase<int,int,int> tc1(&foo, TruthTable<int, int, int>({
        std::make_pair(Input<int,int>(1,2), 4),
        std::make_pair(Input<int,int>(2,4), 16),
        std::make_pair(Input<int,int>(3,5), 30)
    }));
    Testcase<int,int,int> tc2(&foo, Standard<int,int,int>(&bar, std::function<Input<int, int>()>(&gen), 100));

    std::cout<<"testcase 1: "<<tc1.run()<<"\n";
    std::cout<<"testcase 2: "<<tc2.run()<<"\n";


    return 0;
}
