/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 07:16:27 by bslakey           #+#    #+#             */
/*   Updated: 2016/10/01 14:06:09 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	*new_dstr(char *big, int *index, int delim)
{
	int		j;
	char	*new;

	j = 0;
	new = (char*)malloc(sizeof(char) * (d_strlen(big, *index, delim) + 1));
	MEM_GUARD(new);
	while (big[*index] && big[*index] != delim)
	{
		new[j] = big[*index];
		(*index)++;
		j++;
	}
	new[j] = 0;
	return (new);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		nth_str;
	char	**strings;

	i = 0;
	nth_str = 0;
	MEM_GUARD((char**)s);
	strings = (char**)malloc(sizeof(char*) * (w_dcount((char*)s, c) + 1));
	MEM_GUARD(strings);
	while (s[i])
	{
		if (s[i] != c)
		{
			strings[nth_str] = new_dstr((char*)s, &i, c);
			nth_str++;
		}
		else
			i++;
	}
	strings[nth_str] = 0;
	return (strings);
}
