/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 07:35:29 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/09 16:51:02 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_heap			*init_min_queue(t_graph *graph, int src)
{
	int			i;
	t_heap		*min_queue;

	i = -1;
	min_queue = build_heap(graph->n_vertices * 2);
	while (++i < graph->n_vertices)
	{
		if (i == src)
			insert_w_priority(min_queue, (graph->vertices)[i], 0);
		else
			insert_w_priority(min_queue, (graph->vertices)[i], INFINITY);
	}
	return (min_queue);
}

void			insert_w_priority(t_heap *heap, t_vert *v, int priority)
{
	t_vert		**h;
	int			n;

	v->dval = priority;
	v->visited = false;
	v->prev = -1;
	n = ++(heap->size);
	h = heap->arr;
	h[n] = v;
	heapify_up(heap, n);
}

void			decrease_key(t_heap *heap, t_vert *v, int new_key)
{
	int			n;

	n = 0;
	if (new_key > v->dval)
		return ;
	while (++n < heap->size && heap->arr[n]->v_ind != v->v_ind)
		;
	if (n > heap->size)
		return ;
	v->dval = new_key;
	heapify_up(heap, n);
}

t_vert			*extract_min(t_heap *heap)
{
	t_vert		**h;
	t_vert		*v;

	v = NULL;
	h = heap->arr;
	if (heap->size == 0)
		return (v);
	v = h[ROOT];
	h[ROOT] = h[(heap->size)--];
	h[heap->size + 1] = NULL;
	if (heap->size != 0)
		heapify_down(heap, ROOT);
	return (v);
}
