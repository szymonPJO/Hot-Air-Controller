// Debug led ;)
#define DEBUG_LED_PIN 3
#define DEBUG_LED_DDR DDRB
#define DEBUG_LED_PORT PORTB
#define DEBLED_INIT(); \
    DEBUG_LED_DDR  |= _BV(DEBUG_LED_PIN); \
    DEBUG_LED_PORT |= _BV(DEBUG_LED_PIN);
#define DEBLED_ON();  DEBUG_LED_PORT &= ~_BV(DEBUG_LED_PIN);
#define DEBLED_OFF();  DEBUG_LED_PORT |= _BV(DEBUG_LED_PIN);