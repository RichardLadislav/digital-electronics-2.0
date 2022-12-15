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
V projekte využívame phase correct PWM (pulse width modulation), ktorá je bežne využívaná na ovládanie servo motorov.


## Software description

### Funkce Timer1OVF_vect
 ```c
  ISR(TIMER0_OVF_vect)
{
    static uint8_t servo_x_step = 0;        
    static uint8_t servo_y_step = 0;
    static uint8_t increment = 1;   

    if (servo_x == POSITION_1)      
      {
        servo_x_step = 1;           
      }
    else if (servo_x == POSITION_2) 
      {
        servo_x_step = 0;          
      }
       
    if (servo_x_step == 0)
      {
        servo_x += increment;              
      }
        
    if (servo_x_step == 1)
      {
        servo_x -= increment;               
      }
    OCR1A = servo_x;                
       
      
    if (servo_y == POSITION_1)      
      {
        servo_y_step = 1;              
      }
    else if (servo_y == POSITION_2) 
      {
        servo_y_step = 0;               
      }
       
    if (servo_y_step == 0)
      {
        servo_y += increment + 1;               
      }

    if (servo_y_step == 1)
      {
        servo_y -= increment + 1;                
      }
    OCR1B = servo_y;                  
}

   ```
![FlowServopdf-1](https://user-images.githubusercontent.com/99683944/207745250-ad46fee8-b30d-4fe5-8392-23e8b9112708.png)


## Video


## References

1. https://navody.dratek.cz/arduino-projekty/servo-motor.htm
2. https://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-7810-Automotive-Microcontrollers-ATmega328P_Datasheet.pdf
3. https://www.ee-diary.com/2021/07/phase-correct-pwm-with-atmega328p.html?fbclid=IwAR24t4myL5OQH8FrCGZd9OGGwccg384H3I16n2MI2PBwJB_tLiVsiZRMhus
4. https://docs.arduino.cc/resources/datasheets/A000066-datasheet.pdf
5. https://app.code2flow.com/
6. https://app.diagrams.net/
