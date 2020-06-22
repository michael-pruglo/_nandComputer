#include <iostream>
#include <memory>
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

    Testcase<int,int,int> tc1(
            &foo,
            new TruthTable({
                std::make_pair(Input<int,int>(1,2), 4),
                std::make_pair(Input<int,int>(1,2), 4),
            })
    );
    Testcase<int,int,int> tc2(
            &foo,
            new Standard<int,int,int>(&bar, &gen, 2)
    );
    //TODO: memory leak patch

    std::cout<<"testcase 1: "<<tc1.run()<<"\n";
    std::cout<<"testcase 2: "<<tc2.run()<<"\n";


    return 0;
}
