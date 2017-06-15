/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepend_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:24:49 by bslakey           #+#    #+#             */
/*   Updated: 2016/11/16 17:40:20 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_prepend_str(char *orig, const char *to_prepend)
{
	size_t	o_len;
	size_t	pre_len;
	char	*new_str;
	char	*ptr;

	o_len = ft_strlen(orig);
	pre_len = ft_strlen(to_prepend);
	new_str = ft_strnew(o_len + pre_len);
	ft_strcpy(new_str, to_prepend);
	ptr = (new_str + pre_len);
	ft_strcpy(ptr, to_prepend);
	return (new_str);
}
