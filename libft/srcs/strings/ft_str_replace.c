/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 06:26:51 by bslakey           #+#    #+#             */
/*   Updated: 2016/11/04 03:06:50 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char				*ft_str_replace(char **to_replace, char *replace_with)
{
	char			*temp;

	MEM_GUARD(replace_with);
	temp = ft_strdup(replace_with);
	free(*to_replace);
	return (temp);
}
