/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_int_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 01:08:22 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/08 07:34:24 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int			*clone_int_array(int *orig_table, int table_size)
{
	int			i;
	int			*new_table;

	i = -1;
	MEM_GUARD((new_table = malloc(sizeof(int) * table_size)));
	while (++i < table_size)
		new_table[i] = orig_table[i];
	return (new_table);
}
