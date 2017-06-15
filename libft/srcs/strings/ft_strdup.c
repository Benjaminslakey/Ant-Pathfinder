/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 22:40:25 by bslakey           #+#    #+#             */
/*   Updated: 2016/10/01 17:47:34 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char *copy;

	copy = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	MEM_GUARD(copy);
	ft_strcpy(copy, s1);
	return (copy);
}
