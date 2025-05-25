/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:54:31 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/25 19:20:56 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	*xmalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		ft_putstr_fd("Memory allocation failed\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

void	*test_new(const char *name, int (*func)(void), char *output)
{
	t_unittest	*test;

	if (!name || !func)
		return (NULL);
	test = xmalloc(sizeof(t_unittest));
	test->name = ft_strdup(name);
	if (output)
		test->output = ft_strdup(output);
	else
		test->output = NULL;
	test->func = func;
	return (test);
}

void	test_free(void *test)
{
	t_unittest	*t;

	if (!test)
		return ;
	t = (t_unittest *)test;
	free(t->name);
	free(t->output);
	free(t);
}
