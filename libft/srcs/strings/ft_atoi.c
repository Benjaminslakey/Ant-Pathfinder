/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:59:14 by bslakey           #+#    #+#             */
/*   Updated: 2016/11/13 02:35:33 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

intmax_t			ft_atoi(const char *str)
{
	int				i;
	intmax_t		result;
	int				neg;

	i = -1;
	result = 0;
	neg = 1;
	while (str[++i] && (WHT(str[i]) || (ANUM(str[i])) || (ISIGN(str[i]))))
	{
		if (ISIGN(str[i]) || (ANUM(str[i])))
		{
			if (ISIGN(str[i]))
			{
				if (str[i] == '-')
					neg *= -1;
				i++;
			}
			while (ANUM(str[i]))
				result = (result * 10) + (str[i++] - '0');
			return ((result * neg));
		}
	}
	return (0);
}
