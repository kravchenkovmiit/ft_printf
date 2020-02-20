/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 22:40:14 by hvalenci          #+#    #+#             */
/*   Updated: 2019/09/10 18:59:09 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *tmp1;
	unsigned char *tmp2;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	while (*tmp1)
	{
		if (*tmp1 - *tmp2 == 0)
		{
			tmp1++;
			tmp2++;
		}
		else
			break ;
	}
	return (*tmp1 - *tmp2);
}
