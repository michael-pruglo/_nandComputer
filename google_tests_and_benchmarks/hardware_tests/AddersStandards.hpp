#ifndef NANDCOMPUTER_ADDERSSTANDARDS_HPP
#define NANDCOMPUTER_ADDERSSTANDARDS_HPP

#include <gtest/gtest.h>
#include <bitset>
#include "src/hardware/Hardware.hpp"

namespace Standards::HardwareStandards::AddersStandards
{
    void _half_adder(std::array<bool, 2>(*gate)(bool,bool))
    {
        EXPECT_EQ((gate(0, 0)), (std::array<bool, 2>{0, 0}));
        EXPECT_EQ((gate(0, 1)), (std::array<bool, 2>{1, 0}));
        EXPECT_EQ((gate(1, 0)), (std::array<bool, 2>{1, 0}));
        EXPECT_EQ((gate(1, 1)), (std::array<bool, 2>{0, 1}));
    }

    void _full_adder(std::array<bool, 2>(*gate)(bool,bool,bool))
    {
        EXPECT_EQ((gate(0, 0, 0)), (std::array<bool, 2>{0, 0}));
        EXPECT_EQ((gate(0, 0, 1)), (std::array<bool, 2>{1, 0}));
        EXPECT_EQ((gate(0, 1, 0)), (std::array<bool, 2>{1, 0}));
        EXPECT_EQ((gate(0, 1, 1)), (std::array<bool, 2>{0, 1}));
        EXPECT_EQ((gate(1, 0, 0)), (std::array<bool, 2>{1, 0}));
        EXPECT_EQ((gate(1, 0, 1)), (std::array<bool, 2>{0, 1}));
        EXPECT_EQ((gate(1, 1, 0)), (std::array<bool, 2>{0, 1}));
        EXPECT_EQ((gate(1, 1, 1)), (std::array<bool, 2>{1, 1}));
    }

    void _add16(Hardware::Bus16(*gate)(Hardware::Bus16,Hardware::Bus16),
                Hardware::Bus16 a,
                Hardware::Bus16 b)
    {
        EXPECT_EQ((gate(a,b)), Hardware::Bus16(a+b)) << "a = "<<a<<" b = "<<b<<"\n";
    }

    void _inc16(Hardware::Bus16(*gate)(Hardware::Bus16),
                Hardware::Bus16 in)
    {
        EXPECT_EQ((gate(in)), Hardware::Bus16(in+1));
    }
    
    void _add32(Hardware::Bus32(*gate)(Hardware::Bus32,Hardware::Bus32),
                Hardware::Bus32 a,
                Hardware::Bus32 b)
    {
        EXPECT_EQ((gate(a,b)), (a+b)) << "a = "<<a<<" b = "<<b<<"\n";
    }

    void _inc32(Hardware::Bus32(*gate)(Hardware::Bus32),
                Hardware::Bus32 in)
    {
        EXPECT_EQ((gate(in)), (in+1));
    }
}

#endif //NANDCOMPUTER_ADDERSSTANDARDS_HPP
