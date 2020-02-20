#include "printf.h"

int	ch_neg(double d)
{
	if (*(__uint64_t*)(&d) >> 63)
		return (1);
	return (0);
}

int	ch_lneg(long double d)
{
	if ((*(__uint128_t*)(&d) << 48 >> 48) >> 79)
		return (1);
	return (0);
}
