/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 18:14:59 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/25 18:15:01 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	new_test(void);
int	insert_test(void);
int	remove_test(void);
int	size_test(void);
int	full_test(void);

int	launch_setup(void)
{
	t_list	*testlist;

	testlist = NULL;
	load_test(&testlist, "New", &new_test);
	load_test(&testlist, "Insert", &insert_test);
	load_test(&testlist, "Remove", &remove_test);
	load_test(&testlist, "Size", &size_test);
	load_test(&testlist, "Full", &full_test);
	return (launch_tests("SETUP", testlist));
}
