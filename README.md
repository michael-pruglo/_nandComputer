# _nand computer
Creating a computer from the very first principles - both software and hardware. <p>
All the computation is based on the chip Nand. <p>
Based on [Nand2Tetris](https://www.nand2tetris.org/) <p>

## Hardware
Currently implemented chips: <p>
`BasicGates`: Nand, Not, And, Or, Xor, Mux, DMux, IsZero, IsNZero as well as their multi-bit and multi-way versions.<p>
`Adders`: Half adder, Full adder, Add32, Inc32.
`ALU`: Arithmetical Logical Unit

## Testing
Correctness is tested using Google Tests. <p>
![current results](docs/assets/gtests_screenshot.JPG) <p>
Performance is tested using Google Benchmark. <p>
![current results](docs/assets/gbenchmark_screenshot.JPG) <p>