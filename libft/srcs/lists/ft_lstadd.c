/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 23:26:27 by bslakey           #+#    #+#             */
/*   Updated: 2016/10/01 06:58:34 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstadd(t_list **alst, t_list *l_new)
{
	t_list *head;

	if (!(*alst))
		*alst = l_new;
	else
	{
		head = *alst;
		l_new->next = head;
		*alst = l_new;
	}
}
