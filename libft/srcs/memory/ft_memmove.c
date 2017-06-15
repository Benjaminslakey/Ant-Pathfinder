/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 07:04:12 by bslakey           #+#    #+#             */
/*   Updated: 2016/09/29 10:21:40 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest_ptr;
	unsigned char		*src_ptr;

	dest_ptr = (unsigned char*)dst;
	src_ptr = (unsigned char*)src;
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	else
		while (len--)
			dest_ptr[len] = src_ptr[len];
	return (dst);
}
