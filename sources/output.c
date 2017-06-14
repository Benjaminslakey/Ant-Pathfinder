/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 07:35:29 by bslakey           #+#    #+#             */
/*   Updated: 2017/06/09 10:27:25 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		print_moves(t_lem_in *prog, t_ant *ant)
{
	char	*next_room;

	next_room = prog->rooms[ant->move_to];
	ft_putstr(GREEN"L");
	ft_putnbr(ant->id + 1);
	ft_putstr("-");
	ft_putstr(next_room);
	ft_putstr(" "CRESET);
}

void		print_antfarm(t_lem_in *o)
{
	int		i;

	i = -1;
	ft_putnbr(o->n_ants);
	ft_putstr("\n");
	while ((o->rooms)[++i])
	{
		if (i == o->source)
			ft_putstr("##start\n");
		else if (i == o->dest)
			ft_putstr("##end\n");
		ft_putstr(o->rooms[i]);
		ft_putstr("\n");
	}
	i = -1;
	while (++i < o->nlinks)
	{
		ft_putstr(o->rooms[o->links[i][0]]);
		ft_putstr("-");
		ft_putstr(o->rooms[o->links[i][1]]);
		ft_putstr("\n");
	}
	ft_putstr("\n");
}

int			print_error(int err)
{
	if (err > 0)
		ft_putstr("ERROR\n");
	if (err == 1)
		ft_putstr_fd("Err: Invalid Start and/or End\n", STDOUT_FILENO);
	if (err == 2)
		ft_putstr_fd("Err: empty line in file\n", STDOUT_FILENO);
	if (err == 3)
		ft_putstr_fd("Err: invalid command\n", STDOUT_FILENO);
	if (err == 4)
		ft_putstr_fd("Err: \n", STDOUT_FILENO);
	if (err == 5)
		ft_putstr_fd("Err: Invalid Line\n", STDOUT_FILENO);
	if (err == 6)
		ft_putstr_fd("Err: Invalid room name\n", STDOUT_FILENO);
	if (err == 7)
		ft_putstr_fd("Err: empty line in file\n", STDOUT_FILENO);
	if (err == 8)
		ft_putstr_fd("Err: Start and End are disjoint\n", STDOUT_FILENO);
	if (err == 11)
		ft_putstr_fd("Err: no ants given\n", STDOUT_FILENO);
	if (err == 12)
		ft_putstr_fd("Err: No solutions exist\n", STDOUT_FILENO);
	if (err == 13)
		ft_putstr_fd("", STDOUT_FILENO);
	return (err > 0 ? 1 : 0);
}
