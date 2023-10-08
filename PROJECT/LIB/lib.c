#include <avr/io.h>
#include <util/delay.h>

void toggle_delayed(){
    // for (uint32_t i = 100000; i>0; i--);
    _delay_ms(1000);
    PORTB ^= 0xFF;
}