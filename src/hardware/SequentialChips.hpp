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
                    _dff();
        inline bool activate(bool data);
        inline bool operator()(bool data, bool clock);
        inline bool read() const { return q; }
    private:
        bool q, nq, bout, cout, dout;
    };

    class _bit
    {
    public:
        inline bool operator()(bool in, bool load);
        inline bool read() const { return dff.read(); }
        inline void write(bool val) { operator()(val, true); }
    private:
        _dff dff;
    };

    class _register32
    {
    public:
        inline Bus32 operator()(Bus32 in, bool load);
        inline Bus32 read() const;
        inline void  write(Bus32 val) { operator()(val, true); }
    private:
        std::array<_bit, 32> bits;
    };

    template<int N>
    class _RAM
    {
    public:
                     _RAM() { assert(N%8==0); }
        inline Bus32 operator()(Bus32 in, Bus32 address, bool load);
        inline Bus32 read(Bus32 address) const;
        inline void  write(Bus32 val, Bus32 address) { operator()(val, address, true); }
    private:
        std::array<_RAM<N/8>, 8> memoryRegions;
    };

    template <>
    class _RAM<8>
    {
    public:
        inline Bus32 operator()(Bus32 in, Bus8 address, bool load);
        inline Bus32 read(Bus8 address) const;
        inline void  write(Bus32 val, Bus8 address) { operator()(val, address, true); }
    private:
        std::array<_register32, 8> memory;
    };
}



///Implementation
namespace Hardware::SequentialChips
{
    _dff::_dff() : q(!nq), bout(1), cout(1) {}
    bool _dff::activate(bool data)
    {
        operator()(data, true);//tick
        return operator()(data, false);//tock
    }
    bool _dff::operator()(bool data, bool clock)
    {
        //https://en.wikipedia.org/wiki/Flip-flop_(electronics)#/media/File:Edge_triggered_D_flip_flop.svg
        dout = _nand    (data,  cout);
        bout = _nand    (clock, _nand(dout, bout));
        cout = _nand3way(clock, bout, dout);
        nq   = _nand    (cout,  q);
        q    = _nand    (bout,  nq);
        return q;
    }



    bool _bit::operator()(bool in, bool load)
    {
        return dff.activate(_mux(dff.read()/*uninit*/, in, load));
    }



    Bus32 _register32::operator()(Bus32 in, bool load)
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
    Bus32 _register32::read() const
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




    template<int N>
    Bus32 _RAM<N>::operator()(Bus32 in, Bus32 address, bool load)
    {
        auto loads = _dmux8way(load, address&N>>3u, address&N>>2u, address&N>>1u);
        Bus32 childAddress = address&((N>>3u)-1u);
        Bus32 m0 = memoryRegions[0](in, childAddress, loads[0]);
        Bus32 m1 = memoryRegions[1](in, childAddress, loads[1]);
        Bus32 m2 = memoryRegions[2](in, childAddress, loads[2]);
        Bus32 m3 = memoryRegions[3](in, childAddress, loads[3]);
        Bus32 m4 = memoryRegions[4](in, childAddress, loads[4]);
        Bus32 m5 = memoryRegions[5](in, childAddress, loads[5]);
        Bus32 m6 = memoryRegions[6](in, childAddress, loads[6]);
        Bus32 m7 = memoryRegions[7](in, childAddress, loads[7]);
        return _mux8way32(m0,m1,m2,m3,m4,m5,m6,m7,address&N>>3u, address&N>>2u, address&N>>1u);
    }
    template<int N>
    Bus32 _RAM<N>::read(Bus32 address) const
    {
        Bus32 childAddress = address&((N>>3u)-1u);
        Bus32 m0 = memoryRegions[0].read(childAddress);
        Bus32 m1 = memoryRegions[1].read(childAddress);
        Bus32 m2 = memoryRegions[2].read(childAddress);
        Bus32 m3 = memoryRegions[3].read(childAddress);
        Bus32 m4 = memoryRegions[4].read(childAddress);
        Bus32 m5 = memoryRegions[5].read(childAddress);
        Bus32 m6 = memoryRegions[6].read(childAddress);
        Bus32 m7 = memoryRegions[7].read(childAddress);
        return _mux8way32(m0,m1,m2,m3,m4,m5,m6,m7,address&N>>3u, address&N>>2u, address&N>>1u);
    }


    Bus32 _RAM<8>::operator()(Bus32 in, Bus8 address, bool load)
    {
        auto loads = _dmux8way(load, address&0x1u, address&0x2u, address&0x4u);
        Bus32 m0 = memory[0](in, loads[0]);
        Bus32 m1 = memory[1](in, loads[1]);
        Bus32 m2 = memory[2](in, loads[2]);
        Bus32 m3 = memory[3](in, loads[3]);
        Bus32 m4 = memory[4](in, loads[4]);
        Bus32 m5 = memory[5](in, loads[5]);
        Bus32 m6 = memory[6](in, loads[6]);
        Bus32 m7 = memory[7](in, loads[7]);
        return _mux8way32(m0,m1,m2,m3,m4,m5,m6,m7,address&0x1u, address&0x2u, address&0x4u);
    }
    Bus32 _RAM<8>::read(Bus8 address) const
    {
        Bus32 m0 = memory[0].read();
        Bus32 m1 = memory[1].read();
        Bus32 m2 = memory[2].read();
        Bus32 m3 = memory[3].read();
        Bus32 m4 = memory[4].read();
        Bus32 m5 = memory[5].read();
        Bus32 m6 = memory[6].read();
        Bus32 m7 = memory[7].read();
        return _mux8way32(m0,m1,m2,m3,m4,m5,m6,m7,address&0x1u, address&0x2u, address&0x4u);
    }
}

#endif //NANDCOMPUTER_SEQUENTIALCHIPS_HPP
