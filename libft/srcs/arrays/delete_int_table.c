/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_int_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 11:37:30 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/08 11:43:14 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void			delete_int_table(int height, int ***table)
{
	int			i;

	i = 0;
	MEM_GUARD_VR(table);
	while (++i < height)
		free((*table)[i]);
	free(*table);
	*table = NULL;
}
