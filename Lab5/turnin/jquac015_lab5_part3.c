/*	Author: Justin Quach jquac015@ucr.edu
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab 5  Exercise 2
 *	Exercise Description: Increment and decrement with PA0 and PA1 respectively, reset with both
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

enum Light_States{Start, First, FirstW, Sec, SecW, Thr, ThrW}Light_State;

void LightSM(){
	switch(Light_State){
		case Start:
			Light_State = First;
			break;
		case FirstW:
			if(PINA & 0x01){
				Light_State = First;
			}else{
				Light_State = FirstW;
			}
			break;
		case First:
			if(~PINA & 0x01){
				Light_State = SecW;
			}else{
				Light_State = First;
			}
			break;
		case SecW:
			if(PINA & 0x01){
				Light_State = Sec;
			}else{
				Light_State = SecW;
			}
			break;
		case Sec:
			if(~PINA & 0x01){
				Light_State = ThrW;
			}else{
				Light_State = Sec;
			}
			break;
		case ThrW:
			if(PINA & 0x01){
				Light_State = Thr;
			}else{
				Light_State = ThrW;
			}
			break;
		case Thr:
			if(~PINA & 0x01){
				Light_State = FirstW;
			}else{
				Light_State = Thr;
			}
			break;
		default:
			Light_State = Start;
			break;
	}
	switch(Light_State){
		case FirstW:
			PORTC = 0x36;
			break;
		case First:
			PORTC = 0x36;
			break;
		case SecW:
			PORTC = 0x1B;
			break;
		case Sec:
			PORTC = 0x1B;
			break;
		case ThrW:
			PORTC = 0x2D;
			break;
		case Thr:
			PORTC = 0x2D;
			break;
		default:
			break;
	}
}

int main(void) {
	DDRB = 0x00;
	PORTB = 0x00;
	DDRC = 0xFF;
	PORTC = 0x00;
	Light_State = Start;
    while (1) {
	LightSM();
    }
    return 0;
}
