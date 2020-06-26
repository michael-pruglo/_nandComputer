#include <iostream>
#include "hardware/BasicGates.hpp"

int main()
{
    std::cout<<"main():     _nand(0,0) = "<<Hardware::BasicGates::_nand(0,0)<<"\n";
    return 0;
}
