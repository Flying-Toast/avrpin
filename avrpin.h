#ifndef __AVRPIN_H
#define __AVRPIN_H


#define BIT(n) (1 << n)
#define _PIN(port, pinnum) P ## port ## pinnum
#define _DDR(port) DDR ## port
#define _PORT(port) PORT ## port
#define PINDEF(port, pinnum) port, BIT(_PIN(port, pinnum))

#define _SET_BIT_LOW(reg, bit) do { reg &= ~bit; } while(0)
#define _SET_BIT_HIGH(reg, bit) do { reg |= bit; } while(0)

#define PINDIR(pindef, dir) _PINDIR_ ## dir(pindef)
#define _PINDIR_INPUT(port, pinbit) _SET_BIT_LOW(_DDR(port), pinbit)
#define _PINDIR_OUTPUT(port, pinbit) _SET_BIT_HIGH(_DDR(port), pinbit)

#define WRITE_OUT(pindef, state) _WRITE_OUT_ ## state(pindef)
#define _WRITE_OUT_HIGH(port, pinbit) _SET_BIT_HIGH(_PORT(port), pinbit)
#define _WRITE_OUT_LOW(port, pinbit) _SET_BIT_LOW(_PORT(port), pinbit)


#endif
