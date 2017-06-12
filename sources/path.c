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

void 					array_reverse_int(int *arr, int size)
{
	int 				i;
	int 				j;
	int 				temp;

	i = -1;
	j = size;
	while (++i < --j)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}


t_path 					*init_path(int capacity)
{
	t_path 				*path;

	path = (t_path*)malloc(sizeof(t_path));
	path->arr = (int*)malloc(sizeof(int) * capacity);
	path->len = 0;
	path->maxlen = capacity;
	return (path);
}

t_path 					*build_path(t_graph *graph, int src, int target)
{
	int 				n;
	t_vert 				*temp;
	t_path 				*path;

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
