/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:48:59 by hvalenci          #+#    #+#             */
/*   Updated: 2019/09/09 23:59:12 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	pf_neg(const char *c)
{
	if (*c == '-')
		return (-1);
	return (1);
}

int			pf_atoi(const char *str)
{
	unsigned long long int	t;
	int						neg;

	t = 0;
	neg = 1;
	while (*str && ft_isspace((int)*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		neg = pf_neg(str);
		str++;
	}
	while (*str == '0')
		str++;
	while (ft_isdigit(*str))
	{
		t = t * 10 + (unsigned long long int)(*str - '0');
		if (t > 9223372036854775807 && neg < 0)
			return (0);
		else if (t > 9223372036854775806 && neg > 0)
			return (-1);
		str++;
	}
	t = t * neg;
	return ((int)t);
}
