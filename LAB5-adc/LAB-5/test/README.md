
T# Lab 5: INSERT_YOUR_FIRSTNAME INSERT_YOUR_LASTNAME

### Analog-to-Digital Conversion

1. Complete table with voltage divider, calculated, and measured ADC values for all five push buttons.

   | **Push button** | **PC0[A0] voltage** | **ADC value (calculated)** | **ADC value (measured)** | **ADC value (measured, hex)** |
   | :-: | :-: | :-: | :-: | :-: |
   | Right  | 0&nbsp;V | 0   | 0 | 0 |
   | Up     | 0.495&nbsp;V | 101 | 99 | 63 |
   | Down   | 1.203&nbsp;V | 246 | 256 | 100 |
   | Left   | 1.97&nbsp;V | 409 | 409 | 199 |
   | Select | 3.182&nbsp;V | 651 | 640 | 280 |
   | none   | 5&nbsp;V | 1023 | 1023 | 3ff |

### Temperature meter

Consider an application for temperature measurement. Use analog temperature sensor [TC1046](http://ww1.microchip.com/downloads/en/DeviceDoc/21496C.pdf), LCD, and a LED. Every 30 seconds, the temperature is measured and the value is displayed on LCD screen. When the temperature is too high, the LED will turn on.

2. Draw a schematic of temperature meter. The image can be drawn on a computer or by hand. Always name all components and their values.

![Temperature converter](https://user-images.githubusercontent.com/99683944/199312685-57dddc11-41ce-4e43-8389-1904db8f46ae.png)

3. Draw two flowcharts for interrupt handler `TIMER1_OVF_vect` (which overflows every 1&nbsp;sec) and `ADC_vect`. The image can be drawn on a computer or by hand. Use clear descriptions of the individual steps of the algorithms.

  ![temperature flowchart](https://user-images.githubusercontent.com/99683944/199312536-eb8bdd2f-7d68-4c42-90ff-2bc601086dff.png)

  ![TIMERoverflow](https://user-images.githubusercontent.com/99683944/199312576-458bc754-0ca6-4a8d-a526-601aa3a59b1d.png)
