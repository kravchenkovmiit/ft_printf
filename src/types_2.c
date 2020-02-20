#include "printf.h"

int		check_precision_un(int *f_type, char *s, int hash, char conv)
{
	int sz;
	int	f;

	f = 0;
	sz = ft_strlen(s);
	if (s[0] == '0' && sz == 1)
	{
		if (f_type[11] == 0 && conv == 'o' && f_type[0])
			f_type[11]++;
		f_type[0] = 0;
	}
	if (f_type[11] != -1)
		f_type[1] = 0;
	if (f_type[11] > sz && (++f) > 0)
	{
		sz = f_type[11];
		f_type[11] -= ft_strlen(s);
	}
	else if (f_type[11] == 0)
		f_type[11] = 0;
	else
		f_type[11] = -1;
	if (!(f_type[11] == 0 && !f && s[0] == '0' && sz == 1) || f_type[2])
		f_type[5] -= (sz + f_type[0] * hash);
	return (sz);
}

int		o_type(va_list args, int *f_type)
{
	uintmax_t	d;
	int 		neg;
	char		*o_d;
	int			sz;

	neg = 0;
	d = get_nbr_un(args, f_type);
	if (f_type[11] > (int )ft_strlen((o_d = d_to_o(d))))
		f_type[0] = 0;
	sz = check_precision_un(f_type, o_d, 1, 'o');
	if (!f_type[2])
	{
		sz += fill_w_char(f_type, neg, 0, 'o');
		sz += put_converted_num(o_d, f_type, 'o');
	}
	else
	{
		sz += check_neg(f_type, neg);
		sz += check_f_hash(f_type, 'o');
		sz += put_converted_num(o_d, f_type, 'o');
		sz += fill_w_char(f_type, 0, 0, '#');
	}
	free(o_d);
	return (sz);
}

int		x_type(va_list args, int *f_type)
{
	uintmax_t	d;
	int 		neg;
	char		*x_d;
	int			sz;

	neg = 0;
	d = get_nbr_un(args, f_type);
	sz = check_precision_un(f_type, (x_d = d_to_x(d)), 2, 'x');
	if (!f_type[2])
	{
		sz += fill_w_char(f_type, neg, 0, 'x');
		sz += put_converted_num(x_d, f_type, 'x');
	}
	else
	{
		sz += check_neg(f_type, neg);
		sz += check_f_hash(f_type, 'x');
		sz += put_converted_num(x_d, f_type, 'x');
		sz += fill_w_char(f_type, 0, 0, '#');
	}
	free(x_d);
	return (sz);
}

int		X_type(va_list args, int *f_type)
{
	uintmax_t	d;
	int 		neg;
	char		*X_d;
	int			sz;

	neg = 0;
	d = get_nbr_un(args, f_type);
	sz = check_precision_un(f_type, (X_d = d_to_X(d)), 2, 'X');
	if (!f_type[2])
	{
		sz += fill_w_char(f_type, 0, 0, 'X');
		sz += put_converted_num(X_d, f_type, 'X');
	}
	else
	{
		sz += check_neg(f_type, neg);
		sz += check_f_hash(f_type, 'X');
		sz += put_converted_num(X_d, f_type, 'X');
		sz += fill_w_char(f_type, 0, 0, '#');
	}
	free(X_d);
	return (sz);
}

int		p_type(va_list args, int *f_type)
{
	uintmax_t	d;
	int 		neg;
	char		*x_d;
	int			sz;

	neg = 0;
	f_type[0] = 1;
	f_type[8] = 1;
	if (!(d = get_nbr_un(args, f_type)))
		return (display_nil());
	sz = check_precision_un(f_type, (x_d = d_to_x(d)), 2, 'p');
	if (!f_type[2])
	{
		sz += fill_w_char(f_type, neg, 0, 'x');
		sz += put_converted_num(x_d, f_type, 'p');
	}
	else
	{
		sz += check_neg(f_type, neg);
		sz += check_f_hash(f_type, 'x');
		sz += put_converted_num(x_d, f_type, 'p');
		sz += fill_w_char(f_type, 0, 0, '#');
	}
	free(x_d);
	return (sz);
}