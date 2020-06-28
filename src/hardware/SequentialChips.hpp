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
        inline bool activate(bool data)
        {
            operator()(data, true);//tick
            return operator()(data, false);//tock
        }
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
        inline bool read() const { return q; }
    private:
        bool q, nq, bout, cout, dout;
    };

    class _bit
    {
    public:
        inline bool operator()(bool in, bool load)
        {
            return dff.activate(_mux(dff.read()/*uninit*/, in, load));
        }
        inline bool read() const { return dff.read(); }
        inline void write(bool val) { operator()(val, true); }
    private:
        _dff dff;
    };

    class _register32
    {
    public:
        inline Bus32 operator()(Bus32 in, bool load)
        {
            return    bits[ 0](  in &0x80000000u,  load  ) <<31u
                    | bits[ 1](  in &0x40000000u,  load  ) <<30u
                    | bits[ 2](  in &0x20000000u,  load  ) <<29u
                    | bits[ 3](  in &0x10000000u,  load  ) <<28u
                    | bits[ 4](  in & 0x8000000u,  load  ) <<27u
                    | bits[ 5](  in & 0x4000000u,  load  ) <<26u
                    | bits[ 6](  in & 0x2000000u,  load  ) <<25u
                    | bits[ 7](  in & 0x1000000u,  load  ) <<24u
                    | bits[ 8](  in &  0x800000u,  load  ) <<23u
                    | bits[ 9](  in &  0x400000u,  load  ) <<22u
                    | bits[10](  in &  0x200000u,  load  ) <<21u
                    | bits[11](  in &  0x100000u,  load  ) <<20u
                    | bits[12](  in &   0x80000u,  load  ) <<19u
                    | bits[13](  in &   0x40000u,  load  ) <<18u
                    | bits[14](  in &   0x20000u,  load  ) <<17u
                    | bits[15](  in &   0x10000u,  load  ) <<16u
                    | bits[16](  in &    0x8000u,  load  ) <<15u
                    | bits[17](  in &    0x4000u,  load  ) <<14u
                    | bits[18](  in &    0x2000u,  load  ) <<13u
                    | bits[19](  in &    0x1000u,  load  ) <<12u
                    | bits[20](  in &     0x800u,  load  ) <<11u
                    | bits[21](  in &     0x400u,  load  ) <<10u
                    | bits[22](  in &     0x200u,  load  ) << 9u
                    | bits[23](  in &     0x100u,  load  ) << 8u
                    | bits[24](  in &      0x80u,  load  ) << 7u
                    | bits[25](  in &      0x40u,  load  ) << 6u
                    | bits[26](  in &      0x20u,  load  ) << 5u
                    | bits[27](  in &      0x10u,  load  ) << 4u
                    | bits[28](  in &       0x8u,  load  ) << 3u
                    | bits[29](  in &       0x4u,  load  ) << 2u
                    | bits[30](  in &       0x2u,  load  ) << 1u
                    | bits[31](  in &       0x1u,  load  ) << 0u
                    ;
        }
        inline Bus32 read() const
        {
            return    bits[ 0].read() <<31u
                    | bits[ 1].read() <<30u
                    | bits[ 2].read() <<29u
                    | bits[ 3].read() <<28u
                    | bits[ 4].read() <<27u
                    | bits[ 5].read() <<26u
                    | bits[ 6].read() <<25u
                    | bits[ 7].read() <<24u
                    | bits[ 8].read() <<23u
                    | bits[ 9].read() <<22u
                    | bits[10].read() <<21u
                    | bits[11].read() <<20u
                    | bits[12].read() <<19u
                    | bits[13].read() <<18u
                    | bits[14].read() <<17u
                    | bits[15].read() <<16u
                    | bits[16].read() <<15u
                    | bits[17].read() <<14u
                    | bits[18].read() <<13u
                    | bits[19].read() <<12u
                    | bits[20].read() <<11u
                    | bits[21].read() <<10u
                    | bits[22].read() << 9u
                    | bits[23].read() << 8u
                    | bits[24].read() << 7u
                    | bits[25].read() << 6u
                    | bits[26].read() << 5u
                    | bits[27].read() << 4u
                    | bits[28].read() << 3u
                    | bits[29].read() << 2u
                    | bits[30].read() << 1u
                    | bits[31].read() << 0u
                    ;
        }
        inline void write(Bus32 val) { operator()(val, true); }
    private:
        std::array<_bit, 32> bits;
    };
}

#endif //NANDCOMPUTER_SEQUENTIALCHIPS_HPP
