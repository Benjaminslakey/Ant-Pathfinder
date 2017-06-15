/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 10:52:59 by bslakey           #+#    #+#             */
/*   Updated: 2016/11/16 12:43:24 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t size)
{
	t_list	*node;

	node = (t_list*)malloc(sizeof(t_list));
	MEM_GUARD(node);
	if (content == NULL)
	{
		node->content_size = 0;
		node->content = NULL;
	}
	else
	{
		node->content = (void *)malloc(size);
		MEM_GUARD((node->content));
		ft_memcpy((node->content), content, size);
		node->content_size = size;
	}
	node->next = NULL;
	return (node);
}
