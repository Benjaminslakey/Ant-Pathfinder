/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 06:38:14 by bslakey           #+#    #+#             */
/*   Updated: 2016/09/29 05:36:41 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	unsigned const char	*src_ptr;
	size_t				i;

	dest_ptr = (unsigned char*)dest;
	src_ptr = (unsigned const char*)src;
	i = 0;
	while (n)
	{
		dest_ptr[i] = src_ptr[i];
		n--;
		i++;
	}
	return (dest);
}
