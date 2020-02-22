/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:37:32 by hvalenci          #+#    #+#             */
/*   Updated: 2020/02/21 16:13:45 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			c_type(va_list args, int *f_type)
{
	unsigned char	ch;
	int				sz;

	sz = 1;
	ch = va_arg(args, int);
	ch = (unsigned char)ch;
	f_type[5] -= 1;
	if (!f_type[2])
	{
		while (f_type[5]-- > 0 && (++sz))
			ft_putchar(' ');
		write(1, &ch, 1);
	}
	else
	{
		write(1, &ch, 1);
		while (f_type[5]-- > 0 && (++sz))
			ft_putchar(' ');
	}
	return (sz);
}

int			perc_type(va_list args, int *f_type)
{
	unsigned char	ch;
	int				sz;

	sz = 1;
	(void)args;
	if (f_type[1] && !f_type[2])
		ch = '0';
	else
		ch = ' ';
	if (f_type[5] > 0)
		f_type[5] -= 1;
	if (!f_type[2])
	{
		while (f_type[5]-- > 0 && (++sz))
			ft_putchar(ch);
		write(1, "%", 1);
	}
	else
	{
		write(1, "%", 1);
		while (f_type[5]-- > 0 && (++sz))
			ft_putchar(ch);
	}
	return (sz);
}

static int	handle_null(const char *str)
{
	if (str == NULL)
		return (6);
	return (ft_strlen(str));
}

int			s_type(va_list args, int *f_type)
{
	const char	*str;
	int			sz;
	int			len;

	sz = 0;
	str = va_arg(args, const char*);
	len = handle_null(str);
	if (len > f_type[11] && f_type[11] >= 0)
		len = f_type[11];
	f_type[5] -= len;
	if (!f_type[2])
	{
		while (f_type[5]-- > 0 && (++sz))
			ft_putchar(' ');
		str == NULL ? display_str("(null)", len) : display_str(str, len);
	}
	else
	{
		str == NULL ? display_str("(null)", len) : display_str(str, len);
		while (f_type[5]-- > 0 && (++sz))
			ft_putchar(' ');
	}
	sz += len;
	return (sz);
}
