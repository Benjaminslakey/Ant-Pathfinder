/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_routing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <benjaminslakey@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:41:18 by bslakey           #+#    #+#             */
/*   Updated: 2017/06/09 11:09:18 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

bool					goal_reached(t_lem_in *prog)
{
    int 				i;

    i = -1;
    while (++i < prog->n_ants)
    {
        if (prog->ants[i]->location != prog->dest)
            return (false);
    }
    return (true);
}

void					determine_next_move(t_lem_in *prog, int ant_num)
{
    t_adj 				*adj;
    t_vert 				*tmp;
    t_vert 				*room;
    t_ant 				*ant;
    t_path				*path;

    ant = prog->ants[ant_num];
    path = dijkstras(prog->ant_farm, ant->location, prog->dest);
    room = prog->ant_farm->vertices[path->arr[1]];
    if (room->occupied == true && room->v_ind != prog->dest)
    {
        adj = room->lst->first;
        while (adj != NULL)
        {
            tmp = prog->ant_farm->vertices[adj->adj_vert];
            if (in_adjlist(tmp->lst, path->arr[0]) && tmp->occupied == false)
                ant->move_to = tmp->v_ind;
            adj = adj->next;
        }
    }
    else
        ant->move_to = path->arr[1];
    free_path(&path);
    move_ant(prog, ant);
}

void 					move_ant(t_lem_in *prog, t_ant *ant)
{
    if (ant->move_to >= 0)
    {
        print_moves(prog, ant);
        prog->ant_farm->vertices[ant->location]->occupied = false;
        prog->ant_farm->vertices[ant->move_to]->occupied = true;
        ant->location = ant->move_to;
        ant->move_to = -1;
    }
}

void					route_ants(t_lem_in *prog)
{
    int 				i;

    i = 0;
    while (goal_reached(prog) == false)
    {
        i = -1;
        while (++i < prog->n_ants)
        {
            if (prog->ants[i]->location != prog->dest)
                determine_next_move(prog, i);
        }
        ft_putstr("\n");
    }
}
