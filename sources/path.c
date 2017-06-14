/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 07:35:29 by bslakey           #+#    #+#             */
/*   Updated: 2017/06/07 14:35:30 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <stdio.h>

t_path					*init_path(int capacity)
{
	t_path				*path;

	path = (t_path*)malloc(sizeof(t_path));
	path->arr = (int*)malloc(sizeof(int) * capacity);
	path->len = 0;
	path->maxlen = capacity;
	return (path);
}

void					free_path(t_path **path)
{
	free((*path)->arr);
	free(*path);
	path = NULL;
}

t_path					*build_path(t_graph *graph, int src, int target)
{
	int					n;
	t_vert				*temp;
	t_path				*path;

	n = -1;
	path = init_path(graph->n_vertices);
	temp = (graph->vertices)[target];
	src++;
	while (++n < path->maxlen)
	{
		path->arr[n] = temp->v_ind;
		if (temp->prev == -1)
			break ;
		temp = (graph->vertices)[temp->prev];
	}
	path->len = n + 1;
	array_reverse_int(path->arr, path->len);
	return (path);
}

int						test_path(t_lem_in *o)
{
	int					err;
	t_path				*path;

	err = SUCCESS;
	path = dijkstras(o->ant_farm, o->source, o->dest);
	if (o->ant_farm->vertices[o->dest]->prev == -1)
		err = ERR;
	return (err);
}
