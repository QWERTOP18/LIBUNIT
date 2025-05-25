/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:55:08 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/25 17:02:42 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cyclic_list.h"
#include "libunit.h"

int	basic_rr(void)
{
	t_clst	*list_a;

	list_a = clst_new(5);
	if (!list_a)
		return (-1);
	clst_insert(list_a, 2);
	clst_insert(list_a, 1);
	reverse_rotate(list_a);
	if (clst_get(list_a, 0) != 2 || clst_get(list_a, 1) != 1)
	{
		clst_clear(list_a);
		return (-1);
	}
	clst_clear(list_a);
	return (0);
}
