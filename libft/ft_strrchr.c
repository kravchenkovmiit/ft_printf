/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:42:45 by hvalenci          #+#    #+#             */
/*   Updated: 2019/09/18 21:21:38 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*res;
	size_t	i;

	res = ft_strchr(s, c);
	i = 0;
	if (res == NULL)
		return (NULL);
	while (*res)
	{
		i++;
		if (*res == (char)c)
			i = 0;
		res++;
	}
	if ((char)c == '\0')
		return (res++);
	if (i)
		return (res - (i + 1));
	return (res - 1);
}
