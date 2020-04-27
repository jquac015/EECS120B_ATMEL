/*	Author: jquac015 
 *	Lab Section: 025
 *	Assignment: Lab 5 Exercise 1
 *	Exercise Description: PC7 should light a "Fasten seatbelt" icon if a key is in the ignition, the driver is seated, but the belt is not fastened.
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRA= 0x00;
	PORTA = 0x00;
	DDRB = 0x00;
	PORTB = 0x00;
	DDRC = 0xFF;
	PORTC = 0x00;
	unsigned char led = 0x00;
	unsigned char temp;
    while (1) {
	    temp = ~PINA & 0x0F;
	if(temp==0x00){
		led = 0x00;
		PORTC = led;
	}
	if(temp==0x01||temp==0x02){
		led = 0x20;
		PORTC = led;
	}
	if(temp==0x03||temp==0x04){
		led = 0x30;
                PORTC = led;
	}
	if(temp==0x05||temp==0x06){
		led = 0x38;
                PORTC = led;
	}
	if(temp>=7 && temp<=9){
		led = 0x3C;
                PORTC = led;
	} 
	if(temp>=10 && temp<=12){
		led = 0x3E;
                PORTC = led;
	} 
	if(temp>=13 && temp<=15){
		led = 0x3F;
                PORTC = led;
	}
	if(temp<=0x04){
                led = led | 0x40;
                PORTC = led;
        }else{
                led = led & 0xBF;
                PORTC = led;
        }
    }
    return 1;
}
