/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 22:20:05 by bslakey           #+#    #+#             */
/*   Updated: 2016/11/06 10:56:56 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void		*ft_realloc(const void *src, size_t orig_size, size_t new_size)
{
	void			*new_mem;

	new_mem = (void*)malloc(new_size);
	MEM_GUARD(new_mem);
	ft_bzero(new_mem, new_size);
	new_mem = ft_memcpy(new_mem, src, orig_size);
	return (new_mem);
}
