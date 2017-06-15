/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_reverse_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 12:46:07 by bslakey           #+#    #+#             */
/*   Updated: 2017/01/30 18:05:12 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void				array_reverse_int(int *arr, int size)
{
	int				i;
	int				j;
	int				temp;

	i = -1;
	j = size;
	while (++i < --j)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
