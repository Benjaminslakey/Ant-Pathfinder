/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 07:35:29 by bslakey           #+#    #+#             */
/*   Updated: 2017/06/07 14:33:33 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <stdio.h>

/*
* fgetc_stdin: this function is only for use with lem_in
* where the program is always expected to be run with a file redirect to stdin,
* where this function will read the file and convert it into a 2d array of
* strings each string being one line from the file
*/

int 			parse_rooms(char **file, t_lem_in *prog)
{
	int 		i;
	int 		j;
    int         c;
	char 		**temp;

	i = -1;
	j = -1;
    c = 0;
	temp = NULL;
	while (file[++i])
	{
		if (!chk_roomformat(file[i]))
		{
			temp = ft_strsplit(file[i], ' ');
			prog->rooms[++j] = ft_strdup(temp[0]);
            free_strings(&temp);
            c++;
		}
	}
    return (c > 0 ? SUCCESS : ERR);
}

int 			parse_links(char **file, t_lem_in *o)
{
	int 		i;
	int 		j;
	int 		c;
	char 		**temp;

	i = -1;
	temp = NULL;
	c = -1;
	while (file[++i])
	{
		if (!chk_linkformat(file[i]))
		{
			j = -1;
			ERR_GUARD(((temp = ft_strsplit(file[i], '-')) == NULL), ERR);
			ERR_GUARD(((o->links)[++c] =
                        (int*)malloc(sizeof(int) * 2)) == NULL, ERR);
			while ((o->rooms)[++j])
			{
				if (!ft_strcmp((o->rooms)[j], temp[0]))
					(o->links)[c][0] = j;
				if (!ft_strcmp((o->rooms)[j], temp[1]))
					(o->links)[c][1] = j;
			}
            free_strings(&temp);
		}
	}
    return (c > -1 ? SUCCESS : ERR);
}

int 			parse_commands(char **file, t_lem_in *prog)
{
	int 		i;
	char 		**temp;

	i = -1;
	temp = NULL;
	while (file[++i])
	{
			if (!ft_strcmp(file[i], "##start"))
			{
				temp = ft_strsplit(file[i + 1], ' ');
				prog->source = str_inhaystack(temp[0], prog->rooms);
				prog->start = (prog->rooms)[prog->source];
			}
			else if (!ft_strcmp(file[i], "##end"))
			{
				temp = ft_strsplit(file[i + 1], ' ');
				prog->dest = str_inhaystack(temp[0], prog->rooms);
				prog->end = (prog->rooms)[prog->dest];
			}
		}
    return (SUCCESS);
}

int             parse_ants(char **file, t_lem_in *prog)
{
    int         i;

    i = -1;
    while (file[++i])
    {
        if (!chk_comm(file[i]))
            ;
        else if (ft_strcspn(file[i], "0123456789"))
        {
            prog->n_ants = ft_atoi(file[i]);
            return (SUCCESS);
        }
    }
    return (SUCCESS);
}

int 			parse_file(char **file, t_lem_in *prog)
{
	int 		i;
	int 		count;

	i = -1;
	count = 0;
    ERR_GUARD(parse_ants(file, prog) == ERR, ERR);
	while (file[++i])
		count += (!chk_roomformat(file[i])) ? 1 : 0;
	prog->rooms = (char**)malloc(sizeof(char*) * (count + 1));
	(prog->rooms)[count] = 0;
	prog->nrooms = count;
	i = -1;
	count = 0;
	while (file[++i])
		count += (!chk_linkformat(file[i])) ? 1 : 0;
	prog->nlinks = count;
	ERR_GUARD((prog->links = (int**)malloc(sizeof(int*) * count)) == NULL, ERR);
	ERR_GUARD(parse_rooms(file, prog) == ERR, ERR);
	ERR_GUARD(parse_links(file, prog) == ERR, ERR);
	ERR_GUARD(parse_commands(file, prog) == ERR, ERR);
    return (SUCCESS);
}

