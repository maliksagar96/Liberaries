#include "Ultrasonic.h"
#include <avr/interrupt.h>

void ultrasonic_init() {
	//setting trigger PINS as outputs
	triggerDDR = (1 << trigger_PINS[0]) | (1 << trigger_PINS[1]) | (1 << trigger_PINS[2]);
	//timer init
	TCCR1B = preScalar0;
	TCCR3B = preScalar1;
	//TCCR4B = preScalar2; 
	EICRA = ;
	EICRB = ;
	EIMSK = (1 << INT_PINS[0]) | (1 << INT_PINS[1]) | (1 << INT_PINS[2]);
	sei();
}

void trigger(uint8_t n) {
		
		triggerPort &=~(1<<trigger_PINS[n]);	//setting trig pin to low
		_delay_us(2);			//delay to let signal settle
		triggerPort |= (1<<trigger_PINS[n]); 	//setting trig pin to high to activate sensor
		_delay_us(15);			//pause in high state greater than 10us
		triggerPort &= ~(1<<trigger_PINS[n]);	//bring trig pin back to low
		
		//assigning timer counter value zero
		if (n == 0)			timerCounter0 = 0;
		else if(n == 1)		timerCounter1 = 0;
		else if(n == 2)		timerCounter2 = 0;
	//	_delay_ms(35);
}

float getDistance(uint8_t n) {
			return timerCapture[n] * 2.17;
}

ISR(INT1_vect) {
		timerCapture[0] = timerCounter0;
}

ISR(INT2_vect) {
	timerCapture[1] = timerCounter1;
}

ISR(INT3_vect) {
	timerCapture[2] = timerCounter2;
}