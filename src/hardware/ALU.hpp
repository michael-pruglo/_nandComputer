#ifndef NANDCOMPUTER_ALU_HPP
#define NANDCOMPUTER_ALU_HPP

#include <tuple>
#include "Hardware.hpp"
#include "BasicGates.hpp"
#include "Adders.hpp"

namespace Hardware::ALU
{
    using namespace Hardware::BasicGates;
    using namespace Hardware::Adders;

    inline Bus32 _zero_if32(Bus32 in, bool z) { return _mux32(in, 0, z); }
    inline Bus32 _neg_if32(Bus32 in, bool n) { return _mux32(in, ~in, n); }
    inline Bus32 _prepare32(Bus32 in, bool z, bool n) { return _neg_if32(_zero_if32(in, z), n); }

    std::tuple<Bus32,bool,bool> _alu(Bus32 x, Bus32 y,
                                     bool zx, bool nx, bool zy, bool ny, bool f, bool no)
    {
        x = _prepare32(x, zx, nx);
        y = _prepare32(y, zy, ny);
        Bus32 out = _mux32(_and32(x, y), _add32(x, y), f);
        out = _neg_if32(out, no);

        bool zr = _is_zero32(out);
        bool ng = out&0x80'00'00'00;
        return std::tuple<Bus32,bool,bool>{out, zr, ng};
    }
}

#endif //NANDCOMPUTER_ALU_HPP
