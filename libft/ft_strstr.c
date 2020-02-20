/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:00:53 by hvalenci          #+#    #+#             */
/*   Updated: 2019/09/20 18:14:27 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char *)haystack;
	if (!(*needle))
		return (res);
	while (res[i])
	{
		if (res[i] - *needle == 0)
			if (ft_strncmp(res + i, needle, ft_strlen(needle)) == 0)
				return (res + i);
		i++;
	}
	return (NULL);
}
