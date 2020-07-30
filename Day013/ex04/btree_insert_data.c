/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:45:42 by tlee              #+#    #+#             */
/*   Updated: 2019/11/08 16:14:30 by tlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, \
		int (*cmpf)(void *, void *))
{
	t_btree node;

	node = *root
	if (node != 0)
		node = btree_create_node(item);
	if (cmpf(item, node->item) < 0)
	{
		if (node->left)
			btree_insert_data(&node->left, item, cmpf);
		else
			node->left = btree_create_node(item);
	}
	else
	{
		if (node->right)
			btree_insert_data(node->right, item, cmpf);
		else
			node->right = btree_creat_node(item);
	}
}
