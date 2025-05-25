/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_from_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 20:29:42 by ymizukam          #+#    #+#             */
/*   Updated: 2025/03/26 03:13:24 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"
#include "ft_string.h"
#include <stdlib.h>

t_list	*ft_list_from_strs(char **strs)
{
	t_list	*list;
	t_list	*new;
	char	*dup_str;

	if (!strs || !*strs)
		return (NULL);
	list = NULL;
	while (*strs)
	{
		dup_str = ft_strdup(*strs);
		if (!dup_str)
			return (ft_lstclear(&list, free), NULL);
		new = ft_create_elem(dup_str);
		if (!new)
		{
			free(dup_str);
			ft_lstclear(&list, free);
			return (NULL);
		}
		ft_lstadd_back(&list, new);
		strs++;
	}
	return (list);
}
