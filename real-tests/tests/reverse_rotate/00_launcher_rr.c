/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher_rr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:55:05 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/25 17:03:14 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	basic_rr(void);
int	empty_rr(void);

int	launch_reverse_rotate(void)
{
	t_list	*testlist;

	testlist = NULL;
	load_test(&testlist, "Basic test", &basic_rr);
	load_test(&testlist, "Empty list", &empty_rr);
	return (launch_tests("REVERSE_ROTATE", testlist));
}
