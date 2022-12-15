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

### Servo motor
Servomotry slúžia na nastavenie určitej polohy ovládaného mechanizmu a následné udržanie v tejto polohe. Jednosmerné servo motory môžeme často nájsť vo využitiach, 
ako ovládanie robotických paží. Jednou z ich najväčších vyćhod je pomer veľkosti a hmotnosti ku sile, ktorú sú schopné vyvinúť. V obvyklom prevedení servo motor neumožňuje otáčanie o celých 360 stupňov, ale v rozsahu 0 až 180 stupňov. Uhol natočenia sa nastavuje zaslaním impilzu o určitej dĺžke. Pre 90 stupńov 1,5ms, pre 0 stupňov 0,5ms a pre 180 stupňov 2,5ms.

![servoUhly](https://user-images.githubusercontent.com/99683944/207743354-10b85f20-140b-4f68-8533-12b71b546de2.png)

#### Pinout Servomotora
Bežný servo motor má obvykle tri vstupy. GND pripájame na zem Vcc na +5V pin Arduino dosky a tretí väčšinou žltej farby na Arduino pin so schopnosťou vysielania 
PMW signálu. Na obrázku nižšie môžeme nájsť finálny pinout nášho projektu s dvomi zapojenými servo motormi.

![servoPinout](https://user-images.githubusercontent.com/99683944/207743430-bc56773f-a3f6-486a-81e7-b2ed7d31006d.png)

### PWM 



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

1. [http://www.handsontec.com/dataspecs/accessory/PS2-Joystick.pdf](https://navody.dratek.cz/arduino-projekty/servo-motor.html)
2. https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf
3. https://www.ee-diary.com/2021/07/phase-correct-pwm-with-atmega328p.html?fbclid=IwAR24t4myL5OQH8FrCGZd9OGGwccg384H3I16n2MI2PBwJB_tLiVsiZRMhus
4. https://docs.arduino.cc/resources/datasheets/A000066-datasheet.pdf
5. https://app.code2flow.com/
6. https://app.diagrams.net/
