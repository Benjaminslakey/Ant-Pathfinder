/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 07:35:29 by bslakey           #+#    #+#             */
/*   Updated: 2017/06/07 14:34:56 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_adj			*new_adj(int vert_index, int adjacent_vert, int cost)
{
	t_adj		*adj;

	MEM_GUARD((adj = (t_adj*)malloc(sizeof(t_adj))));
	adj->vertex = vert_index;
	adj->adj_vert = adjacent_vert;
	adj->cost = cost;
	adj->next = NULL;
	return (adj);
}

int				adjlst_add(t_adjlist *head, t_adj *new)
{
	t_adj			*temp;

	temp = NULL;
	ERR_GUARD((head == NULL), ERR);
	ERR_GUARD(new == NULL, ERR);
	if (head->first == NULL)
		head->first = new;
	else
	{
		temp = head->first;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	return (SUCCESS);
}

t_adjlist		*create_adjlist(int v_ind, int ne, int **e)
{
	t_adjlist	*head;
	t_adj		*temp;
	int			c;
	int			v;

	c = -1;
	v = 0;
	head = (t_adjlist*)malloc(sizeof(t_adjlist));
	head->first = NULL;
	while (++c < ne)
	{
		if ((e[c][0] == v_ind || e[c][1] == v_ind))
		{
			v = (e[c][0] == v_ind) ? e[c][1] : e[c][0];
			MEM_GUARD((temp = new_adj(v_ind, v, 1)));
			ERR_GUARD((adjlst_add(head, temp)) == ERR, NULL);
		}
	}
	return (head);
}

t_vert			*new_vertex(int nv, char *n, int ne, int **e)
{
	t_vert		*vert;

	MEM_GUARD((vert = (t_vert*)malloc(sizeof(t_vert))));
	vert->v_ind = nv;
	vert->vname = ft_strdup(n);
	vert->lst = create_adjlist(nv, ne, e);
	vert->dval = INFINITY;
	vert->prev = -1;
	vert->visited = false;
	vert->occupied = false;
	return (vert);
}

t_graph			*create_graph(int nv, char **vlist, int ne, int **e)
{
	int			v;
	t_vert		**vertices;
	t_graph		*graph;

	v = -1;
	MEM_GUARD((graph = (t_graph*)malloc(sizeof(t_graph))));
	MEM_GUARD((vertices = (t_vert**)malloc(sizeof(t_vert*) * nv)));
	while (vlist[++v])
		vertices[v] = new_vertex(v, vlist[v], ne, e);
	graph->vertices = vertices;
	graph->n_vertices = nv;
	graph->n_edges = ne;
	return (graph);
}
