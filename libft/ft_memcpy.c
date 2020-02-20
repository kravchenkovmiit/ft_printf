/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:29:08 by hvalenci          #+#    #+#             */
/*   Updated: 2019/09/11 19:16:41 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*res;
	unsigned char	*s;
	size_t		i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	res = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
	{
		res[i] = s[i];
		i++;
	}
	return (dst);
}
