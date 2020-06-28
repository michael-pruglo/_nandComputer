#ifndef NANDCOMPUTER_SEQUENTIALCHIPS_HPP
#define NANDCOMPUTER_SEQUENTIALCHIPS_HPP

#include "Hardware.hpp"
#include "BasicGates.hpp"

namespace Hardware::SequentialChips
{
    using namespace Hardware::BasicGates;

    class _dff
    {
    public:
        _dff() : q(!nq), bout(1), cout(1) {}
        inline bool operator()(bool data, bool clock)
        {
            //https://en.wikipedia.org/wiki/Flip-flop_(electronics)#/media/File:Edge_triggered_D_flip_flop.svg
            dout = _nand    (data,  cout);
            bout = _nand    (clock, _nand(dout, bout));
            cout = _nand3way(clock, bout, dout);
            nq   = _nand    (cout,  q);
            q    = _nand    (bout,  nq);
            return q;
        }
    private:
        bool q, nq, bout, cout, dout;
    };

    class _bit
    {
    public:
        inline bool operator()(bool in, bool load, bool clock)
        {
            return (out = dff(_mux(out/*uninit*/, in, load), clock));
        }
    private:
        bool out;
        _dff dff;
    };

    class _register32
    {
    public:
        inline Bus32 operator()(Bus32 in, bool load, bool clock)
        {
            return    bits[ 0](  in &0x80000000u,  load,  clock  ) <<31u
                    | bits[ 1](  in &0x40000000u,  load,  clock  ) <<30u
                    | bits[ 2](  in &0x20000000u,  load,  clock  ) <<29u
                    | bits[ 3](  in &0x10000000u,  load,  clock  ) <<28u
                    | bits[ 4](  in & 0x8000000u,  load,  clock  ) <<27u
                    | bits[ 5](  in & 0x4000000u,  load,  clock  ) <<26u
                    | bits[ 6](  in & 0x2000000u,  load,  clock  ) <<25u
                    | bits[ 7](  in & 0x1000000u,  load,  clock  ) <<24u
                    | bits[ 8](  in &  0x800000u,  load,  clock  ) <<23u
                    | bits[ 9](  in &  0x400000u,  load,  clock  ) <<22u
                    | bits[10](  in &  0x200000u,  load,  clock  ) <<21u
                    | bits[11](  in &  0x100000u,  load,  clock  ) <<20u
                    | bits[12](  in &   0x80000u,  load,  clock  ) <<19u
                    | bits[13](  in &   0x40000u,  load,  clock  ) <<18u
                    | bits[14](  in &   0x20000u,  load,  clock  ) <<17u
                    | bits[15](  in &   0x10000u,  load,  clock  ) <<16u
                    | bits[16](  in &    0x8000u,  load,  clock  ) <<15u
                    | bits[17](  in &    0x4000u,  load,  clock  ) <<14u
                    | bits[18](  in &    0x2000u,  load,  clock  ) <<13u
                    | bits[19](  in &    0x1000u,  load,  clock  ) <<12u
                    | bits[20](  in &     0x800u,  load,  clock  ) <<11u
                    | bits[21](  in &     0x400u,  load,  clock  ) <<10u
                    | bits[22](  in &     0x200u,  load,  clock  ) << 9u
                    | bits[23](  in &     0x100u,  load,  clock  ) << 8u
                    | bits[24](  in &      0x80u,  load,  clock  ) << 7u
                    | bits[25](  in &      0x40u,  load,  clock  ) << 6u
                    | bits[26](  in &      0x20u,  load,  clock  ) << 5u
                    | bits[27](  in &      0x10u,  load,  clock  ) << 4u
                    | bits[28](  in &       0x8u,  load,  clock  ) << 3u
                    | bits[29](  in &       0x4u,  load,  clock  ) << 2u
                    | bits[30](  in &       0x2u,  load,  clock  ) << 1u
                    | bits[31](  in &       0x1u,  load,  clock  ) << 0u
                    ;
        }
    private:
        std::array<_bit, 32> bits;
    };
}

#endif //NANDCOMPUTER_SEQUENTIALCHIPS_HPP
