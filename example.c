#include <avr/io.h>
#include <util/delay.h>
#include "avrpin.h"

//LED is on PB0
#define LED_PIN PINDEF(B, 0)
//Button on PA2
#define BUTTON_PIN PINDEF(A, 2)

int main(void)
{
	PINDIR(LED_PIN, OUTPUT);
	PINDIR(BUTTON_PIN, INPUT);

	for (;;) {
		//if button is pressed (BUTTON_PIN is a 1)
		if (READ_IN(BUTTON_PIN)) {
			continue;
		}

		//output 1 on led pin
		WRITE_OUT(LED_PIN, HIGH);
		_delay_ms(1000);
		WRITE_OUT(LED_PIN, LOW);
		_delay_ms(1000);
	}
}
