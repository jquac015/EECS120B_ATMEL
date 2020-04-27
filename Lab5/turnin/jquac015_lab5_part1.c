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
    while (1) {
	if(PINA==0x00){
		led = 0x00;
	}
	if(PINA==0x01||PINA==0x02){
		led = 0x20;
	}
	if(PINA==0x03||PINA==0x04){
		led = 0x30;
	}
	if(PINA==0x05||PINA==0x06){
		led = 0x38;
	}
	if(PINA>=7 && PINA<=9){
		led = 0x3C;
	} 
	if(PINA>=10 && PINA<=12){
		led = 0x3E;
	} 
	if(PINA>=13 && PINA<=15){
		led = 0x3F;
	}
	if(PINA<=0x04){
                led = led | 0x40;
        }else{
                led = led & 0xBF;
        }

	PORTC = led;
    }
    return 1;
}
