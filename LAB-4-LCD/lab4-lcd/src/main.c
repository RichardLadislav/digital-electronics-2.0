/***********************************************************************
 * 
 * Stopwatch by Timer/Counter2 on the Liquid Crystal Display (LCD)
 *
 * ATmega328P (Arduino Uno), 16 MHz, PlatformIO
 *
 * Copyright (c) 2017 Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 * Components:
 *   16x2 character LCD with parallel interface
 *     VSS  - GND (Power supply ground)
 *     VDD  - +5V (Positive power supply)
 *     Vo   - (Contrast)
 *     RS   - PB0 (Register Select: High for Data transfer, Low for Instruction transfer)
 *     RW   - GND (Read/Write signal: High for Read mode, Low for Write mode)
 *     E    - PB1 (Read/Write Enable: High for Read, falling edge writes data to LCD)
 *     D3:0 - NC (Data bits 3..0, Not Connected)
 *     D4   - PD4 (Data bit 4)
 *     D5   - PD5 (Data bit 5)
 *     D6   - PD6 (Data bit 3)
 *     D7   - PD7 (Data bit 2)
 *     A+K  - Back-light enabled/disabled by PB2
 * 
 **********************************************************************/

/* Includes ----------------------------------------------------------*/
#include <avr/io.h>         // AVR device-specific IO definitions
#include <avr/interrupt.h>  // Interrupts standard C library for AVR-GCC
#include <gpio.h>           // GPIO library for AVR-GCC
#include "timer.h"          // Timer library for AVR-GCC
#include <lcd.h>            // Peter Fleury's LCD library
#include <stdlib.h>         // C library. Needed for number conversions


/* Function definitions ----------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Update stopwatch value on LCD screen when 8-bit 
 *           Timer/Counter2 overflows.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Initialize display
    lcd_init(LCD_DISP_ON_CURSOR_BLINK);
    TIM2_overflow_4ms();
    TIM2_overflow_interrupt_enable();

   uint8_t customChar[] = {

    // addr 1: |....
    0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000,
    // addr 2: |....
    0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 0b11000, 0b11000,
    // addr 3: |....
    0b11100, 0b11100, 0b11100, 0b11100, 0b11100, 0b11100, 0b11100, 0b11100,
    // addr 4: |....
    0b11110, 0b11110, 0b11110, 0b11110, 0b11110, 0b11110, 0b11110, 0b11110,
    // addr 5: |....
    0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111, 0b11111
  

   };
    sei();

    // Infinite loop
    while (1)
    {
        /* Empty loop. All subsequent operations are performed exclusively 
         * inside interrupt service routines, ISRs */
    }

    // Will never reach this
    return 0;
}


/* Interrupt service routines ----------------------------------------*/
/**********************************************************************
 * Function: Timer/Counter2 overflow interrupt
 * Purpose:  Update the stopwatch on LCD screen every sixth overflow,
 *           ie approximately every 100 ms (6 x 16 ms = 100 ms).
 **********************************************************************/
ISR(TIMER2_OVF_vect)
{
    static uint8_t no_of_overflows = 0;
    static uint8_t tenths = 0; 
    static uint8_t seconds = 0; 
    static uint8_t minutes = 0;  // Tenths of a second
    char string[2];             // String for converted numbers by itoa()

    no_of_overflows++;
    if (no_of_overflows >= 3)
    {
        // Do this every 6 x 16 ms = 100 ms
        no_of_overflows = 0;
        tenths++;
          if(tenths > 9)
            {
              tenths=0;
              seconds++;

                if(seconds>59)
                {
                  seconds=0;
                  minutes++;
                }
            }
        // Count tenth of seconds 0, 1, ..., 9, 0, 1, ...


        
        
                                               
        itoa(minutes, string, 10);    // Convert decimal value to string                                  
       // lcd_gotoxy(9, 0);           // lcd_puts(tenths);// Display "00:00.tenths"
        lcd_puts(string);
        //lcd_gotoxy(8,0);
         lcd_putc(':');
        itoa(seconds, string, 10);
        
        //lcd_gotoxy(7,0);
         lcd_puts(string);
        // lcd_gotoxy(5,0);
         lcd_putc('.');
        
         itoa(tenths, string, 10);
       
        
        //lcd_gotoxy(4, 0);
        lcd_puts(string);
        lcd_gotoxy(1, 0);
        
      
       

    }
    // Else do nothing and exit the ISR

    ISR(TIMER2_OVF_vect)
    
{
    static uint8_t symbol = 0;
    static uint8_t position = 0;
    static uint8_t n_of_overflows = 0;

    n_of_overflows++;
    if (n_of_overflows >= 5)
    {
        // Do this every 6 x 16 ms = 100 ms
        n_of_overflows = 0;
        posistion++;
          if (position > 5)
          {
            positon = 0;
            symbol++

              if (symbol>10)
              {
                symbol = 0;
              }
              
          }
          
          
        

    lcd_gotoxy(1+position, 1);
    lcd_putc(symbol);

    // WRITE YOUR CODE HERE
}
}