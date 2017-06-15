/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_strlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 08:16:24 by bslakey           #+#    #+#             */
/*   Updated: 2016/09/27 08:28:57 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t		d_strlen(char *s, int index, int delim)
{
	size_t length;

	length = 0;
	while (s[index] && s[index] != delim)
	{
		index++;
		length++;
	}
	return (length);
}
