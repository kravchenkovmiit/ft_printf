/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:45:49 by hvalenci          #+#    #+#             */
/*   Updated: 2020/02/21 16:10:07 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		check_precision_un(int *f_t, char *s, int hash, char conv)
{
	int sz;
	int	f;

	f = 0;
	sz = ft_strlen(s);
	if (s[0] == '0' && sz == 1 && conv != 'p')
	{
		if (f_t[11] == 0 && check_mnh(f_t, conv) && conv == 'o' && f_t[0])
			f_t[11]++;
		f_t[0] = 0;
	}
	if (f_t[11] != -1)
		f_t[1] = 0;
	if (f_t[11] > sz && (++f) > 0)
	{
		sz = f_t[11];
		f_t[11] -= ft_strlen(s);
	}
	else if (f_t[11] == 0)
		f_t[11] = 0;
	else
		f_t[11] = -1;
	if (!(f_t[11] == 0 && !f && s[0] == '0' && sz == 1) || f_t[2])
		f_t[5] -= (sz + f_t[0] * hash);
	return (sz);
}

int				o_type(va_list args, int *f_type)
{
	uintmax_t	d;
	int			neg;
	char		*o_d;
	int			sz;

	neg = 0;
	d = get_nbr_un(args, f_type);
	if (f_type[11] > (int)ft_strlen((o_d = d_to_o(d))))
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

int				x_type(va_list args, int *f_type)
{
	uintmax_t	d;
	int			neg;
	char		*x_d;
	int			sz;

	neg = 0;
	d = get_nbr_un(args, f_type);
	x_d = d_to_x(d);
	sz = check_precision_un(f_type, x_d, 2, 'x');
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

int				lx_type(va_list args, int *f_type)
{
	uintmax_t	d;
	int			neg;
	char		*lx_d;
	int			sz;

	neg = 0;
	d = get_nbr_un(args, f_type);
	lx_d = d_to_lx(d);
	sz = check_precision_un(f_type, lx_d, 2, 'X');
	if (!f_type[2])
	{
		sz += fill_w_char(f_type, 0, 0, 'X');
		sz += put_converted_num(lx_d, f_type, 'X');
	}
	else
	{
		sz += check_neg(f_type, neg);
		sz += check_f_hash(f_type, 'X');
		sz += put_converted_num(lx_d, f_type, 'X');
		sz += fill_w_char(f_type, 0, 0, '#');
	}
	free(lx_d);
	return (sz);
}

int				p_type(va_list args, int *f_type)
{
	uintmax_t	d;
	int			neg;
	char		*x_d;
	int			sz;

	neg = p_ignor_flags(f_type);
	d = get_nbr_un(args, f_type);
	x_d = d_to_x(d);
	sz = check_precision_un(f_type, x_d, 2, 'p');
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
