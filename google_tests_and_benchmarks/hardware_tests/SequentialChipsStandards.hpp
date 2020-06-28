#ifndef NANDCOMPUTER_SEQUENTIALCHIPSSTANDARDS_HPP
#define NANDCOMPUTER_SEQUENTIALCHIPSSTANDARDS_HPP

#include <gtest/gtest.h>
#include "src/hardware/Hardware.hpp"

#include "src/hardware/SequentialChips.hpp"

namespace Standards::HardwareStandards::SequentialChipsStandards
{
    const std::array<bool, 5> EVERY_TRANSITION = {0,0,1,1,0};
    void _dff(Hardware::SequentialChips::_dff gate)
    {
        auto in = EVERY_TRANSITION;
        const int T = in.size();
        std::array<bool, T+1> tickOut; //tickOut[0] is uninit
        for (int t = 0; t < T; ++t)
        {
            bool isTick = true;
            tickOut[t+1] = gate(in[t], isTick);
            EXPECT_EQ(tickOut[t+1], in[t])
                <<"t = "<<t;

            isTick = false;
            bool tockOut = gate(in[t], isTick);
            EXPECT_EQ(tockOut, tickOut[t+1]);
        }
    }

    void _bit(Hardware::SequentialChips::_bit gate)
    {
        auto in = EVERY_TRANSITION;
        const int T = in.size();
        std::array<bool, T+1> tickOut; //tickOut[0] is uninit
        for (bool load: {false, true})
            for (int t = 0; t < T; ++t)
            {
                bool isTick = true;
                tickOut[t+1] = gate(in[t], load, isTick);
                EXPECT_EQ(tickOut[t+1], (load?in[t]:tickOut[t]));

                isTick = false;
                bool tockOut = gate(in[t], load, isTick);
                EXPECT_EQ(tockOut, tickOut[t+1]);
            }
    }

    void _register32(Hardware::SequentialChips::_register32 gate,
            const std::vector<Hardware::Bus32>& in)
    {
        const int T = in.size();
        std::vector<Hardware::Bus32> tickOut(T+1); //tickOut[0] is uninit
        for (bool load: {false, true})
            for (int t = 0; t < T; ++t)
            {
                bool isTick = true;
                tickOut[t+1] = gate(in[t], load, isTick);
                EXPECT_EQ(tickOut[t+1], (load?in[t]:tickOut[t]));

                isTick = false;
                Hardware::Bus32 tockOut = gate(in[t], load, isTick);
                EXPECT_EQ(tockOut, tickOut[t+1]);
            }
    }
}

#endif //NANDCOMPUTER_SEQUENTIALCHIPSSTANDARDS_HPP
