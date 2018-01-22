#include <stdio.h>


#define BIT(n) (1 << (n))
#define BIT_FLIP(v, mask) (v ^= (mask))
#define IS_SET_ANY(v, mask) (v & (mask))

unsigned long toggle_bit(unsigned long num, unsigned long bit_num);
