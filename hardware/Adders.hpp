//
// Created by Michael on 06/10/20.
//

#ifndef NANDCOMPUTER_ADDERS_HPP
#define NANDCOMPUTER_ADDERS_HPP

#include <array>
#include "LogicGates.hpp"

namespace Adders
{
    using namespace LogicGates;

    static std::array<bool, 2> _half_adder(bool a, bool b);
    //static _full_adder();
};


#endif //NANDCOMPUTER_ADDERS_HPP
