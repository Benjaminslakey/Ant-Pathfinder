/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 17:38:19 by bslakey           #+#    #+#             */
/*   Updated: 2016/09/27 09:07:03 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int len_l;

	i = 0;
	len_l = ft_strlen(little);
	if (len_l == 0)
		return ((char*)big);
	while (big[i])
	{
		j = 0;
		if (big[i] == little[j])
			while (j < len_l)
			{
				if (big[i + j] == little[j])
					j++;
				else
					break ;
			}
		if (j == len_l)
			return ((char*)(&big[i]));
		i++;
	}
	return (NULL);
}
