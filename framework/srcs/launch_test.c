/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izen <izen@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:54:23 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/25 19:40:11 by izen             ###   ########.fr       */
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

char	*str_status_plain(int status)
{
	if (status == 0)
		return ("[OK]");
	else if (status == SIGSEGV)
		return ("[SEGV]");
	else if (status == SIGBUS)
		return ("[BUS]");
	else if (status == SIGABRT)
		return ("[ABRT]");
	else if (status == SIGFPE)
		return ("[FPE]");
	else if (status == SIGILL)
		return ("[ILL]");
	else if (status == SIGPIPE)
		return ("[PIPE]");
	else if (status == SIGALRM)
		return ("[TIMEOUT]");
	else
		return ("[KO]");
}

void	log_result(const char *func_name, const char *test_name, int result,
		int fd)
{
	ft_putstr_fd((char *)func_name, 1);
	ft_putstr_fd(": ", 1);
	ft_putstr_fd((char *)test_name, 1);
	ft_putstr_fd(" : ", 1);
	ft_putendl_fd(str_status(result), 1);
	ft_putstr_fd((char *)func_name, fd);
	ft_putstr_fd(": ", fd);
	ft_putstr_fd((char *)test_name, fd);
	ft_putstr_fd(" : ", fd);
	ft_putendl_fd(str_status_plain(result), fd);
}

int	launch_tests(const char *func_name, t_list *l)
{
	int			success;
	int			lsize;
	t_list		*current;
	t_unittest	*test;
	int			status;
	char		*file_name;
	int			fd;

	success = 0;
	lsize = ft_lstsize(l);
	current = l;
	file_name = ft_strjoin(func_name, ".log");
	fd = open(file_name, O_CREAT | O_WRONLY | O_APPEND, 0644);
	free(file_name);
	if (fd == -1)
	{
		perror("Failed to open log file");
		return (-1);
	}
	ft_putstr_fd("[Function] ", fd);
	ft_putstr_fd((char *)func_name, fd);
	ft_putstr_fd("\n[Test Count] ", fd);
	ft_putnbr_fd(lsize, fd);
	ft_putstr_fd("\n\n", fd);
	while (current)
	{
		test = (t_unittest *)current->data;
		status = run_unittest(test);
		if (status == 0)
			success++;
		log_result(func_name, test->name, status, fd);
		current = current->next;
	}
	ft_putstr_fd("\n[Summary] ", fd);
	ft_putnbr_fd(success, fd);
	ft_putstr_fd("/", fd);
	ft_putnbr_fd(lsize, fd);
	ft_putstr_fd(" tests passed\n", fd);
	close(fd);
	ft_printf("%d/%d tests checked\n", success, lsize);
	clean_tests(&l);
	if (success == lsize)
		return (0);
	return (-1);
}
