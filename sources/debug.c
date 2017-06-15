/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 07:35:29 by bslakey           #+#    #+#             */
/*   Updated: 2017/06/07 14:36:06 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <stdio.h>

void 					print_heap(t_heap *heap)
{
	t_vert 				*temp;
	int 				i;

	i = -1;
	temp = NULL;
	while (++i < heap->size)
	{
		temp = heap->arr[i + 1];
		printf("heap->arr[%d] is vertex #: %d\n", i + 1, temp->v_ind);
		printf("\tprev: %d", temp->prev);
		printf("\tdval: %d", temp->dval);
		if (temp->visited == true)
			printf("\tvisited: true\n");
		else
			printf("\tvisited: false\n");
		if (temp->occupied == true)
			printf("visited: true\n");
	}
}

void 					print_path(t_path *path)
{
	int 				i;

	i = -1;
	printf("path length: %d\n", path->len);
	while (++i < path->len)
	{
		printf("%d", (path->arr)[i]);
		if (i + 1 != path->len)
			printf("-->>");
	}
}

void 					print_graph(t_graph *graph)
{
	t_vert 				*temp;
	int 				i;

	i = -1;
	temp = NULL;
	printf("\n\ngraph\n");
	while (++i < graph->n_vertices)
	{
		temp = (graph->vertices)[i];
		printf("vertex name: %s, vertex # %d:\n", temp->vname, temp->v_ind);
		printf("\tprev: %d", temp->prev);
		printf("\tdval: %d", temp->dval);
		if (temp->visited == true)
			printf("\tvisited: true\n");
		else
			printf("\tvisited: false\n");
		if (temp->occupied == true)
			printf("occupied: true\n");
        else
            printf("occupied: false\n");
	}
	printf("\n");
}
