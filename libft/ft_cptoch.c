/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cptoch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 15:40:52 by hvalenci          #+#    #+#             */
/*   Updated: 2020/02/21 16:38:32 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_cptoch(char *s, int c)
{
	char	*res;
	char	*smb;

	if (!s)
		return (NULL);
	if (!(smb = ft_strchr(s, c)))
		return (NULL);
	if (!(res = ft_strnew(smb - s)))
		return (NULL);
	res = ft_strncpy(res, s, smb - s);
	return (res);
}
