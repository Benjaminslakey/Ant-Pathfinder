/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <benjaminslakey@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:01:41 by bslakey           #+#    #+#             */
/*   Updated: 2017/06/07 14:50:30 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_ant 				*create_ant(int id, int start)
{
	t_ant 			*ant;

	ant = (t_ant*)malloc(sizeof(t_ant));
	ant->id = id;
	ant->location = start;
	ant->move_to = -1;
	return (ant);
}

void 				init_ants(t_lem_in *prog)
{
	int 			i;
	t_ant 			**ants;

	i = -1;
	ants = (t_ant**)malloc(sizeof(t_ant*) * prog->n_ants);
	while (++i < prog->n_ants)
		ants[i] = create_ant(i, prog->source);
	prog->ants = ants;
}
