/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:55:05 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/25 15:36:38 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int new_test(void);
int insert_test(void);
int remove_test(void);

int launch_setup(void)
{
	t_list *testlist;

	testlist = NULL;
	load_test(&testlist, "New", &basic_test);
	load_test(&testlist, "Insert", &insert_test);
	load_test(&testlist, "Remove", &remove_test);
	return (launch_tests("SETUP", testlist));
}
