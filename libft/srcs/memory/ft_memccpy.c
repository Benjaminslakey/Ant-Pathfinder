/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 06:27:22 by bslakey           #+#    #+#             */
/*   Updated: 2016/09/29 10:21:18 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*d_ptr;
	unsigned char		*s_ptr;

	i = 0;
	d_ptr = (unsigned char*)dst;
	s_ptr = (unsigned char*)src;
	while (n)
	{
		d_ptr[i] = s_ptr[i];
		if (s_ptr[i] == (unsigned char)c)
			return (d_ptr + (i + 1));
		i++;
		n--;
	}
	return (NULL);
}
