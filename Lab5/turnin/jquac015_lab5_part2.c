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

enum Counter_States{Start, STANDBY, INC, DEC, INC_WAIT, DEC_WAIT, RESET}Counter_State;
unsigned char temp;

void CounterSM(){
	switch(Counter_State){
		case Start:
			PORTC = 0x00;
			temp = ~PINA & 0x03;
			Counter_State = STANDBY;
			break;
		case STANDBY:
			if(temp==0x03){
				Counter_State = RESET;
			}else if((temp&0x02) && (PINC>0)){
				Counter_State = DEC;
			}else if((temp&0x01) && (PINC<9)){
				Counter_State = INC;
			}else{
				Counter_State = STANDBY;
			}
			break;
		case INC:
			Counter_State = INC_WAIT;
			break;
		case DEC:
			Counter_State = DEC_WAIT;
			break;
		case INC_WAIT:
			if(temp==0x03){
				Counter_State = RESET;
			}else if(temp == 0x00){
				Counter_State = STANDBY;
			}else{
				Counter_State = INC_WAIT;
			}
			break;
		case DEC_WAIT:
			if(temp == 0x03){
				Counter_State = RESET;
			}else if(temp == 0x00){
				Counter_State = STANDBY;
			}else{
				Counter_State = DEC_WAIT;
			}
			break;
		case RESET:
			if(temp == 0x00){
				Counter_State = STANDBY;
			}else{
				Counter_State = RESET;
			}
			break;
		default:
			Counter_State = Start;
			break;
	}
	switch(Counter_State){
		case Start:
			temp = ~PINA & 0x03;
			PORTC = 0x00;
			break;
		case STANDBY:
			temp = ~PINA & 0x03;
			break;
		case INC:
			temp = ~PINA & 0x03;
			PORTC = PINC+1;
			break;
		case DEC:
			temp = ~PINA & 0x03;
			PORTC = PINC-1;
			break;
		case INC_WAIT:
			temp = ~PINA & 0x03;
			break;
		case DEC_WAIT:
			temp = ~PINA & 0x03;
			break;
		case RESET:
			temp = ~PINA & 0x03;
			PORTC = 0x00;
			break;
		default:
			temp = ~PINA & 0x03;
			break;
	}
}

int main(void) {
	DDRA = 0x00;
	PORTA = 0xFF;
	DDRC = 0xFF;
	PORTC = 0x00;
	Counter_State = Start;
    while (1) {
	CounterSM();
    }
    return 0;
}
