#include "printf.h"

intmax_t	get_nbr(va_list args, int *f_type)
{
	intmax_t	d;

	d = va_arg(args, intmax_t);
	if (f_type[6])
		d = (char)d;
	else if (f_type[7])
		d = (short int)d;
	else if (f_type[8])
		d = (long int)d;
	else if (f_type[9])
		d = (long long int)d;
	else
		d = (int)d;
	return (d);
}

uintmax_t	get_nbr_un(va_list args, int *f_type)
{
	uintmax_t	d;

	d = va_arg(args, uintmax_t);
	if (f_type[6])
		d = (unsigned char)d;
	else if (f_type[7])
		d = (unsigned short int)d;
	else if (f_type[8])
		d = (unsigned long int)d;
	else if (f_type[9])
		d = (unsigned long long int)d;
	else
		d = (unsigned int)d;
	return (d);
}