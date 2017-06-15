/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 22:36:06 by bslakey           #+#    #+#             */
/*   Updated: 2016/10/04 04:59:07 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	btree_apply_prefix(t_btree *root, void (*f)(void *))
{
	if (root)
	{
		(*f)(root->item);
		if (root->left)
			btree_apply_prefix(root->left, f);
		if (root->right)
			btree_apply_prefix(root->right, f);
	}
	return ;
}
