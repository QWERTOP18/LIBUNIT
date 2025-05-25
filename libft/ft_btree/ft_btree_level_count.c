/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_level_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 07:32:40 by ymizukam          #+#    #+#             */
/*   Updated: 2025/03/26 03:13:24 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	ft_btree_level_count(t_btree *root)
{
	int	left_count;
	int	right_count;

	if (!root)
		return (0);
	left_count = ft_btree_level_count(root->left);
	right_count = ft_btree_level_count(root->right);
	if (left_count > right_count)
		return (left_count + 1);
	else
		return (right_count + 1);
}
