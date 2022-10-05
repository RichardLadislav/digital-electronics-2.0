/***********************************************************************
 * 
 * Blink a LED in Arduino-style and use function from the delay library.
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2022 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/


/* Defines -----------------------------------------------------------*/
#define LED_GREEN PB5   // PB5 is AVR pin where green on-board LED 
#define LED_BLUE PB0                        
                        // is connected
<<<<<<< HEAD:Lab-1-blink/src/main.cpp
#define SHORT_DELAY 250 // Delay in milliseconds
#define EXTRA_SHORT_DELAY 100
#define LONG_DELAY 700
=======
#define DOT_DELAY 250 // Delay in milliseconds
#define DASH_DELAY 250
#define INTER_DELAY 250

>>>>>>> 74e1d09923bfab6f0b54e0e571f096cd2a57d23f:LAV1-BLINK_ARDUINO/src/main.cpp
#ifndef F_CPU
# define F_CPU 16000000 // CPU frequency in Hz required for delay funcs
#endif

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>     // AVR device-specific IO definitions
#include <util/delay.h> // Functions for busy-wait delay loops


// -----
// This part is needed to use Arduino functions but also physical pin
// names. We are using Arduino-style just to simplify the first lab.
#include "Arduino.h"
#define PB5 13          // In Arduino world, PB5 is called "13"
// -----
#define PB0 8

/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Toggle one LED and use delay library.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    uint8_t led_value = LOW;  // Local variable to keep LED status

    // Set pin where on-board LED is connected as output
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);

    // Infinite loop
    while (1)
    {
        /

        // Pause several milliseconds
<<<<<<< HEAD:Lab-1-blink/src/main.cpp
        _delay_ms(100);
        // Turn ON/OFF on-board LED
            digitalWrite(LED_GREEN, led_value);
            digitalWrite(LED_BLUE, led_value);
        _delay_ms(100);

        
        // Turn ON/OFF on-board LED
            digitalWrite(LED_GREEN, led_value);
            digitalWrite(LED_BLUE, led_value);
        _delay_ms(250);

         
        // Turn ON/OFF on-board LED
            digitalWrite(LED_GREEN, led_value);
            digitalWrite(LED_BLUE, led_value);
        _delay_ms(500);

         
        // Turn ON/OFF on-board LED
            digitalWrite(LED_GREEN, led_value);
            digitalWrite(LED_BLUE, led_value);
        _delay_ms(100);




=======
        _delay_ms(INTER_DELAY);
        
        digitalWrite(LED_GREEN, led_value);

         _delay_ms(SHORT_DELAY);

        digitalWrite(LED_GREEN, led_value);
          
          _delay_ms(INTER_DELAY);

        digitalWrite(LED_GREEN, led_value);
          
           


        
>>>>>>> 74e1d09923bfab6f0b54e0e571f096cd2a57d23f:LAV1-BLINK_ARDUINO/src/main.cpp
    }

    // Will never reach this
    return 0;
};