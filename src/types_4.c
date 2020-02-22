/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:45:52 by hvalenci          #+#    #+#             */
/*   Updated: 2020/02/21 16:05:53 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			len_ul(uintmax_t num)
{
	int	count;

	count = 1;
	while (num /= 10)
		count++;
	return (count);
}

int			check_ul_precision(int *f_type, uintmax_t d)
{
	int sz;
	int	f;

	f = 0;
	sz = len_ul(d);
	if (f_type[3])
		f_type[4] = 0;
	if (f_type[11] == 0 && d == 0)
		f_type[2] = 0;
	if (f_type[11] != -1)
		f_type[1] = 0;
	if (f_type[11] > sz && (++f) > 0)
	{
		sz = f_type[11];
		f_type[11] -= len_ul(d);
	}
	else if (f_type[11] == 0)
		f_type[11] = 0;
	else
		f_type[11] = -1;
	if (!(f_type[11] == 0 && !f && d == 0) || f_type[2])
		f_type[5] -= sz;
	return (sz);
}

int			display_un_nbr(uintmax_t n, int *f_type, int f)
{
	if (f_type[11] == 0 && n == 0 && (f = -1) == -1)
	{
		if (f_type[5] > 0 && (++f) == 0)
			ft_putchar(' ');
		return (f);
	}
	while ((f_type[11]--) > 0)
		ft_putchar('0');
	if (n >= 10)
		display_nbr(n / 10, f_type, f);
	ft_putchar((n % 10) + '0');
	return (0);
}

int			ul_type(va_list args, int *f_type)
{
	uintmax_t	d;
	int			sz;
	int			neg;

	neg = 0;
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
