/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 19:57:52 by bslakey           #+#    #+#             */
/*   Updated: 2016/10/14 07:48:50 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strndup(const char *s1, size_t size)
{
	char *copy;

	copy = ft_strnew(size);
	MEM_GUARD(copy);
	ft_strncpy(copy, s1, size);
	return (copy);
}
