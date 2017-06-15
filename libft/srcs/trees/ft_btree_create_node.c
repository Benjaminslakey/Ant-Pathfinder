/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bslakey <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/26 22:19:57 by bslakey           #+#    #+#             */
/*   Updated: 2016/10/01 18:06:10 by bslakey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *new_branch;

	new_branch = (t_btree*)malloc(sizeof(t_btree));
	if (new_branch != NULL)
	{
		new_branch->item = item;
		new_branch->left = 0;
		new_branch->right = 0;
	}
	return (new_branch);
}
