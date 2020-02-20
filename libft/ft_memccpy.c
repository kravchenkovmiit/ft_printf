/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 18:36:07 by hvalenci          #+#    #+#             */
/*   Updated: 2019/09/13 19:51:09 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*res;
	unsigned char	*s;
	unsigned char	ch;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	res = (unsigned char *)dst;
	s = (unsigned char *)src;
	ch = (unsigned char)c;
	while (n--)
	{
		res[i] = s[i];
		if (s[i] == ch)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
