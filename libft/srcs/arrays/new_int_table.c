/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_int_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 07:47:54 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/08 07:52:12 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int			**new_int_table(int height, int width)
{
	int			i;
	int			j;
	int			*row;
	int			**table;

	MEM_GUARD((table = (int**)malloc(sizeof(int*) * height)));
	i = -1;
	while (++i < height)
	{
		j = -1;
		MEM_GUARD((row = (int*)malloc(sizeof(int) * width)));
		while (++j < width)
			row[j] = 0;
		table[i] = row;
	}
	return (table);
}
