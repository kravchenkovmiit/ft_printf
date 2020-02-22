/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:46:00 by hvalenci          #+#    #+#             */
/*   Updated: 2020/02/21 17:14:55 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		check_wildcard(int *f_type, int i)
{
	if (f_type[2] == 1)
		f_type[1] = 0;
	return (i);
}

int		check_mnh(int *f_type, char c)
{
	if (!f_type[0] || c != 'o')
		f_type[2] = 0;
	return (1);
}

void	check_f_asterix(va_list args, int *f_type, int w)
{
	if (f_type[12])
	{
		w = va_arg(args, int);
		if (w < 0)
		{
			w *= -1;
			f_type[2] = 1;
		}
		f_type[5] = f_type[5] == 0 ? w : f_type[5];
	}
	if (f_type[13])
	{
		if ((f_type[11] = va_arg(args, int)) < 0)
			f_type[11] = -1;
	}
	check_wildcard(f_type, 1);
}

int		is_flag(char s, char f, int *f_t, int *k)
{
	if (s == f && s != '\0')
	{
		f_t[*k] = 1;
		*k = 0;
		return (1);
	}
	return (0);
}

int		p_ignor_flags(int *f_type)
{
	f_type[0] = 1;
	f_type[8] = 1;
	return (0);
}
