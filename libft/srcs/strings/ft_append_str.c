/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:25:24 by bslakey           #+#    #+#             */
/*   Updated: 2016/11/16 17:41:01 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_append_str(char *orig, const char *to_append)
{
	size_t	o_len;
	size_t	app_len;
	char	*new_str;
	char	*ptr;

	o_len = ft_strlen(orig);
	app_len = ft_strlen(to_append);
	new_str = ft_strnew(o_len + app_len);
	ft_strcpy(new_str, orig);
	ptr = (new_str + o_len);
	ft_strcpy(ptr, to_append);
	return (new_str);
}
