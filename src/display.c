#include "printf.h"

int		display_nbr(intmax_t n, int *f_type, int f)
{
	if (f_type[11] == 0 && n == 0 && (f = -1) == -1)
	{
		if (f_type[5] > 0 && (++f) == 0)
			ft_putchar(' ');
		return (f);
	}
	while ((f_type[11]--) > 0)
		ft_putchar('0');
	if (n == -2147483648)
		ft_putstr("2147483648");
	else if ((n + 1) == -9223372036854775807)
		ft_putstr("9223372036854775808");
	else
	{
		if (n < 0 && (n *= -1) > 0)
			ft_putchar('-');
		if (n >= 10)
			display_nbr(n / 10, f_type, f);
		ft_putchar((n % 10) + '0');
	}
	return (0);
}

void	display_str(const char *s, int len)
{
	if (s)
	{
		while (*s && (len--) > 0)
			ft_putchar(*s++);
	}
}

void	display_float(const char *s, int len, int *f_t, int neg)
{
	int		wdth;
	char	c;
	char	n;

	c = f_t[1] == 1 ? '0' : ' ';
	n = neg == 1 ? '-' : '+';
	if (f_t[1] && (f_t[3] || neg))
		ft_putchar(n);
	if (((wdth = f_t[5]) <= 0 || f_t[1] || f_t[2]) && f_t[4] && !neg)
	{
		ft_putchar(' ');
		wdth--;
	}
	if (wdth > 0 && !f_t[2])
		while (wdth--)
			ft_putchar(c);
	if (!f_t[1] && (f_t[3] || neg))
		ft_putchar(n);
	if (s)
		while (*s && (len--) > 0)
			ft_putchar(*s++);
	while (0 < len--)
		ft_putchar('0');
	while (0 < wdth-- && f_t[2])
		ft_putchar(c);
}

int		display_nil(void)
{
	write(1, "(nil)", 5);
	return (5);
}
