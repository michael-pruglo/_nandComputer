#ifndef NANDCOMPUTER_ADDERS_HPP
#define NANDCOMPUTER_ADDERS_HPP

#include <array>
#include "BasicGates.hpp"

namespace Hardware::Adders
{
    ///return {sum, carry}
    inline std::array<bool, 2> _half_adder(bool a, bool b);
    inline std::array<bool, 2> _full_adder(bool a, bool b, bool c);

    inline               Bus32 _add32(Bus32 a, Bus32 b);
    inline               Bus32 _inc32(Bus32 in);
};




///Implementation
namespace Hardware::Adders {

    using namespace Hardware::BasicGates;

    ///return {sum, carry}
    inline std::array<bool, 2> _half_adder(bool a, bool b)
    {
        bool tmp = _nand(a, b);
        return {
                _nand(_nand(a, tmp), _nand(tmp, b)),
                _nand(tmp, tmp)
        };
    }
    inline std::array<bool, 2> _half_adder_v2(bool a, bool b)
    {
        return {
                _xor(a, b),
                _and(a, b)
        };
    }

    inline std::array<bool, 2> _full_adder(bool a, bool b, bool c)
    {
        bool nandab = _nand(a, b);
        bool xorab = _nand(_nand(a, nandab), _nand(nandab, b));
        bool tmp = _nand(xorab, c);
        return {
                _nand(_nand(xorab, tmp), _nand(tmp, c)),
                _nand(tmp, nandab)
        };
    }
    inline std::array<bool, 2> _full_adder_v2(bool a, bool b, bool c)
    {
        return {
                _xor(_xor(a, b), c),
                _mux(_and(b, c), _or(b, c), a)
        };
    }

    inline Bus32 _add32(Bus32 a, Bus32 b)
    {
        auto [sum0,  carry0 ] = _half_adder(  a &       0x1u,  b &       0x1u  );
        auto [sum1,  carry1 ] = _full_adder(  a &       0x2u,  b &       0x2u,  carry0   );
        auto [sum2,  carry2 ] = _full_adder(  a &       0x4u,  b &       0x4u,  carry1   );
        auto [sum3,  carry3 ] = _full_adder(  a &       0x8u,  b &       0x8u,  carry2   );
        auto [sum4,  carry4 ] = _full_adder(  a &      0x10u,  b &      0x10u,  carry3   );
        auto [sum5,  carry5 ] = _full_adder(  a &      0x20u,  b &      0x20u,  carry4   );
        auto [sum6,  carry6 ] = _full_adder(  a &      0x40u,  b &      0x40u,  carry5   );
        auto [sum7,  carry7 ] = _full_adder(  a &      0x80u,  b &      0x80u,  carry6   );
        auto [sum8,  carry8 ] = _full_adder(  a &     0x100u,  b &     0x100u,  carry7   );
        auto [sum9,  carry9 ] = _full_adder(  a &     0x200u,  b &     0x200u,  carry8   );
        auto [sum10, carry10] = _full_adder(  a &     0x400u,  b &     0x400u,  carry9   );
        auto [sum11, carry11] = _full_adder(  a &     0x800u,  b &     0x800u,  carry10  );
        auto [sum12, carry12] = _full_adder(  a &    0x1000u,  b &    0x1000u,  carry11  );
        auto [sum13, carry13] = _full_adder(  a &    0x2000u,  b &    0x2000u,  carry12  );
        auto [sum14, carry14] = _full_adder(  a &    0x4000u,  b &    0x4000u,  carry13  );
        auto [sum15, carry15] = _full_adder(  a &    0x8000u,  b &    0x8000u,  carry14  );
        auto [sum16, carry16] = _full_adder(  a &   0x10000u,  b &   0x10000u,  carry15  );
        auto [sum17, carry17] = _full_adder(  a &   0x20000u,  b &   0x20000u,  carry16  );
        auto [sum18, carry18] = _full_adder(  a &   0x40000u,  b &   0x40000u,  carry17  );
        auto [sum19, carry19] = _full_adder(  a &   0x80000u,  b &   0x80000u,  carry18  );
        auto [sum20, carry20] = _full_adder(  a &  0x100000u,  b &  0x100000u,  carry19  );
        auto [sum21, carry21] = _full_adder(  a &  0x200000u,  b &  0x200000u,  carry20  );
        auto [sum22, carry22] = _full_adder(  a &  0x400000u,  b &  0x400000u,  carry21  );
        auto [sum23, carry23] = _full_adder(  a &  0x800000u,  b &  0x800000u,  carry22  );
        auto [sum24, carry24] = _full_adder(  a & 0x1000000u,  b & 0x1000000u,  carry23  );
        auto [sum25, carry25] = _full_adder(  a & 0x2000000u,  b & 0x2000000u,  carry24  );
        auto [sum26, carry26] = _full_adder(  a & 0x4000000u,  b & 0x4000000u,  carry25  );
        auto [sum27, carry27] = _full_adder(  a & 0x8000000u,  b & 0x8000000u,  carry26  );
        auto [sum28, carry28] = _full_adder(  a &0x10000000u,  b &0x10000000u,  carry27  );
        auto [sum29, carry29] = _full_adder(  a &0x20000000u,  b &0x20000000u,  carry28  );
        auto [sum30, carry30] = _full_adder(  a &0x40000000u,  b &0x40000000u,  carry29  );
        auto [sum31, carryOF] = _full_adder(  a &0x80000000u,  b &0x80000000u,  carry30  );


        return    sum0  << 0u
                | sum1  << 1u
                | sum2  << 2u
                | sum3  << 3u
                | sum4  << 4u
                | sum5  << 5u
                | sum6  << 6u
                | sum7  << 7u
                | sum8  << 8u
                | sum9  << 9u
                | sum10 <<10u
                | sum11 <<11u
                | sum12 <<12u
                | sum13 <<13u
                | sum14 <<14u
                | sum15 <<15u
                | sum16 <<16u
                | sum17 <<17u
                | sum18 <<18u
                | sum19 <<19u
                | sum20 <<20u
                | sum21 <<21u
                | sum22 <<22u
                | sum23 <<23u
                | sum24 <<24u
                | sum25 <<25u
                | sum26 <<26u
                | sum27 <<27u
                | sum28 <<28u
                | sum29 <<29u
                | sum30 <<30u
                | sum31 <<31u
                ;
    }

    inline Bus32 _inc32(Bus32 in)
    {
        auto [sum0,  carry0 ] = _half_adder(  in &       0x1u,  1  );
        auto [sum1,  carry1 ] = _half_adder(  in &       0x2u,  carry0   );
        auto [sum2,  carry2 ] = _half_adder(  in &       0x4u,  carry1   );
        auto [sum3,  carry3 ] = _half_adder(  in &       0x8u,  carry2   );
        auto [sum4,  carry4 ] = _half_adder(  in &      0x10u,  carry3   );
        auto [sum5,  carry5 ] = _half_adder(  in &      0x20u,  carry4   );
        auto [sum6,  carry6 ] = _half_adder(  in &      0x40u,  carry5   );
        auto [sum7,  carry7 ] = _half_adder(  in &      0x80u,  carry6   );
        auto [sum8,  carry8 ] = _half_adder(  in &     0x100u,  carry7   );
        auto [sum9,  carry9 ] = _half_adder(  in &     0x200u,  carry8   );
        auto [sum10, carry10] = _half_adder(  in &     0x400u,  carry9   );
        auto [sum11, carry11] = _half_adder(  in &     0x800u,  carry10  );
        auto [sum12, carry12] = _half_adder(  in &    0x1000u,  carry11  );
        auto [sum13, carry13] = _half_adder(  in &    0x2000u,  carry12  );
        auto [sum14, carry14] = _half_adder(  in &    0x4000u,  carry13  );
        auto [sum15, carry15] = _half_adder(  in &    0x8000u,  carry14  );
        auto [sum16, carry16] = _half_adder(  in &   0x10000u,  carry15  );
        auto [sum17, carry17] = _half_adder(  in &   0x20000u,  carry16  );
        auto [sum18, carry18] = _half_adder(  in &   0x40000u,  carry17  );
        auto [sum19, carry19] = _half_adder(  in &   0x80000u,  carry18  );
        auto [sum20, carry20] = _half_adder(  in &  0x100000u,  carry19  );
        auto [sum21, carry21] = _half_adder(  in &  0x200000u,  carry20  );
        auto [sum22, carry22] = _half_adder(  in &  0x400000u,  carry21  );
        auto [sum23, carry23] = _half_adder(  in &  0x800000u,  carry22  );
        auto [sum24, carry24] = _half_adder(  in & 0x1000000u,  carry23  );
        auto [sum25, carry25] = _half_adder(  in & 0x2000000u,  carry24  );
        auto [sum26, carry26] = _half_adder(  in & 0x4000000u,  carry25  );
        auto [sum27, carry27] = _half_adder(  in & 0x8000000u,  carry26  );
        auto [sum28, carry28] = _half_adder(  in &0x10000000u,  carry27  );
        auto [sum29, carry29] = _half_adder(  in &0x20000000u,  carry28  );
        auto [sum30, carry30] = _half_adder(  in &0x40000000u,  carry29  );
        auto [sum31, carryOF] = _half_adder(  in &0x80000000u,  carry30  );

         return   sum0  << 0u
                | sum1  << 1u
                | sum2  << 2u
                | sum3  << 3u
                | sum4  << 4u
                | sum5  << 5u
                | sum6  << 6u
                | sum7  << 7u
                | sum8  << 8u
                | sum9  << 9u
                | sum10 <<10u
                | sum11 <<11u
                | sum12 <<12u
                | sum13 <<13u
                | sum14 <<14u
                | sum15 <<15u
                | sum16 <<16u
                | sum17 <<17u
                | sum18 <<18u
                | sum19 <<19u
                | sum20 <<20u
                | sum21 <<21u
                | sum22 <<22u
                | sum23 <<23u
                | sum24 <<24u
                | sum25 <<25u
                | sum26 <<26u
                | sum27 <<27u
                | sum28 <<28u
                | sum29 <<29u
                | sum30 <<30u
                | sum31 <<31u
                ;
    }
}

#endif //NANDCOMPUTER_ADDERS_HPP
