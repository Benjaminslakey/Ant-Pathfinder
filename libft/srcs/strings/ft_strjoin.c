/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 05:56:50 by bslakey           #+#    #+#             */
/*   Updated: 2017/01/31 05:27:58 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	length;
	char	*newstr;
	int		i;
	int		j;

	MEM_GUARD((char*)s1);
	MEM_GUARD((char*)s2);
	i = -1;
	j = -1;
	length = (ft_strlen(s1) + ft_strlen(s2));
	MEM_GUARD((newstr = ft_strnew(length)));
	while (s1[++i])
		newstr[i] = s1[i];
	while (s2[++j])
		newstr[i + j] = s2[j];
	return (newstr);
}
