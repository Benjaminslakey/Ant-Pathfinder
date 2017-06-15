/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 03:49:48 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/15 07:25:56 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char				*ft_itoa(int n)
{
	int		len;
	long	num;
	char	*ret_str;

	num = (long)n;
	len = ft_nbrlen(num, 10);
	ret_str = ft_strnew(len);
	MEM_GUARD(ret_str);
	ret_str[len] = 0;
	if (num == 0)
		return (ft_strdup("0"));
	if (num < 0)
	{
		ret_str[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		ret_str[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (ret_str);
}
