/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:54:39 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/25 19:26:21 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	load_test(t_list **l, const char *name, int (*func)(void))
{
	if (!l || !name || !func)
		return ;
	ft_lstadd_back(l, ft_lstnew(test_new(name, func, NULL)));
}
void	load_test_with_output(t_list **l, const char *name, int (*func)(void),
		char *output)
{
	if (!l || !name || !func)
		return ;
	ft_lstadd_back(l, ft_lstnew(test_new(name, func, output)));
}


