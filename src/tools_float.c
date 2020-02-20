#include "printf.h"

t_float		*get_fdb(double d)
{
	unsigned long	*nb;
	int				i;
	int				l;
	t_float			*res;

	nb = (unsigned long *)&d;
	if (!(res = (t_float *)malloc(sizeof(t_float))))
		return (NULL);
	res->sign = d < 0;
	if ((res->exp = (((*nb) << 1) >> 53) - 1023) == 1024)
		return (res);
	i = 0;
	while (((*nb) >> i & 1) != 1 && i < 52)
		++i;
	l = 52 - i;
	if (!(res->mantissa = ft_strnew(l + 2)))
	{
		free(res);
		return (NULL);
	}
	while (l + 1 > 0)
		res->mantissa[l-- + 1] = '0' + ((((*nb) >> i++) & 1) == 1);
	res->mantissa[0] = '1';
	res->mantissa[1] = '.';
	return (res);
}

static int	nbr_division(int i, char *res)
{
	char	t;

	t = res[i];
	if (t == '1' || t == '3' || t == '5' || t == '7' || t == '9')
	{
		t--;
		res[i + 1] += 5;
	}
	if (t == '.')
		return (1);
	if (t != '0')
		t = (t - '0') / 2 + '0';
	res[i] = t;
	return (0);
}

char		*s_division(char **s)
{
	char	*res;
	int		i;

	if (ft_strcmp(".0", *s) == 0)
	{
		free(*s);
		return (ft_strdup(".5"));
	}
	if (!(res = ft_strjoin_pf_2(s, '0')))
		return (NULL);
	i = ft_strlen(res) - 1;
	while (--i >= 0)
	{
		if (nbr_division(i, res))
			break ;
	}
	free(*s);
	*s = res;
	return (res);
}

char		*add_int(char **s1, char *s2, int f)
{
	char	*res;
	int		i;
	int		len1;
	int		len2;
	int		prev;

	len1 = ft_strlen(*s1);
	len2 = ft_strlen(s2);
	i = len1 > len2 ? len1 : len2 + 1;
	res = ft_strnew(i);
	prev = 0;
	while (--i >= 0)
	{
		res[i] = ((--len1 >= 0) ? (*s1)[len1] : '0') +
				 ((--len2 >= 0) ? s2[len2] : '0') - '0' + prev;
		if ((prev = res[i] > '9'))
			res[i] -= 10;
	}
	if (prev && res[0] == 0)
		res[0] = '1';
	else if (res[0] == 0 || res[0] == '0')
		res = strshift(&res, 1);
	if (f)
		ft_strdel(s1);
	return (res);
}

char		*add_frac(char **s1, char *s2)
{
	char	*res;
	int		len1;
	int		len2;
	int		prev;

	if (!s1 || !s2 || !*s1)
		return (NULL);
	len1 = ft_strlen(*s1);
	len2 = ft_strlen(s2);
	if (!(res = ft_strdup(len1 > len2 ? *s1 : s2)))
		return (NULL);
	len1 = len1 > len2 ? len2 : len1;
	prev = 0;
	while (res[--len1] != '.')
	{
		res[len1] = (*s1)[len1] + s2[len1] - '0' + prev;
		if ((prev = res[len1] > '9'))
			res[len1] -= 10;
	}
	ft_strdel(s1);
	return (res);
}
