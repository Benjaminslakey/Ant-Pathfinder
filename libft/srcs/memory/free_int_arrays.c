/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_int_arrays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 12:46:07 by bslakey           #+#    #+#             */
/*   Updated: 2017/01/30 18:05:12 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void			free_int_arrays(int ***arrs, int height)
{
	int			i;

	i = -1;
	ERR_GUARD_VR(arrs == NULL);
	while (++i < height)
		free((*arrs)[i]);
	free((*arrs));
	arrs = NULL;
}
