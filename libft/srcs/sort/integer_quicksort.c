/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_quicksort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 01:13:33 by bslakey           #+#    #+#             */
/*   Updated: 2017/02/15 07:24:58 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int			choose_pivot(int *int_tab, int left, int right)
{
	int				first;
	int				last;
	int				mid;

	first = int_tab[left];
	last = int_tab[right];
	mid = int_tab[left + (right - left) / 2];
	if ((first < mid && mid < last) || (last < mid && mid < first))
		return (left + (right - left) / 2);
	else if ((mid < first && first < last) || (last < first && first < mid))
		return (left);
	else
		return (right);
}

static int			partition(int *int_table, int left, int right)
{
	int				i;
	int				pivot;
	int				pivot_index;

	i = left - 1;
	pivot_index = choose_pivot(int_table, left, right);
	pivot = int_table[pivot_index];
	swap_integers(&(int_table[pivot_index]), &(int_table[right]));
	pivot_index = left;
	while (++i < right)
	{
		if (int_table[i] <= pivot)
		{
			swap_integers(&(int_table[pivot_index]), &(int_table[i]));
			pivot_index++;
		}
	}
	swap_integers(&(int_table[pivot_index]), &(int_table[right]));
	return (pivot_index);
}

void				integer_quicksort(int *int_table, int left, int right)
{
	int				middle;

	if (left >= right)
		return ;
	middle = partition(int_table, left, right);
	integer_quicksort(int_table, left, middle - 1);
	integer_quicksort(int_table, middle + 1, right);
}
