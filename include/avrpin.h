#ifndef __AVRPIN_H
#define __AVRPIN_H


#define BIT(n) (1 << (n))
#define _PIN(port, pinnum) P ## port ## pinnum
#define _DDR(port) DDR ## port
#define _PORT(port) PORT ## port
#define _INPUT(port) PIN ## port
#define PINDEF(port, pinnum) port, BIT(_PIN(port, pinnum))

#define _SET_BIT_LOW(reg, bit) do { reg &= ~(bit); } while(0)
#define _SET_BIT_HIGH(reg, bit) do { reg |= (bit); } while(0)
#define _SET_BIT(reg, bit, boolean) do { \
if (boolean) \
	_SET_BIT_HIGH(reg, bit); \
else \
	_SET_BIT_LOW(reg, bit); \
} while(0)

#define INPUT  0
#define OUTPUT 1
#define pindir(pindef, dir) _PINDIR(pindef, dir)
#define _PINDIR(port, pinbit, dir) _SET_BIT(_DDR(port), pinbit, dir)

#define iowrite(pindef, state) _IOWRITE(pindef, state)
#define _IOWRITE(port, pinbit, state) _SET_BIT(_PORT(port), pinbit, state)

#define ioread(pindef) _IOREAD(pindef)
#define _IOREAD(port, pinbit) (_INPUT(port) & (pinbit))


#endif /* __AVRPIN_H */
