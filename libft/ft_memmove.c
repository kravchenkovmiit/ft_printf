/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:05:56 by hvalenci          #+#    #+#             */
/*   Updated: 2019/09/13 18:18:19 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*res;
	unsigned char	*s;
	size_t			i;

	i = 0;
	if (dst == NULL && src == NULL && len > 0)
		return (NULL);
	s = (unsigned char *)src;
	res = (unsigned char *)dst;
	if (dst > src)
	{
		while (len--)
			res[len] = s[len];
	}
	else
	{
		while (len--)
		{
			res[i] = s[i];
			i++;
		}
	}
	return (dst);
}
