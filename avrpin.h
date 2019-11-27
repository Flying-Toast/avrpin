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

#define PINDIR(pindef, dir) _PINDIR_ ## dir(pindef)
#define _PINDIR_INPUT(port, pinbit) _SET_BIT_LOW(_DDR(port), pinbit)
#define _PINDIR_OUTPUT(port, pinbit) _SET_BIT_HIGH(_DDR(port), pinbit)

#define WRITE_OUT(pindef, state) _WRITE_OUT_ ## state(pindef)
#define _WRITE_OUT_HIGH(port, pinbit) _SET_BIT_HIGH(_PORT(port), pinbit)
#define _WRITE_OUT_LOW(port, pinbit) _SET_BIT_LOW(_PORT(port), pinbit)

#define READ_IN(pindef) _READ_IN(pindef)
#define _READ_IN(port, pinbit) (_INPUT(port) & pinbit)

#define _PORTLETTER_OF(port, pinbit) port
#define PINBIT_OF(pindef) _PINBIT_OF(pindef)
#define _PINBIT_OF(port, pinbit) pinbit
#define DDR_OF(pindef) _DDR_OF(_PORTLETTER_OF(pindef))
#define _DDR_OF(port) _DDR(port)
#define PORT_OF(pindef) _PORT_OF(_PORTLETTER_OF(pindef))
#define _PORT_OF(port) _PORT(port)
#define INPUT_REG_OF(pindef) _INPUT_REG_OF(_PORTLETTER_OF(pindef))
#define _INPUT_REG_OF(port) _INPUT(port)


#endif
