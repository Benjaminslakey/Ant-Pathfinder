/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_infix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 23:23:14 by bslakey           #+#    #+#             */
/*   Updated: 2016/10/04 04:58:29 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	btree_apply_infix(t_btree *root, void (*f)(void *))
{
	if (root)
	{
		if (root->left)
			btree_apply_infix(root->left, f);
		(*f)(root->item);
		if (root->right)
			btree_apply_infix(root->right, f);
	}
	return ;
}
