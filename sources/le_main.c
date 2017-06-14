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
#include <stdio.h>

char			**fgetc_stdin(void)
{
	char		**file;
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

void			clear_memory(char ***file, t_lem_in **prog)
{
	t_lem_in	*o;

	o = NULL;
	if (file != NULL && *file != NULL)
		free_strings(file);
	if (prog != NULL && *prog != NULL)
	{
		o = *prog;
		free(o->start);
		free(o->end);
		free_ants(&(o->ants), o->n_ants);
		free_int_2Darr(&(o->links), o->nlinks);
		destroy_graph(&(o->ant_farm));
		free(*prog);
	}
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
		ft_putstr(RED"ERROR\n"CRESET);
		clear_memory(&file, NULL);
		return (EXIT_FAILURE);
	}
	if (test_path(program) != ERR)
	{
		print_antfarm(program);
		init_ants(program);
		route_ants(program);
	}
	else
		print_error(12);
	clear_memory(&file, &program);
	return (EXIT_SUCCESS);
}
