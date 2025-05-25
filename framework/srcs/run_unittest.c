/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_unittest.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izen <izen@student.42tokyo.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:29:29 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/25 20:22:49 by izen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	run_unittest(void *vtest)
{
	t_unittest	*test;
	pid_t		pid;
	int			status;
	int			pipefd[2];

	test = (t_unittest *)vtest;
	if (!test || !test->func)
		return (-1);
	if (pipe(pipefd) == -1)
		return (-1);
	pid = fork();
	if (pid < 0)
		return (-1);
	else if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		alarm(TIMEOUT);
		exit(test->func());
	}
	close(pipefd[1]);
	wait(&status);
	if (WIFSIGNALED(status))
		return (close(pipefd[0]), WTERMSIG(status));
	else if (WIFEXITED(status) && assert_output(pipefd[0], test->output) == 0)
		return (close(pipefd[0]), WEXITSTATUS(status));
	return (close(pipefd[0]), -1);
}
