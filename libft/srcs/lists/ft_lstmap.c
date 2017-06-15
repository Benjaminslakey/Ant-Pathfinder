/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 05:06:01 by bslakey           #+#    #+#             */
/*   Updated: 2016/10/04 01:26:16 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *map_head;
	t_list *map_curr;

	MEM_GUARD(lst);
	MEM_GUARD((t_list*)f);
	map_curr = (*f)(lst);
	MEM_GUARD(map_curr);
	map_head = map_curr;
	while (lst->next != NULL)
	{
		lst = lst->next;
		map_curr->next = (*f)(lst);
		map_curr = map_curr->next;
	}
	return (map_head);
}
