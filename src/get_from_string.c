#include "printf.h"

/*
** Flags:
**  #		- 0
**  0		- 1
**  -		- 2
**  +		- 3
** " "		- 4
** width	- 5
** Length:
** hh		- 6
** h		- 7
** l		- 8
** ll		- 9
** L		- 10
** prec		- 11
** *_width	- 12
** *_prec	- 13
*/

int		check_flags(char *conv, char *flags, int *f_type, char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (k < 5)
	{
		while (k < 5 && str[i] != flags[k])
			k++;
		if (str[i] == flags[k] && str[i] != '\0' && (f_type[k] = 1) && (k = 0) == 0)
			i++;
		else if (ft_isdigit(str[i]))
			i += get_width(str + i, f_type, &k);
		else if (str[i] == '.' && (k = 0) == 0)
			i += get_precision(str + i + 1, f_type, &k);
		else if (str[i] == '*' && (k = 0) == 0 && (++i))
			f_type[12] = 1;
		else if (str[i] == 'l' || str[i] == 'h' || str[i] == 'L')
			i += get_l_type(f_type, str + i, &k);
		else if (!get_conversion(str[i], conv))
			break ;
		else
			return (-1);
	}
	check_wildcard(f_type);
	return (i);
}

int		get_conversion(char s, char *conv)
{
	int	j;

	j = 0;
	while (j < 11)
	{
		if (s == conv[j])
			return (0);
		j++;
	}
	return (1);
}

int		get_width(char *str, int *f_type, int *k)
{
	int	i;

	i = 0;
	*k = 0;
	f_type[5] = pf_atoi(str);
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

int		get_precision(char *str, int *f_type, int *k)
{
	int	i;

	i = 0;
	*k = 0;
	if (*str == '*' && (++i))
	{
		f_type[13] = 1;
	}
	else if (ft_isdigit(*str))
	{
		f_type[11] = pf_atoi(str);
		while (ft_isdigit(str[i]))
			i++;
	}
	else
		f_type[11] = 0;
	return (i + 1);
}

int		get_l_type(int *f_type, char *s, int *k)
{
	*k = 0;
	if (*s == 'h')
	{
		if (*(s + 1) == 'h' && (f_type[6] = 1))
			return (2);
		f_type[7] = 1;
	}
	else if (*s == 'l')
	{
		if (*(s + 1) == 'l' && (f_type[9] = 1))
			return (2);
		f_type[8] = 1;
	}
	else
		f_type[10] = 1;
	return (1);
}