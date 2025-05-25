/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:55:05 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/25 15:36:46 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	basic_test(void);

int	launch_push(void)
{
	t_list	*testlist;

	testlist = NULL;
	load_test(&testlist, "Basic test", &basic_test);
	return (launch_tests("PUSH", testlist));
}
