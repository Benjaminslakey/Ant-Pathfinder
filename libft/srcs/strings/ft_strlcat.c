/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 08:02:48 by bslakey           #+#    #+#             */
/*   Updated: 2016/09/29 11:40:14 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t init_len;
	size_t src_len;
	size_t i;

	i = 0;
	init_len = 0;
	src_len = 0;
	while (dst[init_len])
		init_len++;
	while (src[src_len])
		src_len++;
	while (src[i] && (init_len + i) < size - 1)
	{
		dst[init_len + i] = src[i];
		i++;
	}
	dst[i + init_len] = 0;
	if (init_len <= size)
		return (init_len + src_len);
	else
		return (size + src_len);
}
