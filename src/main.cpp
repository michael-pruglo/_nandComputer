#include <iostream>
#include "hardware/BasicGates.hpp"
#include "hardware/Adders.hpp"

int main()
{
    std::cout<<"main():     _nand(0,0) = "<<Hardware::BasicGates::_nand(0,0)<<"\n";
    std::cout<<"main():     _add32(17,39) = "<<Hardware::Adders::_add32(17,39)<<"\n";
    return 0;
}
