/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:55:05 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/25 17:04:26 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	basic_r(void);
int	empty_r(void);

int	launch_rotate(void)
{
	t_list	*testlist;

	testlist = NULL;
	load_test(&testlist, "Basic test", &basic_r);
	load_test(&testlist, "Empty list", &empty_r);
	return (launch_tests("ROTATE", testlist));
}
