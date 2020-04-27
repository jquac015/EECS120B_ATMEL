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
unsigned char temp;

void LightSM(){
	switch(Light_State){
		case Start:
			Light_State = First;
			break;
		case FirstW:
			if(temp==0x00){
				Light_State = First;
			}else{
				Light_State = FirstW;
			}
			break;
		case First:
			if(temp==0x01){
				Light_State = SecW;
			}else{
				Light_State = First;
			}
			break;
		case SecW:
			if(temp==0x00){
				Light_State = Sec;
			}else{
				Light_State = SecW;
			}
			break;
		case Sec:
			if(temp==0x01){
				Light_State = ThrW;
			}else{
				Light_State = Sec;
			}
			break;
		case ThrW:
			if(temp==0x00){
				Light_State = Thr;
			}else{
				Light_State = ThrW;
			}
			break;
		case Thr:
			if(temp==0x01){
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
		case Start:
			temp = ~PINA&0x01;
		case FirstW:
			temp = ~PINA&0x01;
			PORTC = 0x36;
			break;
		case First:
			temp = ~PINA&0x01;
			PORTC = 0x36;
			break;
		case SecW:
			temp = ~PINA&0x01;
			PORTC = 0x1B;
			break;
		case Sec:
			temp = ~PINA&0x01;
			PORTC = 0x1B;
			break;
		case ThrW:
			temp = ~PINA&0x01;
			PORTC = 0x2D;
			break;
		case Thr:
			temp = ~PINA&0x01;
			PORTC = 0x2D;
			break;
		default:
			temp = ~PINA&0x01;
			break;
	}
}

int main(void) {
	DDRA = 0x00;
	PORTA = 0xFF;
	DDRC = 0xFF;
	PORTC = 0x00;
	Light_State = Start;
    while (1) {
	LightSM();
    }
    return 0;
}
