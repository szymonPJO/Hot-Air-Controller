/*
 * oled.h
 *	Biblioteka do wyswietlacza graficznego z sterownikiem WS0010
 *  Created on: 9 pa� 2019
 *      Author: Szymonp
 */

#ifndef OLED4BIT_OLED_H_
#define OLED4BIT_OLED_H_

#include <inttypes.h>

#define RS 5//PA6	// 0=>instructions ; 1=>data
#define RW 3//PA5	// 0=>write ; 1=>read
#define E 4//PA4	//en.

void OLED_GPIOinit();
void OLED_GPIOoff();
uint8_t OLEDinitChr4bit();
void OLEDreset();
void OLEDclear();
void OLEDhome();
void OLEDcursor(uint8_t x , uint8_t y);
void OLEDwrite(uint8_t chr);
uint8_t OLEDread();
void OLEDsendStr(char *str);
void OLEDinstr_clear();
void OLEDinstr_home();
void OLEDinstr_funkSet();
void OLEDinstr_onOff();
void OLEDinstr_enteryMode();
void OLEDinstr_displayMode();
void OLEDinstr_cursorMode();
void OLEDinstr_sync();
uint8_t WS0010ChckBsyFl();
void WS0010instr(uint8_t addr);
void WS0010customChrUpload(uint8_t chr,uint8_t *str);

#endif /* OLED4BIT_OLED_H_ */
