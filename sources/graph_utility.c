/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <benjaminslakey@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:42:07 by bslakey           #+#    #+#             */
/*   Updated: 2017/06/07 13:51:46 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

bool			in_adjlist(t_adjlist *lst, int search_for)
{
	t_adj 		*adj;

	adj = lst->first;
	while (adj != NULL)
	{
		if (adj->adj_vert == search_for)
			return (true);
		adj = adj->next;
	}
	return (false);
}
