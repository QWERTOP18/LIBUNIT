/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher_example.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:55:05 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/25 15:11:49 by ymizukam         ###   ########.fr       */
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

int	launch_example(void)
{
	t_list	*testlist;

	testlist = NULL;
	load_test(&testlist, "Basic test", &basic_test);
	load_test(&testlist, "Segv test", &segv_test);
	load_test(&testlist, "Bus test", &bus_test);
	load_test(&testlist, "OK test", &ok_test);
	load_test(&testlist, "KO test", &ko_test);
	load_test(&testlist, "Timeout test", &timeout_test);
	load_test(&testlist, "Abort test", &abrt_test);
	load_test(&testlist, "FPE test", &fpe_test);
	load_test(&testlist, "ILL test", &ill_test);
	load_test(&testlist, "Pipe test", &pipe_test);
	return (launch_tests("EXAMPLE", testlist));
}
