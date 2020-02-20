/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:00:46 by hvalenci          #+#    #+#             */
/*   Updated: 2019/09/18 20:20:34 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft.h"

static int	ft_counter(char const *s, char c)
{
	while (*s && *s != c)
		s++;
	if (*s == '\0')
		return (0);
	while (*s && *s == c)
		s++;
	if (*s == '\0')
		return (0);
	return (1 + ft_counter(s, c));
}

static char	*ft_skipc(char *s, char c)
{
	while (*s == c)
		s++;
	return (s);
}

static char	**ft_arrfiller(char const *s, char c, size_t strnum, char **fresh)
{
	char	*tmp;
	size_t	i;
	size_t	j;

	j = 0;
	tmp = ft_skipc((char *)s, c);
	while (strnum--)
	{
		if (*tmp != c)
		{
			i = 0;
			while (tmp[i] && tmp[i] != c)
				i++;
			if (!(fresh[j] = ft_strnew(i)))
			{
				ft_arrdel(fresh, j);
				return (NULL);
			}
			ft_strncpy(fresh[j], tmp, i);
			tmp += i;
			j++;
		}
		tmp = ft_skipc(tmp, c);
	}
	return (fresh);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t	strnum;
	char	**fresh;

	if (c == '\0' || s == NULL)
		return (NULL);
	if (*s == '\0')
	{
		if (!(fresh = ft_arrnew(1)))
			return (NULL);
		fresh[0] = NULL;
		return (fresh);
	}
	strnum = 0;
	if (*s != c)
		strnum = 1;
	strnum += ft_counter(s, c);
	if (!(fresh = ft_arrnew(strnum)))
		return (NULL);
	fresh = ft_arrfiller(s, c, strnum, fresh);
	return (fresh);
}
