/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:55:08 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/25 17:14:08 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cyclic_list.h"
#include "libunit.h"

int	new_test(void)
{
	t_clst	*list_a;

	list_a = clst_new(5);
	if (!list_a)
		return (-1);
	return (0);
}
