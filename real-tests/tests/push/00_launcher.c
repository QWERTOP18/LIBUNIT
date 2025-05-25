/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:55:05 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/25 17:03:45 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	basic_p(void);
int	empty_p(void);

int	launch_push(void)
{
	t_list	*testlist;

	testlist = NULL;
	load_test(&testlist, "Basic test", &basic_p);
	load_test(&testlist, "Empty list", &empty_p);
	return (launch_tests("PUSH", testlist));
}
