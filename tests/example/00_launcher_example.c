/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher_example.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:55:05 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/25 19:52:19 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	basic_test(void);
int	segv_test(void);
int	bus_test(void);
int	ok_test(void);
int	ko_test(void);
int	timeout_test(void);
int	abrt_test(void);
int	fpe_test(void);
int	ill_test(void);
int	pipe_test(void);
int	stdout_test(void);

int	launch_example(void)
{
	t_list	*testlist;

	testlist = NULL;
	load_test(&testlist, "Basic", &basic_test);
	load_test(&testlist, "Segv", &segv_test);
	load_test(&testlist, "Bus", &bus_test);
	load_test(&testlist, "OK", &ok_test);
	load_test(&testlist, "KO", &ko_test);
	load_test(&testlist, "Timeout", &timeout_test);
	load_test(&testlist, "Abort", &abrt_test);
	load_test(&testlist, "FPE", &fpe_test);
	load_test(&testlist, "ILL", &ill_test);
	load_test(&testlist, "Pipe", &pipe_test);
	load_test_with_output(&testlist, "Stdout OK", &stdout_test,
		"Hello Kotaro!\n");
	load_test_with_output(&testlist, "Stdout KO", &stdout_test,
		"ASSERT ERROR\n");
	return (launch_tests("EXAMPLE", testlist));
}
