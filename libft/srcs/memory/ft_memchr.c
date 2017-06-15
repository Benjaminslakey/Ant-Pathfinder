/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 22:59:11 by bslakey           #+#    #+#             */
/*   Updated: 2016/09/29 10:20:50 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	chr;
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	chr = (unsigned char)c;
	ptr = (unsigned char*)s;
	while (i < n)
	{
		if (*(ptr + i) == chr)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
