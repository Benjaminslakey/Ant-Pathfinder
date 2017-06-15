/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_dcount.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 08:11:06 by bslakey           #+#    #+#             */
/*   Updated: 2016/09/25 08:11:32 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		w_dcount(char *words, int delim)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (words[i])
	{
		if (words[i] == delim)
			i++;
		else
		{
			while (words[i] && words[i] != delim)
				i++;
			count++;
		}
	}
	return (count);
}
