/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:30:35 by ymizukam          #+#    #+#             */
/*   Updated: 2025/03/26 03:13:24 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)(void *,
			void *))
{
	t_list	*current;

	current = begin_list;
	while (current)
	{
		if ((*cmp)(current->data, data_ref) == 0)
			return (current);
		current = current->next;
	}
	return (0);
}
