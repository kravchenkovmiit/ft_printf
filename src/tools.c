/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:44:15 by hvalenci          #+#    #+#             */
/*   Updated: 2020/02/21 15:44:15 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		check_f_space(int *f_type, int neg)
{
	if (f_type[4] && !neg)
	{
		f_type[5] -= 1;
		ft_putchar(' ');
		return (1);
	}
	return (0);
}

int		check_neg(int *f_type, int neg)
{
	if (neg)
	{
		ft_putchar('-');
		if (!f_type[3])
			f_type[5] -= 1;
		return (1);
	}
	return (0);
}

int		check_f_plus(int *f_type, int neg)
{
	if (!neg && f_type[3])
	{
		ft_putchar('+');
		return (1);
	}
	return (0);
}

char	check_f_zero(int *f_type)
{
	if (f_type[1] && !f_type[2])
		return ('0');
	return (' ');
}

int		fill_w_char(int *f_type, int neg, int f_plus, char f)
{
	char	ch;
	int		res;

	res = 0;
	f_type[5] -= f_type[3];
	ch = check_f_zero(f_type);
	if (neg && !f_plus)
		f_type[5] -= 1;
	if (ch == '0' && neg && (++res))
		ft_putchar('-');
	else if (ch == '0' && f_plus && (++res))
		ft_putchar('+');
	if (ch == '0' && f > 47)
		res += check_f_hash(f_type, f);
	if (f_type[5] > 0 && (res += f_type[5]))
		while (f_type[5]-- > 0)
			ft_putchar(ch);
	if (ch == ' ' && neg && (++res))
		ft_putchar('-');
	else if (ch == ' ' && f_plus && (++res))
		ft_putchar('+');
	if (ch == ' ' && f > 47 && (f_type[11] <= 0 || f != 'o'))
		res += check_f_hash(f_type, f);
	return (res);
}
