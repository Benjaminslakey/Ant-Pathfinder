/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   le_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 07:35:29 by bslakey           #+#    #+#             */
/*   Updated: 2017/06/07 14:32:59 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void 			print_antfarm(t_lem_in *o)
{
    //int         t = 0;
    int 		i;
    t_graph 	*graph;
    t_vert 		**vertices;

    i = -1;
    graph = o->ant_farm;
    //printf(RED"af_trace%d\n", t++);
    vertices = graph->vertices;
    //printf(RED"af_trace%d\n", t++);
    printf("%d\n", o->n_ants);
    //printf(RED"af_trace%d\n", t++);
    while ((o->rooms)[++i])
    {
        if (i == o->source)
            printf("##start\n");
        else if (i == o->dest)
            printf("##end\n");
        printf("%s\n", o->rooms[i]);
    }
    //printf(RED"af_trace%d\n", t++);
    i = -1;
    while (++i < o->nlinks)
        printf("%s-%s\n", o->rooms[o->links[i][0]], o->rooms[o->links[i][1]]);
    //printf(RED"af_trace%d\n", t++);
    printf("\n");
}

void 			clear_memory(char ***file, t_lem_in **program)
{
    MEM_GUARD_VR((file));
    MEM_GUARD_VR((program));
    free_strings(file);
}

t_lem_in		*init_lem_in(char **file)
{
    t_lem_in	*o;

    MEM_GUARD((o = (t_lem_in*)malloc(sizeof(t_lem_in))));
    if ((parse_file(file, o)) == ERR || o->n_ants <= 0)
    {
        free(o);
        return (NULL);
    }
    o->ant_farm = create_graph(o->nrooms, o->rooms, o->nlinks, o->links);
    return (o);
}

int				main(void)
{
    int         t = 0;
    t_lem_in	*program;
    t_vert		**ant_farm;
    char		**file;

    program = NULL;
    ant_farm = NULL;
    ERR_GUARD(((file = fgetc_stdin()) == NULL), EXIT_FAILURE);
    //Rrintf(RED"maintrace%d\n", t++);
    ERR_GUARD((print_error((errchk_input(file)))) == 1, EXIT_FAILURE);
    //printf(RED"maintrace%d\n", t++);
    if ((program = init_lem_in(file)) == NULL)
    {
        printf(RED"ERROR"CRESET);
        clear_memory(&file, NULL);
        return (EXIT_FAILURE);
    }
    //printf(RED"maintrace%d\n", t++);
    print_antfarm(program);
    //printf(RED"maintrace%d\n", t++);
    init_ants(program);
    //printf(RED"maintrace%d\n", t++);
    route_ants(program);
    //printf(RED"maintrace%d\n", t++);
    printf(GREEN"-------------------------------------------------\n\n"CRESET);
    clear_memory(&file, &program);
    return (EXIT_SUCCESS);
}