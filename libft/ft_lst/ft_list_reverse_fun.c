/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:31:35 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/25 15:16:11 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

// typedef struct s_range
// {
// 	int		size;
// 	int		i;
// 	int		j;
// }			t_range;

// static int	ft_list_size_local(t_list *begin_list)
// {
// 	int		count;
// 	t_list	*cur;

// 	count = 0;
// 	cur = begin_list;
// 	while (cur)
// 	{
// 		count++;
// 		cur = cur->next;
// 	}
// 	return (count);
// }

// void	ft_list_reverse_fun(t_list *begin_list)
// {
// 	t_list	*start;
// 	t_list	*end;
// 	void	*temp;
// 	t_range	range;

// 	range.size = ft_list_size_local(begin_list);
// 	range.i = 0;
// 	while (range.i < range.size / 2)
// 	{
// 		range.j = -1;
// 		start = begin_list;
// 		end = begin_list;
// 		while (++range.j < range.i)
// 			start = start->next;
// 		range.j = -1;
// 		while (++range.j < range.size - range.i - 1)
// 			end = end->next;
// 		temp = start->data;
// 		start->data = end->data;
// 		end->data = temp;
// 		range.i++;
// 	}
// }
