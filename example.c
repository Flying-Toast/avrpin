#include <avr/io.h>
#include <util/delay.h>
#include "avrpin.h"

//LED is on PB0
#define LED_PIN PINDEF(B, 0)
//Button on PA2
#define BUTTON_PIN PINDEF(A, 2)

int main(void)
{
	//OUTPUT is #defined to `1`
	PINDIR(LED_PIN, OUTPUT);
	//INPUT is #defined to `0`
	PINDIR(BUTTON_PIN, INPUT);

	for (;;) {
		//if button is pressed, don't blink (contrived for example)
		if (READ_IN(BUTTON_PIN)) {
			continue;
		}

		//output 1 on led pin
		WRITE_OUT(LED_PIN, 1);
		_delay_ms(1000);
		WRITE_OUT(LED_PIN, 0);
		_delay_ms(1000);
	}
}
