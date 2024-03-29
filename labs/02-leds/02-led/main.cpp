/***********************************************************************
 * 
 * Alternately toggle two LEDs when a push button is pressed.
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 * Copyright (c) 2018-Present Tomas Fryza
 * Dept. of Radio Electronics, Brno University of Technology, Czechia
 * This work is licensed under the terms of the MIT license.
 * 
 **********************************************************************/

/* Defines -----------------------------------------------------------*/
#define LED_GREEN   PC0
#define LED_2   PB5
#define PBUTTON   PD2         // AVR pin where green LED is connected
#define BLINK_DELAY 500
#ifndef F_CPU
# define F_CPU 16000000     // CPU frequency in Hz required for delay
#endif

/* Includes ----------------------------------------------------------*/
#include <util/delay.h>     // Functions for busy-wait delay loops
#include <avr/io.h>
#include <avr/sfr_defs.h>         // AVR device-specific IO definitions

/* Functions ---------------------------------------------------------*/
/**********************************************************************
 * Function: Main function where the program execution begins
 * Purpose:  Toggle two LEDs when a push button is pressed.
 * Returns:  none
 **********************************************************************/
int main(void)
{
    // Green LED at port B
    // Set pin as output in Data Direction Register...
    DDRC = DDRC | (1<<LED_GREEN);
    // ...and turn LED off in Data Register
    PORTC = PORTC & ~(1<<LED_GREEN);
    

    // Configure the second LED at port C
    DDRB = DDRB | (1<<LED_2);
    // ...and turn LED off in Data Register
    PORTB = PORTB & ~(1<<LED_2);
    
        // Configure the second LED at port C
    DDRD = DDRD | (0<<PBUTTON);
        // ...and turn LED off in Data Register
    PORTD = PORTD & ~(1<<PBUTTON);

    // Configure Push button at port D and enable internal pull-up resistor
    PORTC = PORTC ^ (1<<LED_GREEN);
    // Infinite loop
    while (1)
    {
        // Pause several milliseconds
        if(bit_is_clear(PIND,PBUTTON)){
            PORTC = PORTC ^ (1<<LED_GREEN);
            
        }
       
        // WRITE YOUR CODE HERE
    }

    // Will never reach this
    return 0;
}