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
	t_adj		*adj;

	adj = lst->first;
	while (adj != NULL)
	{
		if (adj->adj_vert == search_for)
			return (true);
		adj = adj->next;
	}
	return (false);
}

void			free_adjlist(t_adjlist **list)
{
	t_adj		*curr;
	t_adj		*prev;

	prev = NULL;
	curr = (*list)->first;
	while (curr != NULL)
	{
		if (prev != NULL)
			free(prev);
		prev = curr;
		curr = curr->next;
	}
	free(curr);
	free(*list);
	list = NULL;
}

void			destroy_graph(t_graph **graph)
{
	int			i;
	t_vert		*temp;

	i = -1;
	while (++i < (*graph)->n_vertices)
	{
		temp = (*graph)->vertices[i];
		free(temp->vname);
		free_adjlist(&(temp->lst));
		free((*graph)->vertices[i]);
	}
	free(*graph);
	graph = NULL;
}
