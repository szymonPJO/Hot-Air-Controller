/*
 * oled.c
 *
 *  Created on: 9 pa� 2019
 *      Author: Szymonp
 */

#include "lcd.h"

#include <avr/io.h>
#include <util/delay.h>

#define portDB PORTD
#define ddrDB DDRD
#define pinDB PIND
#define port3 PORTC
#define ddr3 DDRC
#define pin3 PINC

void OLEDinstr_clear(){
	ddrDB |= 0b1111;
	port3 &= ~(_BV(RS)|_BV(RW));
	port3 |= _BV(E);
	portDB &= ~0b1111;	//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b0001;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
}

void OLEDinstr_home(){
	ddrDB |= 0b1111;
	port3 &= ~(_BV(RS)|_BV(RW));
	port3 |= _BV(E);
	portDB &= ~0b1111;	//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b0010;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
}

void OLED_GPIOinit(){//set we/wy
	ddr3 |= (_BV(RS)|_BV(RW)|_BV(E)); //set RS,RW,E and onboard smdLED
	ddrDB |= 0b1111;
	portDB &= ~0b1111;
	port3 &= ~(_BV(RS)|_BV(RW)|_BV(E));
}

void OLED_GPIOoff(){//set we/wy
	ddr3 &= ~(_BV(RS)|_BV(RW)|_BV(E)); //set RS,RW,E and onboard smdLED
	port3 &= ~(_BV(RS)|_BV(RW)|_BV(E));
	ddrDB &= ~0b1111;
	portDB &= ~0b1111;
	DDRB |= _BV(2);//przetwornica
	PORTB |= _BV(2);//przetwornica
}

void OLEDinstr_funkSet(){
	ddrDB |= 0b1111;
	port3 &= ~(_BV(RS)|_BV(RW));
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b0010;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_ms(5);
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b1000;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
}

void OLEDinstr_onOff(){
	_delay_ms(1);
	ddrDB |= 0b1111;
	port3 &= ~(_BV(RS)|_BV(RW));
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b0000;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_ms(5);
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b1100;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
}

void OLEDinstr_enteryMode(){
	ddrDB |= 0b1111;
	port3 &= ~(_BV(RS)|_BV(RW));
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b0000;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b0110;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
}

void OLEDinstr_displayMode(){
	ddrDB |= 0b1111;
	port3 &= ~(_BV(RS)|_BV(RW));
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b0001;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b0111;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
}


void OLEDinstr_cursorMode(){
	ddrDB |= 0b1111;
	port3 &= ~(_BV(RS)|_BV(RW));
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b0001;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b0100;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
}

void OLEDinstr_sync(){
	ddrDB |= 0b1111;
	port3 &= ~(_BV(RS)|_BV(RW));
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b0000;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b0000;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b0000;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b0000;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b0000;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
}

uint8_t OLEDinitChr4bit(){	//OLED init.
	//Wait for power stabilization
	_delay_ms(100);

	//function set 3 8bitowe ramki
	ddrDB |= 0b1111;
	port3 &= ~(_BV(RS)|_BV(RW));
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b0010;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b0010;//set4bits
	_delay_us(1);
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b1000;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
	WS0010ChckBsyFl();

	//Display ON/OFF controll
	OLEDinstr_onOff();
	WS0010ChckBsyFl();

	//Clear
	OLEDinstr_clear();
	WS0010ChckBsyFl();

	//Entery mode set
	OLEDinstr_enteryMode();
	WS0010ChckBsyFl();

	//- - - - - - - - - - -

	//Display mode
	OLEDinstr_displayMode();
	WS0010ChckBsyFl();

	//Cursor mode
	OLEDinstr_cursorMode();
	return WS0010ChckBsyFl();
}

void OLEDreset(){//poco
	//synchronization funk
	OLEDinstr_sync();
	WS0010ChckBsyFl();

	//function set
	ddrDB |= 0b1111;
	port3 &= ~(_BV(RS)|_BV(RW));
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b0010;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b0010;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_ms(5);
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b1001;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
	WS0010ChckBsyFl();

	//initial command srtting
	ddrDB |= 0b1111;
	port3 &= ~(_BV(RS)|_BV(RW));
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b1111;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_ms(5);
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b0000;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
	WS0010ChckBsyFl();

	//Display RAM write
	ddrDB |= 0b1111;
	port3 &= ~_BV(RW);
	port3 |= _BV(RS)|_BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b1111;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_ms(5);
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= 0b0000;//set4bits
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
	WS0010ChckBsyFl();
}

void OLEDclear(){
	//Display clear
	OLEDinstr_clear();
	WS0010ChckBsyFl();
}

void OLEDhome(){
	//Display clear
	OLEDinstr_home();
	WS0010ChckBsyFl();
}

void OLEDcursor(uint8_t x , uint8_t y){//nieodwrocone
	uint8_t o;
	x = x & 0b00111111;
	y = ((y & 0b00000001) << 6);
		o = (0b10000000 + x + y);//
		ddrDB |= 0b1111;
		port3 &= ~(_BV(RS)|_BV(RW));
		port3 |= _BV(E);
		portDB &= ~0b1111;	//zer
		portDB |= (o >> 4);	//set4bits	//!!!
		_delay_us(1);
		port3 &= ~_BV(E);
		_delay_us(1);
		port3 |= _BV(E);
		portDB &= ~0b1111;	//zer
		portDB |= (0b1111 & o);	//set4bits	//!!!
		_delay_us(1);
		port3 &= ~_BV(E);
		_delay_us(1);
		WS0010ChckBsyFl();
}

uint8_t OLEDread(){ //nie dla 4bit
	ddrDB &= ~0b1111;
	port3 |= (_BV(RS)|_BV(RW));
	port3 |= _BV(E);
	_delay_us(1);
	uint8_t OLEDread = pinDB;
	port3 &= ~_BV(E);
	_delay_us(1);

	WS0010ChckBsyFl();
	return OLEDread;
}

void OLEDsendStr(char *str){
	_delay_us(50);
	for (char *it = str; *it; it++) {
		OLEDwrite(*it);
	}
}

void OLEDwrite(uint8_t chr){//special chars 0-7
	ddrDB |= 0b1111;
	port3 &= ~_BV(RW);
	port3 |= _BV(RS)|_BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= (chr >> 4);//
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= (0b1111 & chr);//
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);

	WS0010ChckBsyFl();
}

void WS0010instr(uint8_t addr){
	ddrDB |= 0b1111;
	port3 &= ~(_BV(RS)|_BV(RW));
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= (addr >> 4);//
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);
	port3 |= _BV(E);
	portDB &= ~0b1111;	//zer
	portDB |= (0b1111 & addr);//
	_delay_us(1);
	port3 &= ~_BV(E);
	_delay_us(1);

	WS0010ChckBsyFl();
}

void WS0010customChrUpload(uint8_t chr,uint8_t *str){//chr = 0-7 ;
	for (uint8_t i = 0; i < 8; ++i) {
		WS0010instr(0b1000000 + (chr<<3) + i);
		OLEDwrite(*(str+i));
	}
}

uint8_t WS0010ChckBsyFl(){	//Check busy flag
	uint8_t i = 0;
	ddrDB &= ~0b1111;//db7
	portDB |= 0b1111;//db7
	port3 &= ~_BV(RS);
	port3 |= _BV(RW);
	_delay_us(150);

	port3 |= _BV(E);
	_delay_us(2);
	while((pinDB & _BV(3))&&(i<200)){//db7
		port3 &= ~_BV(E);
		_delay_us(2);
		port3 |= _BV(E);
		_delay_us(2);

		port3 &= ~_BV(E);
		_delay_us(2);
		port3 |= _BV(E);
		_delay_us(2);
		i++;
	}
	port3 &= ~_BV(E);
	_delay_us(2);
	port3 |= _BV(E);
	_delay_us(2);
	port3 &= ~_BV(E);
	_delay_us(2);

	portDB &= ~0b1111;//db7
	ddrDB |= 0b1111;//db7
	_delay_us(1);
	port3 &= ~_BV(E);
	port3 &= ~_BV(RW);
	_delay_us(1);
	if(i>199){
		return 1; //1 - błąd
	}
	return 0;
}

