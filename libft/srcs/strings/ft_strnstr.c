/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 17:33:34 by bslakey           #+#    #+#             */
/*   Updated: 2016/09/29 11:48:22 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(*l))
		return ((char*)b);
	while (i < len && b[i])
	{
		j = 0;
		while ((i + j) < len && (b[i + j] == l[j]) && l[j])
		{
			if (b[i + j] == l[j])
				j++;
			else
				break ;
		}
		if (j == ft_strlen(l))
			return ((char*)(&b[i]));
		i++;
	}
	return (NULL);
}
