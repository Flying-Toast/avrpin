#ifndef __AVRPIN_H
#define __AVRPIN_H


#include <avr/io.h>

#define BIT(n) (1 << n)
#define _PIN(port, pinnum) P ## port ## pinnum
#define _DDR(port) DDR ## port
#define _PORT(port) PORT ## port
#define _INPUT(port) PIN ## port
#define PINDEF(port, pinnum) port, BIT(_PIN(port, pinnum))

#define _SET_BIT_LOW(reg, bit) do { reg &= ~bit; } while(0)
#define _SET_BIT_HIGH(reg, bit) do { reg |= bit; } while(0)
#define _SET_BIT(reg, bit, boolean) do { \
if (boolean) \
	_SET_BIT_HIGH(reg, bit); \
else \
	_SET_BIT_LOW(reg, bit); \
} while(0)

#define INPUT  0
#define OUTPUT 1
#define PINDIR(pindef, dir) _PINDIR(pindef, dir)
#define _PINDIR(port, pinbit, dir) _SET_BIT(_DDR(port), pinbit, dir)

#define WRITE_OUT(pindef, state) _WRITE_OUT(pindef, state)
#define _WRITE_OUT(port, pinbit, state) _SET_BIT(_PORT(port), pinbit, state)

#define READ_IN(pindef) _READ_IN(pindef)
#define _READ_IN(port, pinbit) (_INPUT(port) & pinbit)


#endif
