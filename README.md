# _nand computer
Creating a computer from the very first principles - both software and hardware. <p>
All the computation is based on the chip Nand. <p>
Based on [Nand2Tetris](https://www.nand2tetris.org/) <p>

## Hardware
Currently implemented chips: <p>
`BasicGates`: Nand, Not, And, Or, Xor, Mux, DMux as well as their multi-bit and multi-way versions.<p>
`Adders`: Half adder, Full adder, Add32.

Testing capacities are provided as well.
There are 2 parameters: `RANDOM_AMOUNT_N`, which specifies how thoroughly the functions are tested (higher = more tests),
and `EXHAUSTIVE_TIME_N`, which allows to measure time more precisely (higher = more precise).<p>

Current results: <p>
```
TestBasicGates::full scan:
        testing _nand: OK.      testing time:         52 ns
        testing _not: OK.       testing time:         54 ns
        testing _and: OK.       testing time:         56 ns
        testing _or: OK.        testing time:         61 ns
        testing _xor: OK.       testing time:         71 ns
        testing _mux: OK.       testing time:         64 ns
        testing _dmux: OK.      testing time:         68 ns
        testing _not32: OK.     testing time:        166 ns
        testing _and32: OK.     testing time:        293 ns
        testing _or32: OK.      testing time:        397 ns
        testing _mux32: OK.     testing time:        423 ns
        testing _and8way: OK.   testing time:        112 ns
        testing _or8way: OK.    testing time:        120 ns
        testing _mux4way32: OK. testing time:       1174 ns
        testing _mux8way32: OK. testing time:       2670 ns
        testing _dmux4way: OK.  testing time:        128 ns
        testing _dmux8way: OK.  testing time:        251 ns
====TestBasicGates::full scan finished====
    # of tests passed: 17
```
```
TestAdders::full scan:
        testing _half_adder: OK.testing time:         90 ns
        testing _full_adder:
                v1:  OK.        testing time:        131 ns
                v2:  OK.        testing time:        130 ns
        testing _add32:
                v1:  OK.        testing time:       2785 ns
====TestAdders::full scan finished====
    # of tests passed: 3
```
