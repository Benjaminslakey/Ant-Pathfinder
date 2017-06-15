/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 04:42:13 by bslakey           #+#    #+#             */
/*   Updated: 2016/10/01 14:08:06 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*map;
	size_t	i;

	i = 0;
	MEM_GUARD((char*)s);
	map = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	MEM_GUARD(map);
	while (s[i])
	{
		map[i] = (*f)(s[i]);
		i++;
	}
	map[i] = 0;
	return (map);
}
