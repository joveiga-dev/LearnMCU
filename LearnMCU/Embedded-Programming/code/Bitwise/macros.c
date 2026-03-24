#include <stdio.h>

#define SET_BIT(x, pos)     ((x) |= (1U << (pos)))
#define CLEAR_BIT(x, pos)   ((x) &= ~(1U << (pos)))
#define CHECK_BIT(x, pos)    ((x) & (1U << (pos)))
#define TOGGLE_bit(x, pos)   ((x) ^= (1U << (pos)))
#define GET_BIT(x, pos)      (((x) &= (1 << pos)) >> (pos))