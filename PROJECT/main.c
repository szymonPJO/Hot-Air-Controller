// #include <stdlib.h>
#include "main.h"
#include <avr/io.h>
#include <util/delay.h>
#include "LIB/lib.h"
#include "LCD/lcd.h"

int main(void){
    DEBLED_INIT();
    // while(1) toggle_delayed(1000);

    OLED_GPIOinit();
    // _delay_ms(300);
    OLEDinitChr4bit();
    OLEDreset();
    OLEDclear();
    OLEDhome();
    OLEDcursor(0,0);
    OLEDsendStr("Hello");
    OLEDcursor(0,1);
    OLEDsendStr("World");

    DEBLED_ON()
    while(1);
}