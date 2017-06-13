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

char			**fgetc_stdin(void)
{
    char        **file;
	char		*file_buffer;
    char		*temp;
    char		*line;

    MEM_GUARD((file_buffer = ft_strnew(0)));
    while (get_next_line(STDIN_FILENO, &line) > 0)
    {
        MEM_GUARD((temp = ft_strjoin(file_buffer, line)));
        free((void*)line);
        free((void*)file_buffer);
        MEM_GUARD((file_buffer = ft_strjoin(temp, "\n")));
        free((void*)temp);
	}
    file = ft_strsplit(file_buffer, '\n');
    free(file_buffer);
	return (file);
}

void 			print_antfarm(t_lem_in *o)
{
    int 		i;

    i = -1;
    printf("%d\n", o->n_ants);
    while ((o->rooms)[++i])
    {
        if (i == o->source)
            printf("##start\n");
        else if (i == o->dest)
            printf("##end\n");
        printf("%s\n", o->rooms[i]);
    }
    i = -1;
    while (++i < o->nlinks)
        printf("%s-%s\n", o->rooms[o->links[i][0]], o->rooms[o->links[i][1]]);
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
    t_lem_in	*program;
    char		**file;

    program = NULL;
    ERR_GUARD(((file = fgetc_stdin()) == NULL), EXIT_FAILURE);
    ERR_GUARD((print_error((errchk_input(file)))) == 1, EXIT_FAILURE);
    if ((program = init_lem_in(file)) == NULL)
    {
        printf(RED"ERROR\n"CRESET);
        clear_memory(&file, NULL);
        return (EXIT_FAILURE);
    }
    print_antfarm(program);
    init_ants(program);
    route_ants(program);
    printf(GREEN"-------------------------------------------------\n\n"CRESET);
    clear_memory(&file, &program);
    return (EXIT_SUCCESS);
}