#ifndef Ultrasonic
#define Ultrasonic

#include <avr/io.h>

#define triggerPort		PORTG
#define triggerDDR		DDRG
#define timerCounter0	TCNT1
#define timerCounter1	TCNT2
#define	timerCounter2	TCNT3
#define preScalar0      0x01			// prescalar of 1 
#define preScalar1		0x01			// prescalar of 1 
#define preScalar2      0x01			// prescalar of 1

void ultrasonic_init();
float getDistance(uint8_t n);
void trigger(uint8_t n);

volatile uint8_t INT_PINS[3] = {1,2,3};
volatile uint8_t trigger_PINS[3] = {1,2,3};
volatile timerCapture[3] = {0,0,0};
#endif
