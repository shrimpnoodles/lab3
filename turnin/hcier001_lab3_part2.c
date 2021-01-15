/*	Author: hcier001
 *  Partner(s) Name: nona
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b){
	return (b ? (x| (0x01<<k)) : (x & ~(0x01 << k)) );
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA= 0x00; PORTA =0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char fuel = 0x00;
	unsigned char temp = 0x00;
    /* Insert your solution below */
    while (1) {
	fuel = PINA;
	if(fuel ==0x01 || fuel==0x02){
		SetBit(temp, 5, 1);
		SetBit(temp, 6, 1); //gas light
	}
	if(fuel ==0x03 || fuel ==0x04){
		SetBit(temp, 5, 1);
		SetBit(temp, 4, 1);
		SetBit(temp, 6, 1);
	}
	if(fuel ==0x05 || fuel ==0x06){
		SetBit(temp, 6, 0); //gas light off
		SetBit(temp, 5, 1);
		SetBit(temp, 4, 1);
		SetBit(temp, 3, 1);
	}
	if(fuel ==0x07 || fuel ==0x08 || fuel == 0x09){
		SetBit(temp, 6, 0); //gas light off
		SetBit(temp, 5, 1);
		SetBit(temp, 4, 1);
		SetBit(temp, 3, 1);
		SetBit(temp, 2, 1);
	}
	if(fuel ==0x0A || fuel ==0x0B || fuel == 0x0C){
		SetBit(temp, 6, 0); //gas light off
		SetBit(temp, 5, 1);
		SetBit(temp, 4, 1);
		SetBit(temp, 3, 1);
		SetBit(temp, 2, 1);
		SetBit(temp, 1, 1);
	}
	if(fuel ==0x0D || fuel ==0x0E || fuel == 0x0F){
		SetBit(temp, 6, 0); //gas light off
		SetBit(temp, 5, 1);
		SetBit(temp, 4, 1);
		SetBit(temp, 3, 1);
		SetBit(temp, 2, 1);
		SetBit(temp, 1, 1);
		SetBit(temp, 0, 1);
	}
	PORTC = temp;
	temp = 0x00;
	
}

	 
    
    return 1;
}
