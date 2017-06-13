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
	printf("L%d-%s ", ant->id + 1, next_room);
}

int 		print_error(int err)
{
	if (err > 0)
		ft_putstr("ERROR\n");
	if (err == 1)
		ft_putstr_fd("Err: start and/or end not specified\n", STDOUT_FILENO);
	if (err == 2)
		ft_putstr_fd("Err: empty line in file\n", STDOUT_FILENO);
	if (err == 3)
		ft_putstr_fd("Err: invalid command\n", STDOUT_FILENO);
	if (err == 4)
		ft_putstr_fd("Err: \n", STDOUT_FILENO);
	if (err == 5)
		ft_putstr_fd("Err: empty line in file\n", STDOUT_FILENO);
	if (err == 6)
		ft_putstr_fd("Err: empty line in file\n", STDOUT_FILENO);
	if (err == 7)
		ft_putstr_fd("Err: empty line in file\n", STDOUT_FILENO);
	if (err == 8)
		ft_putstr_fd("Err: empty line in file\n", STDOUT_FILENO);
	if (err == 11)
		ft_putstr_fd("Err: no ants given\n", STDOUT_FILENO);
	if (err == 12)
		ft_putstr_fd("Err: No solutions exist\n", STDOUT_FILENO);
	if (err == 13)
		ft_putstr_fd("", STDOUT_FILENO);
    return (err > 0 ? 1 : 0);
}