# Hot-Air-Controller
Simple Hot Air station with some 8-bit AVR (ATmega or ATtiny), 2x16 alfanumeric OLED and potentiometer for regulation
Power: 230VAC heating, 12V fan, 5V 

I just want to make this hot station from useless parts I have

## Build

This project is built on the linux (fedora). 
BTW: On windows, avr-gcc libraries paths (maybe only for CMakeLists) needs to be modified. 

### Software Requirments

- make
- cmake
- avr-gcc
- avrdude

### Hardware Requirments

- USBASP
- ATMega88a
- LCD (HD44780 driver)
- Power output (230VAC) with zero cross-detection circuit
- Power output (12V) PWM fan circuit