# _nand computer
Creating a computer from the very first principles - both software and hardware. <p>
All the computation is based on the chip Nand. <p>
Based on [Nand2Tetris](https://www.nand2tetris.org/) <p>

## Hardware
Currently implemented 
- `Hardware::BasicGates` - Not, And, Or, Xor etc.
- `Hardware::Adders` - HalfAdder, FullAdder etc.
- `Hardware::ALU` - Arithmetical Logical Unit
- `Hardware::SequentialChips` - FlipFlops, Register, RAM, Counter etc.
<p>
The list of the implemented chips and their performance can be found below.

## Testing
Correctness is tested using Google Tests. <p>
![current results](docs/assets/gtests_screenshot.JPG) <p>
Performance is tested using Google Benchmark. <p>

```
---------------------------------------------------------
Benchmark                                         Time 
---------------------------------------------------------
BasicGates_nand                                  2.80 ns 
BasicGates_nand_v2                               3.07 ns 
BasicGates_nand3way                              3.35 ns 
BasicGates_nand_v3                               3.46 ns 
BasicGates_not                                   4    ns 
BasicGates_and                                   6.6  ns 
BasicGates_or                                    8.1  ns 
BasicGates_xor                                  10.5  ns 
BasicGates_mux                                  10.3  ns 
BasicGates_xnor                                 13.9  ns 
BasicGates_dmux                                 16.8  ns 
BasicGates_and8way                              52.4  ns 
BasicGates_or8way                               55.4  ns 
BasicGates_dmux4way                             69    ns 
BasicGates_not32                               121    ns 
BasicGates_dmux8way                            175    ns 
BasicGates_and32                               212    ns 
BasicGates_is_nzero32                          234    ns 
BasicGates_is_zero32                           239    ns 
BasicGates_or32                                261    ns 
BasicGates_mux32                               329    ns 
BasicGates_mux4way32                           980    ns 
BasicGates_mux8way32                         2'300    ns 
                                            
Adders_half_adder                               13    ns 
Adders_full_adder                               23    ns 
Adders_inc32                                   816    ns 
Adders_add32                                 1'140    ns 
                                            
ALU_neg_if32                                   332    ns 
ALU_prepare32                                  332    ns 
ALU_alu                                      2'740    ns  
                                            
SequentialChips_bit_read                         3.65 ns 
SequentialChips_dff                             20.6  ns 
SequentialChips_bit_write                       60    ns 
SequentialChips_register32_read                185    ns 
SequentialChips_counter32_read                 187    ns  
SequentialChips_register32_write             1'970    ns       
SequentialChips_counter32                    3'988    ns  

SequentialChips_RAM8_read                    3'793    ns  
SequentialChips_RAM8_write                  18'287    ns  
SequentialChips_RAM64_read                  32'802    ns  
SequentialChips_RAM64_write                149'330    ns  
SequentialChips_RAM512_read                266'083    ns  
SequentialChips_RAM512_write             1'201'081    ns  
SequentialChips_RAM4096_read             2'119'522    ns  
SequentialChips_RAM4096_write            9'588'255    ns  
SequentialChips_RAM32768_read           17'076'489    ns  
SequentialChips_RAM32768_write          76'573'758    ns  
```
