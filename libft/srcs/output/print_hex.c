/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 23:58:47 by bslakey           #+#    #+#             */
/*   Updated: 2016/10/22 00:07:42 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	print_hex(int n)
{
	int		i;
	char	*radix;
	char	hex_string[9];

	i = 0;
	radix = "0123456789abcdef";
	if (!n)
		write(1, "0", 1);
	else
	{
		while (n)
		{
			hex_string[i] = radix[(n % 16)];
			n /= 16;
			i++;
		}
		while (i-- > 0)
			write(1, &hex_string[i], 1);
	}
}
