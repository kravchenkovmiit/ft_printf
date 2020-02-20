/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:42:11 by hvalenci          #+#    #+#             */
/*   Updated: 2019/09/16 18:50:34 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*fresh;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	fresh = ft_strnew(len);
	if (fresh == NULL)
		return (NULL);
	i = 0;
	while (len--)
	{
		fresh[i] = (char)s[(start + i)];
		i++;
	}
	return (fresh);
}
