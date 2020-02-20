#include "printf.h"

int		c_type(va_list args, int *f_type)
{
	unsigned char	ch;
	int				sz;

	sz = 1;
	ch = va_arg(args, int);
	ch =  (unsigned char)ch;
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

int		perc_type(va_list args, int *f_type)
{
	unsigned char	ch;

	ch = '%';
	(void)args;
	f_type[5] -= 1;
	write(1, &ch, 1);
	return (1);
}
/*
int		s_type(va_list args, int *f_type)
{
	const char	*str;
	int			sz;
	int			len;

	sz = 0;
	if ((str = va_arg(args, const char*)) == NULL)
		return (display_null());
	if ((len = ft_strlen(str)) > f_type[11] && f_type[11] >= 0)
		len = f_type[11];
	f_type[5] -= len;
	if (!f_type[2])
	{
		while (f_type[5]-- > 0 && (++sz))
			ft_putchar(' ');
		display_str(str, len);
	}
	else
	{
		display_str(str, len);
		while (f_type[5]-- > 0 && (++sz))
			ft_putchar(' ');
	}
	sz += len;
	return (sz);
}
*/

static int	handle_null(const char *str, int *f_type)
{
	if (str == NULL)
	{
		if (f_type[11] > 0 && f_type[11] < 6)
			f_type[11] = 0;
		return (6);
	}
	return (ft_strlen(str));
}

int		s_type(va_list args, int *f_type)
{
	const char	*str;
	int			sz;
	int			len;

	sz = 0;
	str = va_arg(args, const char*);
	len = handle_null(str, f_type);
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
