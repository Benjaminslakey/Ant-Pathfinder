/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dstr_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 19:12:45 by bslakey           #+#    #+#             */
/*   Updated: 2016/11/12 19:22:17 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t		dstr_strlen(char *s, int i, const char *delims)
{
	int		len;
	int		j;

	j = 0;
	len = 0;
	while (s[i + len])
	{
		j = 0;
		while (delims[j])
		{
			if (s[i + len] == delims[j])
				return (len + 1);
			j++;
		}
		len++;
	}
	return (len);
}
