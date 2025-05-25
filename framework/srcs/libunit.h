/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:54:17 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/25 19:44:35 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include "libft.h"
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <wait.h>

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"

# define TIMEOUT 2

typedef struct s_unittest
{
	char	*name;
	int		(*func)(void);
	char	*output;
}			t_unittest;

void		load_test(t_list **l, const char *name, int (*func)(void));
void		load_test_with_output(t_list **l, const char *name,
				int (*func)(void), char *output);
int			launch_tests(const char *func_name, t_list *l);
void		clean_tests(t_list **l);
int			assert_output(int fd, const char *expected);
int			run_unittest(void *vtest, int fd);

/*          Util          */
void		*test_new(const char *name, int (*func)(void), char *output);
void		test_free(void *test);
void		*xmalloc(size_t size);
#endif
