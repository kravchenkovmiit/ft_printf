#include "printf.h"

t_lfloat	*get_lfdb(long double d)
{
	__uint128_t	*nb;
	int			i;
	int			l;
	t_lfloat	*res;

	nb = (__uint128_t *)&d;
	if (!(res = (t_lfloat *)malloc(sizeof(t_lfloat))))
		return (NULL);
	res->sign = d < 0;
	if ((res->exp = (((*nb) << 49 >> 49) >> 64) - 16383) == 16384)
		return (res);
	i = 0;
	while (((*nb) >> i & 1) != 1 && i < 63)
		++i;
	l = 63 - i;
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

static char	*handle_lmantissa_if_e_less_zero(t_lfloat *fdb)
{
	char	*res;

	if(!(res = ft_joinstr_pf(fdb->mantissa, '0', -(fdb->exp))))
		return (NULL);
	res[1] = '.';
	res[-(fdb->exp) + 1] = '1';
	if (fdb->exp != -1 && fdb->exp != 1)
		res[-(fdb->exp)] = '0';
	free(fdb->mantissa);
	fdb->mantissa = res;
	return (res);
}

char		*handle_lmantissa(t_lfloat *fdb)
{
	char	*res;
	int	 l;

	if (fdb->sign == 0 && fdb->exp == -32767 && !ft_strcmp(fdb->mantissa, "1."))
	{
		free(fdb->mantissa);
		fdb->mantissa = ft_strdup("0.0");
	}
	else if (fdb->exp < 0)
		handle_lmantissa_if_e_less_zero(fdb);
	else if (fdb->exp > 0)
	{
		if (!(res = ft_strjoin_pf(fdb->mantissa, '0',
				fdb->exp - ft_strlen(fdb->mantissa) + 3)))
			return (NULL);
		free(fdb->mantissa);
		fdb->mantissa = res;
		l = 1;
		while ((fdb->exp)-- > 0)
		{
			res[l] = res[l + 1];
			res[l++ + 1] = '.';
		}
	}
	return (fdb->mantissa);
}
