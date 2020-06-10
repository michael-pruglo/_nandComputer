# _nand computer
Creating a computer from the very first principles - both software and hardware. <p>
All the computation is based on the chip Nand. <p>
Based on [Nand2Tetris](https://www.nand2tetris.org/) <p>

## Hardware
Currently the most basic chips are implemented: Nand, Not, And, Or, Xor, Mux, DMux as well as their multi-bit and multi-way versions.
The implementation is in the class `LogicGates`. <p>
Testing capacities are provided as well - in form of the class `TestLogicGates`.
There are 2 parameters: `RANDOM_AMOUNT_N`, which specifies how thoroughly the functions are tested (higher = more tests),
and `EXHAUSTIVE_TIME_N`, which allows to measure time more precisely (higher = more precise).<p>
Current results: <p>
```
TestLogicGates::full scan:
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
====TestLogicGates::full scan finished====
    # of tests passed: 17
```
