/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 07:35:29 by bslakey           #+#    #+#             */
/*   Updated: 2017/06/09 11:58:32 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

// unfinished

void 					relax_edges(t_graph *g, t_heap *q, t_vert *u)
{
	int 				dist;
	t_adj 				*adj;
	t_vert 				*temp;

	dist = 0;
	temp = NULL;
	adj = (u->lst)->first;
	while (adj != NULL)
	{
		temp = (g->vertices)[adj->adj_vert];
		if (temp->visited == false)
		{
			temp->visited = true;
			temp->prev = u->v_ind;
			dist = u->dval + adj->cost;
			if (dist < temp->dval)
				decrease_key(q, temp, dist);
		}
		adj = adj->next;
	}
}

t_path					*dijkstras(t_graph *graph, int src, int target)
{
	t_heap				*q;
	t_vert				*u;
	t_path				*path;

	q = init_min_queue(graph, src);
	graph->vertices[src]->visited = true;
	while (q->size > 0)
	{
		u = extract_min(q);
		relax_edges(graph, q, u);
	}
	destroy_heap(&q);
	path = build_path(graph, src, target);
	return (path);
}
