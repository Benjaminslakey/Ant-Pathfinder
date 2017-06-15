/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 23:27:25 by bslakey           #+#    #+#             */
/*   Updated: 2016/10/01 06:49:44 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *curr;
	t_list *next;

	curr = *alst;
	while (curr != NULL)
	{
		next = curr->next;
		(*del)(curr->content, curr->content_size);
		free(curr);
		curr = next;
	}
	*alst = NULL;
}
