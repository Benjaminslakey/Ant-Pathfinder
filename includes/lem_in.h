/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 07:35:29 by bslakey           #+#    #+#             */
/*   Updated: 2017/06/07 15:06:49 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include <limits.h>

# define PARENT(i) (i/2)
# define LCHILD(i) (i * 2)
# define RCHILD(i) (i * 2 + 1)
# define ISLEAF(i, size) ((i >= size / 2) && (i <= size))
# define ROOT 1

# define ERR -1
# define SUCCESS 0

# define INFINITY (INT_MAX - 1)

/* ************************************************************************** */
/** 						graph structures								  */
/* ************************************************************************** */

typedef struct			s_adj
{
	int					vertex;
	int					adj_vert;
	int					cost;
	struct s_adj		*next;
}						t_adj;

typedef struct			s_adjlist
{
	int					total;
	t_adj				*first;
}						t_adjlist;

typedef struct			s_vert
{
	char				*vname;
	int					v_ind;
	int					dval;
	int					prev;
	bool				visited;
	bool				occupied;
	t_adjlist			*lst;
}						t_vert;

typedef struct			s_graph
{
	int					n_vertices;
	int					n_edges;
	t_vert				**vertices;
}						t_graph;

/* ************************************************************************** */

/* ************************************************************************** */
/** 						minimum priority queue							  */
/* ************************************************************************** */

typedef struct			s_heap
{
	int					capacity;
	int					size;
	t_vert				**arr;
}						t_heap;

/* ************************************************************************** */

/* ************************************************************************** */
/** 						program data object								  */
/* ************************************************************************** */

typedef struct			s_path
{
	int					maxlen;
	int					len;
	int					*arr;
}						t_path;

typedef struct			s_ant
{
	int 				id;
	int					location;
	int					move_to;
}						t_ant;

typedef struct			s_lem_in
{
	char				*start;
	int					source;
	char				*end;
	int					dest;
	int					n_ants;
	t_ant				**ants;
	int					nlinks;
	int					**links;
	int					nrooms;
	char				**rooms;
	t_graph				*ant_farm;
}						t_lem_in;

/* ************************************************************************** */

/* ************************************************************************** */
/** 						data structure functions						  */
/* ************************************************************************** */

t_graph					*create_graph(int nv, char **v, int ne, int **edges);
void                    destroy_graph(t_graph **graph);
t_vert 					*new_vertex(int nv, char *n, int ne, int **e);
t_adjlist 				*create_adjlist(int v_ind, int ne, int **e);
t_adj 					*new_adj(int vert_index, int adjacent_vert, int cost);
int 					adjlst_add(t_adjlist *head, t_adj *new);
bool					in_adjlist(t_adjlist *lst, int search_for);

t_heap 					*build_heap(int capacity);
void 					destroy_heap(t_heap **heap);
void 					mheap_swap(t_heap *heap, int n, int m);
void 					heapify_up(t_heap *heap, int n);
void 					heapify_down(t_heap *heap, int n);

t_heap 					*init_min_queue(t_graph *graph, int src);
void 					insert_w_priority(t_heap *heap, t_vert *v, int prio);
void 					decrease_key(t_heap *heap, t_vert *v, int new_key);
t_vert 					*extract_min(t_heap *heap);

/* ************************************************************************** */
/** 						program setup									  */
/* ************************************************************************** */
/* parsing, err checking, initialization */

char					**fgetc_stdin(void);
int						errchk_input(char **file_arr);
int 	    			parse_file(char **file_arr, t_lem_in *program);
int 					errchk_input(char **file);
int 					chk_comm(char *command);
int 					chk_linkformat(char *link);
int 					chk_roomformat(char *room);
int                     test_path(t_lem_in *prog);

/* ************************************************************************** */
/** 						pathfinding										  */
/* ************************************************************************** */
/* single source single destination dijkstra's using a min priority queue */

t_path 					*dijkstras(t_graph *graph, int src, int target);
void 					relax_all_edges(t_graph *graph, t_vert *u);


void					find_paths(t_lem_in *prog);
t_path					*init_path(int capacity);
t_path 					*build_path(t_graph *graph, int src, int target);
void                    free_path(t_path **path);
void					init_ants(t_lem_in *prog);
void                    free_ants(t_ant ***ants, int num_ants);
void					route_ants(t_lem_in *prog);
void 					determine_next_move(t_lem_in *prog, int ant_num);
void					move_ant(t_lem_in *prog, t_ant *ant);
bool					goal_reached(t_lem_in *prog);


/*
* output functions
* error printing, data to output conversion, print data
*/

void                    print_antfarm(t_lem_in *o);
int 					print_error(int err);
void 					print_heap(t_heap *heap);
void 					print_graph(t_graph *graph);
void 					print_path(t_path *path);
void 					print_moves(t_lem_in *prog, t_ant *ant);

/* ************************************************************************* */
/* 							utility functions 								 */
/* ************************************************************************* */

void 		    		clear_memory(char ***file, t_lem_in **obj);
#endif