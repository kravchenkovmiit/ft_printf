/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_pf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:43:16 by hvalenci          #+#    #+#             */
/*   Updated: 2020/02/21 16:30:54 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strjoin_pf(char *s1, char c, int n)
{
	char	*fresh;
	size_t	i;

	i = -1;
	if (!s1 || !(*s1))
		return (NULL);
	if (n <= 0)
		return (ft_strdup(s1));
	fresh = ft_strnew(ft_strlen(s1) + n);
	if (fresh == NULL)
		return (NULL);
	while (s1[++i])
		fresh[i] = s1[i];
	while (n--)
		fresh[i++] = c;
	return (fresh);
}

char	*ft_strjoin_pf_2(char **s1, char c)
{
	char	*fresh;

	if (!s1 || !(*s1))
		return (NULL);
	if (!(fresh = ft_strnew(ft_strlen(*s1) + 1)))
		return (NULL);
	fresh = ft_strcpy(fresh, *s1);
	fresh = ft_strncat(fresh, &c, 1);
	free(*s1);
	*s1 = NULL;
	return (fresh);
}

char	*ft_joinstr_pf(char *s1, char c, int n)
{
	char	*fresh;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 || !(*s1))
		return (NULL);
	if (n < 0)
		return (ft_strdup(s1));
	fresh = ft_strnew(ft_strlen(s1) + n);
	if (fresh == NULL)
		return (NULL);
	while (n--)
		fresh[++j] = c;
	while (s1[++i])
		fresh[++j] = s1[i];
	return (fresh);
}
