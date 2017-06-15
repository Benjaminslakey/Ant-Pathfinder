/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_inhaystack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 07:35:29 by bslakey           #+#    #+#             */
/*   Updated: 2017/06/07 14:33:33 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int				str_inhaystack(char *needle, char **haystack)
{
	int			i;
	bool		found;

	i = -1;
	found = false;
	while (haystack[++i])
	{
		if (!ft_strcmp(needle, haystack[i]))
		{
			found = true;
			break ;
		}
	}
	return (found ? i : -1);
}
