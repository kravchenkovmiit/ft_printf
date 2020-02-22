/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:43:07 by hvalenci          #+#    #+#             */
/*   Updated: 2020/02/21 16:36:34 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		put_converted_num(char *s, int *f_type, char conv)
{
	int i;
	int f;

	conv += 1;
	i = ft_strlen(s);
	if (f_type[11] == 0 && *s == '0' && i == 1)
	{
		f = -1;
		if (f_type[5] > 0 && (++f) == 0)
			ft_putchar(' ');
		return (f);
	}
	while ((f_type[11]--) > 0)
		ft_putchar('0');
	while (i--)
	{
		ft_putchar(s[i]);
	}
	return (0);
}

char	*d_to_o(uintmax_t dig)
{
	char	*str;
	int		i;

	i = len_ul(dig) + 1;
	str = ft_strnew(i);
	i = 0;
	while (dig > 7)
	{
		str[i] = (dig % 8) + '0';
		dig /= 8;
		i++;
	}
	str[i] = dig + '0';
	return (str);
}

char	*d_to_x(uintmax_t dig)
{
	char		*str;
	int			i;
	uintmax_t	tmp;

	i = len_ul(dig);
	str = ft_strnew(i);
	i = 0;
	while (dig > 15)
	{
		if ((tmp = dig % 16) < 10)
			str[i] = tmp + '0';
		else
			str[i] = (tmp - 10) + 'a';
		dig /= 16;
		i++;
	}
	if (dig < 10)
		str[i] = dig + '0';
	else
		str[i] = (dig - 10) + 'a';
	return (str);
}

char	*d_to_lx(uintmax_t dig)
{
	char		*str;
	int			i;
	uintmax_t	tmp;

	i = len_ul(dig);
	str = ft_strnew(i);
	i = 0;
	while (dig > 15)
	{
		if ((tmp = dig % 16) < 10)
			str[i] = tmp + '0';
		else
			str[i] = (tmp - 10) + 'A';
		dig /= 16;
		i++;
	}
	if (dig < 10)
		str[i] = dig + '0';
	else
		str[i] = (dig - 10) + 'A';
	return (str);
}

int		check_f_hash(int *f_type, char f)
{
	int	i;

	i = 0;
	if (f_type[0] && (++i))
	{
		ft_putchar('0');
		if (f == 'X' && (++i))
			ft_putchar('X');
		else if (f == 'x' && (++i))
			ft_putchar('x');
	}
	return (i);
}
