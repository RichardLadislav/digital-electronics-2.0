# Lab 8: INSERT_YOUR_FIRSTNAME INSERT_YOUR_LASTNAME

### Instruction set

1. Complete the conversion table with selected instructions:

   | **Instruction** | **Binary opcode** | **Hex opcode** | **Compiler Hex opcode** |
   | :-- | :-: | :-: | :-: |
   | `add r24, r0` | 0b0000_1101_1000_0000 |  | 80 0d |
   | `com r26` | 0b1001_0101_1010_000 |  | 90 95 |
   | `eor r26, r27` | 0b0010_0111_1010_1011 |  | aa 27 |
   | `mul r22, r20` |  |  | 64 9f |
   | `ret` | `1001_0101_0000_1000` | `95 08` |  |

### 4-bit LFSR

2. Complete table with 4-bit LFSR values for different Tap positions:

   | **Tap position** | **Generated values** | **Length** |
   | :-: | :-- | :-: |
   | 4, 3 | 1 3 7 14 13 11 6 12 9 2 5 10 4 8 0 | 15 |
   | 4, 2 | 1 3 6 12 8 0  | 6 |
   | 4, 1 | 1 2 5 10 4 9 3 6 13 11 7 14 12 8 0 | 15 |

### Variable number of short pulses

3. Draw a flowchart of function `void burst_c(uint8_t number)` which generates a variable number of short pulses at output pin. Let the pulse width be the shortest one. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

   ![your figure]()