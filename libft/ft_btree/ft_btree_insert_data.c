/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 07:32:09 by ymizukam          #+#    #+#             */
/*   Updated: 2025/03/26 03:13:24 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

// t_btree	*ft_btree_create_node(void *item);

void	ft_btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *,
			void *))
{
	if (!root)
		return ;
	if (*root == 0)
	{
		*root = ft_btree_create_node(item);
		return ;
	}
	if (cmpf(item, (*root)->item) < 0)
		ft_btree_insert_data(&((*root)->left), item, cmpf);
	else
		ft_btree_insert_data(&((*root)->right), item, cmpf);
}
