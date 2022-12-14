# Lab 6: RICHARD LADISLAV

### ASCII

1. Complete the table with selected ASCII codes.

   | **Char** | **Decimal** | **Hexadecimal** | **Binary** |
   | :-: | :-: | :-: | :-: |
   | `a` | 97 | 0x61 | `0b0110_0001` |
   | `b` | 98 | 62 | `0b0110_0010` |
   | `c` | 99 | 63 | `0b0110_0011` |
   | `0` | 48 | 0x30 | `0b0011_0000` |
   | `1` | 13 | d | `0b0011_0001` |
   | `2` | 50 | 32 | `0b0011_0010` |
   | `Esc` | 27 | 1b | `0b0001_1011` |
   | `Space` | 32 | 20 | `0b0010_0000` |
   | `Tab` | 9	 | 9 | `0b0000_1001` |
   | `Backspace` | 127 | 7f | `0b0000_1000` |
   | `Enter` | 13 | d | `0b0000_1101` |

### UART communication

2. Draw timing diagram of the output from UART/USART when transmitting three character data `De2` in 4800 7O2 mode (7 data bits, odd parity, 2 stop bits, 4800&nbsp;Bd). The image can be drawn on a computer or by hand. Name all parts timing diagram.

   ![UART_timingDiagram](https://user-images.githubusercontent.com/99683944/200620166-aab65b0b-1e6f-46ea-a92c-b3a7a039871b.png)



3. Draw a flowchart for function `uint8_t get_parity(uint8_t data, uint8_t type)` which calculates a parity bit of input 8-bit `data` according to parameter `type`. The image can be drawn on a computer or by hand. Use clear descriptions of individual algorithm steps.

   ![UART_flowchart](https://user-images.githubusercontent.com/99683944/200625988-42de55ad-737b-4113-ada3-dd47e426ee2c.png)

