# Lab 1: RICHARD LADISLAV

### Morse code

1. Listing of C code which repeats one "dot" and one "comma" (BTW, in Morse code it is letter `A`) on a LED. Always use syntax highlighting, meaningful comments, and follow C guidelines:

```c
int main(void)
{

#define SHORT_DELAY 250 // Delay in milliseconds
#define LONG_DELAY 750
#define INTER_LETTER_DELAY 1750

    // Set pin where on-board LED is connected as output
    pinMode(LED_GREEN, OUTPUT);

    // Infinite loop
    while (1)
    {
         // Generate a lettre `A` Morse code

        // WRITE YOUR CODE HERE

	 digitalWrite(LED_GREEN, HIGH);

         _delay_ms(SHORT_DELAY);

        digitalWrite(LED_GREEN, LOW);
          
          _delay_ms(LONG_DELAY);

        digitalWrite(LED_GREEN, HIGH);

        _delay_ms(LONG_DELAY);
          
        digitalWrite(LED_GREEN, LOW);   

        _delay_ms(SHORT_DELAY);

        _delay_ms(INTER_LETTER_DELAY);

    }

    // Will never reach this
    return 0;
}
```

2. Scheme of Morse code application, i.e. connection of AVR device, LED, resistor, and supply voltage. The image can be drawn on a computer or by hand. Always name all components and their values!

   ![BLINK_obvod](https://user-images.githubusercontent.com/99683944/193917260-c92d662a-62b1-450b-a0c8-65a24f94c567.png)

