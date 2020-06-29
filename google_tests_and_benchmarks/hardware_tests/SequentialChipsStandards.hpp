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
                tickOut[t+1] = gate(in[t], load);
                if (load)
                    EXPECT_EQ(tickOut[t+1], in[t])<<"t="<<t;
                else if (t)
                    EXPECT_EQ(tickOut[t+1], tickOut[t])<<"t="<<t;
            }
        EXPECT_EQ(gate.read(), tickOut[T]);
        for (auto item: EVERY_TRANSITION)
        {
            gate.write(item);
            auto stored = gate.read();
            EXPECT_EQ(stored, item);
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
                tickOut[t+1] = gate(in[t], load);
                if (load)
                    EXPECT_EQ(tickOut[t+1], in[t])<<"t="<<t;
                else if (t)
                    EXPECT_EQ(tickOut[t+1], tickOut[t])<<"t="<<t;
            }

        EXPECT_EQ(gate.read(), tickOut[T]);
        for (auto item: in)
        {
            gate.write(item);
            EXPECT_EQ(gate.read(), item);
        }
    }

    template <int N>
    void _RAM(Hardware::SequentialChips::_RAM<N> gate)
    {
        std::vector<int> candidateAddresses = {0, 1, N-2, N-1};
        int step = std::max(1, N/100);
        for (int i = 0; i < N; i+=step)
            candidateAddresses.push_back(i);
        
        const int VAL = 777;
        for (auto address:candidateAddresses)
        {
            gate(VAL, address, 1);
            EXPECT_EQ(gate(888, address, 0), VAL)<<"@ "<<address<<"\n";
        }

        for (auto address:candidateAddresses) EXPECT_EQ(gate.read(address), VAL)<<"@ "<<address<<"\n";
        for (auto address:candidateAddresses) gate.write(address, address);
        for (auto address:candidateAddresses) EXPECT_EQ(gate.read(address), address)<<"@ "<<address<<"\n";
    }
}

#endif //NANDCOMPUTER_SEQUENTIALCHIPSSTANDARDS_HPP
