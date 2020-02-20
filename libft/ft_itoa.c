/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:28:11 by hvalenci          #+#    #+#             */
/*   Updated: 2019/09/14 20:39:54 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int tmp)
{
	int	i;

	i = 1;
	if (tmp < 0)
		i++;
	while ((tmp = tmp / 10) != 0)
		i++;
	return (i);
}

char		*ft_itoa(int n)
{
	int			i;
	int			j;
	long int	num;
	char		*fresh;

	num = (long int)n;
	i = ft_count(n);
	fresh = ft_strnew(i);
	if (fresh == NULL)
		return (NULL);
	j = 0;
	if (num < 0)
	{
		fresh[0] = '-';
		num *= -1;
		j++;
	}
	while (j < ft_count(n))
	{
		fresh[--i] = (num % 10) + '0';
		num = num / 10;
		j++;
	}
	return (fresh);
}
