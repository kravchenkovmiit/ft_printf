/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvalenci <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 18:40:26 by hvalenci          #+#    #+#             */
/*   Updated: 2019/09/19 18:54:19 by hvalenci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin_lst;
	t_list	*tmp;

	if (lst == NULL)
		return (NULL);
	begin_lst = f(lst);
	if (begin_lst == NULL)
	{
		free(begin_lst);
		return (NULL);
	}
	tmp = begin_lst;
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = f(lst);
		if (tmp->next == NULL)
		{
			free(tmp->next);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (begin_lst);
}
