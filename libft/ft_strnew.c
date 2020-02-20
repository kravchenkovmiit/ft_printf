/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 19:41:16 by hvalenci          #+#    #+#             */
/*   Updated: 2019/09/10 20:50:11 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*fresh;

	if (size + 1 == 0)
		return (NULL);
	fresh = ft_memalloc(size + 1);
	if (fresh == NULL)
		return (NULL);
	return (fresh);
}
