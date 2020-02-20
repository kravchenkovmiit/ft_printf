#include "printf.h"

int 	inicialise_foos(char **conv, int **foo_type)
{
	*conv = "cspdiouxXf%";
	foo_type[0] = (int *) &c_type;
	foo_type[1] = (int *) &s_type;
	foo_type[2] = (int *) &p_type;
	foo_type[3] = (int *) &d_type;
	foo_type[4] = (int *) &d_type;
	foo_type[5] = (int *) &o_type;
	foo_type[6] = (int *) &u_type;
	foo_type[7] = (int *) &x_type;
	foo_type[8] = (int *) &X_type;
	foo_type[9] = (int *) &f_type;
	foo_type[10] = (int *) &perc_type;
	foo_type[11] = (int *) &lf_type;
	return (1);
}

int 	inicialise_flags(char **flags, int *f_type)
{
	int	i;

	i = -1;
	*flags = "#0-+ ";
	while (++i < 14)
		f_type[i] = 0;
	f_type[11] = -1;
	return (1);
}

int		process_conv(va_list args, char *str, int *i, int j)
{
	int		f_sz;
	char	*conv;
	char	*flags;
	int 	(*foo_type[12])(va_list, int *);
	int		f_type[14];

	inicialise_foos(&conv, (int **) foo_type);
	inicialise_flags(&flags, f_type);
	if ((f_sz = check_flags(conv, flags, f_type, str)) == -1)
		return (-1);
	check_f_asterix(args, f_type);
	while (j++ < 11)
	{
		if (*(str + f_sz) == conv[j])
		{
			if (conv[j] == 'f' && f_type[10])
			{
				*i += foo_type[11](args, f_type);
				break ;
			}
			*i += foo_type[j](args, f_type);
			break ;
		}
	}
	return (f_sz);
}

int		process_format(va_list args, char *str, int *sz)
{
	int		i;
	int 	j;
	char	*buffer;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1] == '\0')
			return (-1);
		else if (str[i] == '%' && (*sz += i) >= 0)
		{
			buffer = ft_strnew(i);
			buffer = ft_strncpy(buffer , str, i);
			ft_putstr(buffer);
			free(buffer);
			if ((j = process_conv(args, str + i + 1, sz, -1)) == -1)
				return (-1);
			str = str + i + j + 2;
			i = -1;
		}
	}
	buffer = ft_strncpy((buffer = ft_strnew(i)), str, i);
	ft_putstr(buffer);
	free(buffer);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list args;
	char    *str;
	int     sz;
	int		i;

	va_start(args, format);
	sz = 0;
	str = (char*)format;
	if ((i = process_format(args, str, &sz)) == -1)
		return (-1);
	sz += i;
	va_end(args);
	return (sz);
}