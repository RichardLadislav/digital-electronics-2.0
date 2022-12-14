# Projekt 

### Team members

* David Hromas - kód, dokumentace
* Filip Voch - kód, zapojení
* Richard Ladislav - zapojení, dokumentace

### Table of contents


* [Hardware description](#hardware)
* [Software description](#software)
* [Video](#video)
* [References](#references)





## Hardware description
![Arduino Uno](https://github.com/davidhro/digital-electronics_2/blob/main/Project_1/pictures/Arduino_uno_pinout.png)

### PS2 Joy Stick
Stick je prstom ovládaný modul pozostávajúci z dvoch potenciometrov o veľkosti 10kΩ a jedného tlačidla. Potenciometre indikujú súradnice smeru do ktorého je páčka vychýlená a tlačidlo vysiela low signál
V stave pokoja, keď nie je s Joy Stickom manipulované nadobúda výstupné napätie X i Y hodnotu 2,5V a následným pohybom meníme rozsah odporu potenciometrov v rozsahu 0Ω až 10kΩ, čo mení výstupné napätie modulu v rozmedzí 0V až 5V podľa smeru výchylky. Toto napätie je následne Arduinom interpretované ako celočíselná hodnota pohybujúca sa medi  0 až 1023.

![your figure](https://github.com/davidhro/digital-electronics_2/blob/main/Project_1/pictures/Joystick_pinout.png)
![JoyStickSmerz](https://user-images.githubusercontent.com/99683944/205034556-a86ae40a-1e32-45dd-8896-14e67f004670.png)
![joystickDobre](https://user-images.githubusercontent.com/99683944/205034636-049df2af-aab6-4d67-9917-56e2f35a5b18.png)

### LCD display

![your figure](https://github.com/davidhro/digital-electronics_2/blob/main/Project_1/pictures/LCD_pinout.png)
![LCD_pinout](https://user-images.githubusercontent.com/99683944/205039905-d8dde4cb-79b3-4df0-93b8-fbf0b47b5101.png)



### Finálny pinout projektu

![projekt1_finalPinou](https://user-images.githubusercontent.com/99683944/205702651-b4dd97b1-2299-4d3a-82a2-d01c4f0b3459.png)


## Software description

### Funkce Timer1OVF_vect - spuštění konverze na ADC, přepínání mezi dvěma kanály
 ```c
   static uint8_t channel = 0;
   if (channel == 0)
   {
    ADMUX &= ~((1 << MUX0) | (1 << MUX1) | (1 << MUX2) | (1 << MUX3));
    channel = 1;
   }
   else
   {
    ADMUX &= ~((1 << MUX1) | (1 << MUX2) | (1 << MUX3));
    ADMUX |= (1 << MUX0);
    channel = 0;
   }
    
   // Start ADC conversion
    ADCSRA |= (1 << ADSC);

   ```
![flowchartADMUX](https://user-images.githubusercontent.com/99683944/205927797-109ba625-1778-44eb-b8ba-52f494f3f20b.png)

### Funkce ADC_vect - definování pohybu joysticku
 ```c
    static uint8_t channel = 0;
    uint16_t value;
   
    char string[4];  // String for converted numbers by itoa()
   
    //Cursors, defined as volatile variable
   
    if (channel == 0) //osa x
    {
     value = ADC;
     if (value > 600)
     {
     CursorX++;
     if (CursorX == 2)
     {
       CursorX = 3;
     }
     else if (CursorX == 5)
     {
       CursorX = 6;
     }
     else if (CursorX > 6)
     {
       CursorX = 0;
     }
         
     lcd_gotoxy(CursorX, CursorY);
     }
    else if (value < 400)
    {
     CursorX--;
     if (CursorX == 5)
     {
       CursorX = 4;
     }
     else if (CursorX == 2)
     {
       CursorX = 1;
     }
     else if (CursorX < 0)
     {
       CursorX = 6;
     }
     lcd_gotoxy(CursorX, CursorY);
    }
    else
    {
     lcd_gotoxy(CursorX, CursorY);
    }
     channel = 1;
   }
   else if (channel == 1) //osa y
   {
    value = ADC;
     if (value > 600)
     {
      CursorY != CursorY;
      lcd_gotoxy(CursorX, CursorY);
      }
     else if (value < 400)
     {
     CursorY != CursorY;
     lcd_gotoxy(CursorX, CursorY);
     }
     else
     {
     lcd_gotoxy(CursorX, CursorY);
     }
     channel = 0;
   }
   ```
![flowchartJoystick](https://github.com/davidhro/digital-electronics_2/blob/main/Project_1/pictures/flowchart_adc.png)

### Funkce SetTimer
```c
   if (buttonVal == 0)
    {
       if (CursorX = 0 && CursorY = 0 )
      {
        minutes = minutes + 10;
       
      }
       
       else if (CursorX = 1 && CursorY = 0 )
      {
        minutes ++;
       
      } 
       else if (CursorX = 3 && CursorY = 0 )
      {
        seconds = seconds + 10;
       
      } 
       else if (CursorX = 4 && CursorY = 0 )
      {
        seconds ++;
       
      } 
    }
```
![flowchartSetTimer](https://user-images.githubusercontent.com/99683944/205927833-6f11ed96-a3ac-4330-87e5-f5cb927f9fc3.png)

### Funkce Timer v ISR(Timer1_OVF_vect)
```c
  no_of_overflows++;
    if (no_of_overflows >= 3)
    {
        // Do this every 3 x 33 ms = 100 ms
        no_of_overflows = 0;
        tenths--;
        // Count tenth of seconds 9, 8, ..., 0, 9, 8, ...
        if (tenths = 0)
        {
          tenths = 9;
          seconds--;

          if (seconds = 0)
          {
            seconds = 59;
            minutes--;
            if (minutes = 0)
            {
              tenths = 0;
              seconds = 0;
              minutes = 0;
            }
          }
        }
```
![flowchartTimerCount](https://github.com/davidhro/digital-electronics_2/blob/main/Project_1/pictures/flowchart_timer.png)





## Video


## References

1. http://www.handsontec.com/dataspecs/accessory/PS2-Joystick.pdf
2. https://howtomechatronics.com/tutorials/arduino/rotary-encoder-works-use-arduino/
3. https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf
4. https://docs.arduino.cc/resources/datasheets/A000066-datasheet.pdf
5. https://app.code2flow.com/
6. https://app.diagrams.net/
