#include "printf.h"

int			len(intmax_t num)
{
	int	count;

	count = 1;
	while (num /= 10)
		count++;
	return (count);
}

int			check_precision(int *f_type, intmax_t d)
{
	int sz;
	int	f;

	f = 0;
	sz = len(d);
	if (f_type[3])
		f_type[4] = 0;
	if (f_type[11] == 0 && d == 0 && !f_type[3])
		f_type[2] = 0;
	if (f_type[11] != -1)
		f_type[1] = 0;
	if (f_type[11] > sz && (++f) > 0)
	{
		sz = f_type[11];
		f_type[11] -= len(d);
	}
	else if (f_type[11] == 0)
		f_type[11] = 0;
	else
		f_type[11] = -1;
	if (!(f_type[11] == 0 && !f && d == 0) || f_type[2])
		f_type[5] -= sz;
	return (sz);
}

int			d_type(va_list args, int *f_type)
{
	intmax_t	d;
	int			sz;
	int 		neg;

	neg = 0;
	d = get_nbr(args, f_type);
	if (d < 0 && (neg = 1))
		d *= -1;
	sz = check_precision(f_type, d);
	if (!f_type[2])
	{
		sz += check_f_space(f_type, neg);
		sz += fill_w_char(f_type, neg, f_type[3], '#');
		sz += display_nbr(d, f_type, 0);
	}
	else
	{
		sz += check_neg(f_type, neg);
		sz += check_f_plus(f_type, neg);
		sz += check_f_space(f_type, neg);
		sz += display_nbr(d, f_type, 0);
		sz += fill_w_char(f_type, 0, 0, '#');
	}
	return (sz);
}

static int	ignor_flags(int *f_type)
{
	f_type[3] = 0;
	f_type[4] = 0;
	return (0);
}

int		u_type(va_list args, int *f_type)
{
	uintmax_t	d;
	int			sz;
	int 		neg;

	neg = ignor_flags(f_type);
	if (f_type[9])
		return (ul_type(args, f_type));
	d = get_nbr_un(args, f_type);
	sz = check_ul_precision(f_type, d);
	if (!f_type[2])
	{
		sz += check_f_space(f_type, neg);
		sz += fill_w_char(f_type, neg, f_type[3], '#');
		sz += display_un_nbr(d, f_type, 0);
	}
	else
	{
		sz += check_neg(f_type, neg);
		sz += check_f_plus(f_type, neg);
		sz += check_f_space(f_type, neg);
		sz += display_un_nbr(d, f_type, 0);
		sz += fill_w_char(f_type, 0, 0, '#');
	}
	return (sz);
}
