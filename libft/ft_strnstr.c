/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:57:29 by hvalenci          #+#    #+#             */
/*   Updated: 2019/09/14 16:13:08 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	char	*res;
	char	*fnd;
	size_t	i;
	size_t	j;

	i = 0;
	res = (char *)haystack;
	fnd = (char *)needle;
	if (!(*fnd))
		return (res);
	while (res[i] && i < n)
	{
		j = 0;
		while (res[i + j] - fnd[j] == 0 && (i + j) < n)
		{
			j++;
			if (fnd[j] == '\0')
				return (res + i);
		}
		i++;
	}
	return (NULL);
}
