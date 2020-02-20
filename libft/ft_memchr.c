/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:19:46 by hvalenci          #+#    #+#             */
/*   Updated: 2019/09/11 19:54:35 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *t;
	unsigned char ch;

	t = (unsigned char *)s;
	ch = (unsigned char)c;
	while (n--)
	{
		if (*t == ch)
			return (t);
		t++;
	}
	return (NULL);
}
