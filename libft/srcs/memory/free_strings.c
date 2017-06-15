/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 12:46:07 by bslakey           #+#    #+#             */
/*   Updated: 2017/01/30 18:05:12 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void			free_strings(char ***strings)
{
	int			i;

	i = -1;
	ERR_GUARD_VR(strings == NULL);
	while ((*strings)[++i])
		free((*strings)[i]);
	free(*strings);
	*strings = NULL;
}
