/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:00:04 by hvalenci          #+#    #+#             */
/*   Updated: 2019/09/14 17:36:40 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	fresh = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (fresh == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		fresh[i] = (char)s1[i];
		i++;
	}
	while (i + j < ft_strlen(s2) + ft_strlen(s1))
	{
		fresh[i + j] = (char)s2[j];
		j++;
	}
	return (fresh);
}
