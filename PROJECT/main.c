// #include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 8000000UL

int main(void){
 	DDRB = 	0xFF;
    while(1){
        // for (uint32_t i = 100000; i>0; i--);
        _delay_ms(1000);
        PORTB ^= 0xFF;
    }
}