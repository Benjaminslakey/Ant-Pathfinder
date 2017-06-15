/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 10:28:48 by bslakey           #+#    #+#             */
/*   Updated: 2016/11/13 01:58:43 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_strtrim(char const *s)
{
	char	*newstr;
	int		i;

	i = -1;
	VAR3_INIT0(trail, lead, length);
	MEM_GUARD((char*)s);
	length = ft_strlen(s);
	while (s[lead] && WHT(s[lead]))
		lead++;
	while (WHT(s[(length - 1) - trail]) && (length - trail) > 0)
		trail++;
	if (lead == trail)
		newstr = ft_strnew(0);
	else
		length -= (lead + trail);
	newstr = ft_strnew(length);
	MEM_GUARD(newstr);
	while (s[++i + (lead + trail)])
		newstr[i] = s[i + lead];
	return (newstr);
}
