/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:54:23 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/25 14:54:24 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	run_unittest(void *vtest)
{
	t_unittest	*test;
	pid_t		pid;
	int			status;

	test = (t_unittest *)vtest;
	if (!test || !test->func)
		return (-1);
	pid = fork();
	if (pid < 0)
	{
		return (-1);
	}
	else if (pid == 0)
	{
		alarm(TIMEOUT);
		exit(test->func());
	}
	wait(&status);
	if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	else if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (-1);
}

char	*str_status(int status)
{
	if (status == 0)
		return (GREEN "[OK]" RESET);
	else if (status == SIGSEGV)
		return (YELLOW "[SEGV]" RESET);
	else if (status == SIGBUS)
		return (YELLOW "[BUS]" RESET);
	else if (status == SIGABRT)
		return (YELLOW "[ABRT]" RESET);
	else if (status == SIGFPE)
		return (YELLOW "[FPE]" RESET);
	else if (status == SIGILL)
		return (YELLOW "[ILL]" RESET);
	else if (status == SIGPIPE)
		return (YELLOW "[PIPE]" RESET);
	else if (status == SIGALRM)
		return (RED "[TIMEOUT]" RESET);
	else
		return (RED "[KO]" RESET);
}

void	log_result(const char *func_name, const char *test_name, int result)
{
	ft_putstr_fd((char *)func_name, 1);
	ft_putstr_fd(": ", 1);
	ft_putstr_fd((char *)test_name, 1);
	ft_putstr_fd(" ", 1);
	ft_putendl_fd(str_status(result), 1);
}

int	launch_tests(const char *func_name, t_list *l)
{
	int			success;
	int			lsize;
	t_list		*current;
	t_unittest	*test;
	int			status;

	success = 0;
	lsize = ft_lstsize(l);
	current = l;
	while (current)
	{
		test = (t_unittest *)current->data;
		status = run_unittest(test);
		if (status == 0)
			success++;
		log_result(func_name, test->name, status);
		current = current->next;
	}
	ft_printf("%d/%d tests checked\n", success, lsize);
	clean_tests(&l);
	if (success == lsize)
		return (0);
	return (-1);
}
