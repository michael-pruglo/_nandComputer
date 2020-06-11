//
// Created by Michael on 06/10/20.
//

#ifndef NANDCOMPUTER_ADDERS_HPP
#define NANDCOMPUTER_ADDERS_HPP

#include <array>
#include "BasicGates.hpp"

namespace Hardware::Adders
{
    ///return {sum, carry}
    std::array<bool, 2> _half_adder(bool a, bool b);
    std::array<bool, 2> _full_adder(bool a, bool b, bool c);
    std::array<bool, 2> _full_adder_v2(bool a, bool b, bool c);

                  Bus32 _add32(Bus32 a, Bus32 b);
                  Bus32 _add32_v2(Bus32 a, Bus32 b);
                  Bus32 _inc32(Bus32 a);
};

#endif //NANDCOMPUTER_ADDERS_HPP
