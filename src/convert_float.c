/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:41:59 by hvalenci          #+#    #+#             */
/*   Updated: 2020/02/21 16:37:09 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*handle_mantissa_if_e_less_zero(t_float *fdb)
{
	char	*res;

	if (!(res = ft_joinstr_pf(fdb->mantissa, '0', -(fdb->exp))))
		return (NULL);
	res[1] = '.';
	res[-(fdb->exp) + 1] = '1';
	if (fdb->exp != -1 && fdb->exp != 1)
		res[-(fdb->exp)] = '0';
	free(fdb->mantissa);
	fdb->mantissa = res;
	return (res);
}

char		*handle_mantissa(t_float *fdb)
{
	char	*res;
	int		l;

	if (fdb->sign == 0 && fdb->exp == -1023 && !ft_strcmp(fdb->mantissa, "1."))
	{
		free(fdb->mantissa);
		fdb->mantissa = ft_strdup("0.0");
	}
	else if (fdb->exp < 0)
		handle_mantissa_if_e_less_zero(fdb);
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

char		*get_btofr(char *s)
{
	char	*res;
	char	*tmp;
	int		i;

	tmp = ft_strdup(".0");
	res = ft_strdup(".0");
	i = 0;
	while (s[++i])
	{
		tmp = s_division(&tmp);
		if (s[i] == '1')
			res = add_frac(&res, tmp);
	}
	free(tmp);
	return (res);
}

char		*get_btoi(char *s)
{
	char	*res;
	char	*tmp;
	char	*t;
	int		i;

	i = ft_strlen(s);
	t = ft_strdup("1");
	res = ft_strdup("0");
	while (--i >= 0)
	{
		if (s[i] == '1')
			res = add_int(&res, t, 1);
		tmp = add_int(&t, t, 0);
		free(t);
		t = tmp;
	}
	free(t);
	return (res);
}

char		*strshift(char **s, size_t n)
{
	char	*res;

	if (!s || !(*s))
		return (NULL);
	if (!(res = ft_strsub(*s, n, ft_strlen(*s) - n)))
		return (NULL);
	free(*s);
	*s = NULL;
	return (res);
}
