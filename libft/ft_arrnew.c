/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:45:08 by hvalenci          #+#    #+#             */
/*   Updated: 2019/09/18 18:57:32 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_arrnew(size_t len)
{
	char	**fresh;
	size_t	i;

	i = 0;
	if (len + 1 == 0)
		return (NULL);
	fresh = (char **)malloc(sizeof(char *) * (len + 1));
	if (fresh == NULL)
		return (NULL);
	while (len--)
	{
		fresh[i] = 0;
		i++;
	}
	fresh[i] = 0;
	return (fresh);
}
