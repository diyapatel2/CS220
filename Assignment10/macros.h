#ifndef MACROS_H

#define BIT(n) (1UL << (n))
#define BIT_MASK(len) (BIT(len) -1)
#define BF_MASK(start, len) (BIT_MASK(len +1 ) << (start))
#define MASK(start, end) (~((~0) << ((end) - (start) +1)))

#define TEST_IF_ANY_SET(v, start, end)((v) | (MASK(start, end)))

#define TEST_IF_ALL_SET(v, start, end)((v) & (BF_MASK(end, (start-end)))) == (BF_MASK(end, (start-end)))

#endif
