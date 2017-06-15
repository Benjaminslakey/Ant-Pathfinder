/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_int_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 07:35:29 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/09 16:51:02 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void			copy_int_array(int **dest, int *src, int size)
{
	int			i;

	MEM_GUARD_VR(dest);
	MEM_GUARD_VR(src);
	i = -1;
	while (++i < size)
		(*dest)[i] = src[i];
}
