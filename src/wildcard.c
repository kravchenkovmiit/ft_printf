#include "printf.h"

int		check_wildcard(int *f_type)
{
	if (f_type[2] == 1)
		f_type[1] = 0;
	return (1);
}

void	check_f_asterix(va_list args, int *f_type)
{
	if (f_type[12])
	{
		if ((f_type[5] = va_arg(args, int)) < 0)
		{
			f_type[5] *= -1;
			f_type[2] = 1;
		}
	}
	if (f_type[13])
	{
		if ((f_type[11] = va_arg(args, int)) < 0)
		{
			f_type[11] = -1;
			f_type[2] = 1;
		}
	}
	check_wildcard(f_type);
}