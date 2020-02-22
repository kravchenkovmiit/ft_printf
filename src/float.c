/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:43:40 by hvalenci          #+#    #+#             */
/*   Updated: 2020/02/21 16:24:40 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	check_f(int *f_type, double d, int sz)
{
	if (f_type[2])
		f_type[1] = 0;
	if (f_type[3])
		f_type[4] = 0;
	if ((f_type[5] -= sz) < 0)
		f_type[5] = 0;
	if (f_type[4] && f_type[5] <= 0)
		f_type[5] = 1;
	if (f_type[3] || ch_neg(d))
		f_type[5]--;
	if (f_type[5] < 0)
		f_type[1] = 0;
	if (f_type[11] == 0)
		f_type[11] = 0;
	else
		f_type[11] = -1;
}

static char	*dbtostr(double d)
{
	char	*res;
	char	*frac;
	char	*integ;
	t_float	*fdb;

	fdb = get_fdb(d);
	if (fdb->exp == 1024)
		return (NULL);
	handle_mantissa(fdb);
	integ = ft_cptoch(fdb->mantissa, '.');
	frac = ft_strchr(fdb->mantissa, '.');
	res = get_btoi(integ);
	free(integ);
	integ = res;
	res = get_btofr(frac);
	frac = res;
	res = ft_strjoin(integ, frac);
	free(integ);
	free(frac);
	free(fdb->mantissa);
	free(fdb);
	return (res);
}

static int	get_round(char **res, int ilen, int prec, int extra_one)
{
	if (prec == 0)
		++ilen;
	if (ilen < (int)ft_strlen(*res))
	{
		if (ilen > 0 && (*res)[ilen] >= '5' && (*res)[ilen--] <= '9')
		{
			if ((*res)[ilen] == '.')
				ilen--;
			(*res)[ilen]++;
			while (ilen >= 0 && (*res)[ilen] == ':')
			{
				(*res)[ilen] = '0';
				if ((*res)[--ilen] == '.')
					ilen--;
				(*res)[ilen]++;
				if (ilen == 0 && (*res)[ilen] == ':' && (extra_one = 1))
					(*res)[ilen] = '0';
			}
		}
	}
	if (extra_one)
		*res = ft_strjoin("1", *res);
	return (extra_one);
}

static int	ftoa(double d, char **res, int prec, int hash)
{
	int		ilen;

	if (d != d)
	{
		ft_putstr(ch_neg(d) ? "-nan" : "nan");
		return (-1);
	}
	if (!(*res = dbtostr(d)))
	{
		ft_putstr(ch_neg(d) ? "-inf" : "inf");
		return (-1);
	}
	ilen = 0;
	while ((*res)[ilen] != '.' && (*res)[ilen])
		ilen++;
	if (prec > 0)
		ilen += prec + 1;
	if (prec == 0 && hash)
		ilen++;
	ilen += get_round(res, ilen, prec, 0);
	return (ilen);
}

int			f_type(va_list args, int *f_t)
{
	double	d;
	int		sz;
	int		neg;
	char	*res;

	if (f_t[11] == -1)
		f_t[11] = 6;
	d = va_arg(args, double);
	neg = ch_neg(d);
	if ((sz = ftoa(d, &res, f_t[11], f_t[0])) == -1)
	{
		if (neg)
			return (4);
		return (3);
	}
	check_f(f_t, d, sz);
	display_float(res, sz, f_t, neg);
	free(res);
	if (f_t[5] > 0)
		sz += f_t[5];
	return (sz + (f_t[3] || neg));
}
