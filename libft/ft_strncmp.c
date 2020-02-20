/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:20:19 by hvalenci          #+#    #+#             */
/*   Updated: 2019/09/18 21:07:49 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*fst;
	unsigned char	*snd;
	size_t			i;

	i = 0;
	if (!(n))
		return (0);
	fst = (unsigned char *)s1;
	snd = (unsigned char *)s2;
	while (fst[i])
	{
		if (fst[i] - snd[i] == 0 && i < n - 1)
			i++;
		else
			break ;
	}
	return (fst[i] - snd[i]);
}
