/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimum_heap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 07:35:29 by bslakey           #+#    #+#             */
/*   Updated: 2017/06/09 11:59:11 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_heap 			*build_heap(int capacity)
{
	t_heap 		*heap;
	t_vert 		**vertices;

	heap = (t_heap*)malloc(sizeof(t_heap));
	vertices = (t_vert**)malloc(sizeof(t_vert) * capacity);
	heap->arr = vertices;
	heap->size = 0;
	heap->capacity = capacity;
	return (heap);
}

void 			destroy_heap(t_heap **heap)
{
	free((*heap)->arr);
	free(*heap);
	heap = NULL;
}

void 			mheap_swap(t_heap *heap, int n, int m)
{
	t_vert 		*temp;

	temp = heap->arr[n];
	heap->arr[n] = heap->arr[m];
	heap->arr[m] = temp;
}

void			heapify_up(t_heap *heap, int n)
{
	t_vert 		**h;

	h = heap->arr;
	if (n != ROOT)
	{
		if (h[n]->dval < h[PARENT(n)]->dval)
		{
			mheap_swap(heap, n, PARENT(n));
			heapify_up(heap, PARENT(n));
		}
	}
}

void 			heapify_down(t_heap *heap, int n)
{
	int 		child;
	t_vert 		**h;

	h = heap->arr;
	child = 0;
	if (!ISLEAF(n, heap->size))
	{
		if (h[n]->dval > h[LCHILD(n)]->dval || h[n]->dval > h[RCHILD(n)]->dval)
		{
			child =
			(h[LCHILD(n)]->dval < h[RCHILD(n)]->dval) ? LCHILD(n) : RCHILD(n);
            mheap_swap(heap, n, child);
			heapify_down(heap, child);
		}
	}
}