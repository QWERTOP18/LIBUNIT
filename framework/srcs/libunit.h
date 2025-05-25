/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:54:17 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/25 15:02:04 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H
# define LIBUNIT_H

# include "libft.h"
# include <signal.h>
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
}			t_unittest;

void		load_test(t_list **l, const char *name, int (*func)(void));
int			launch_tests(const char *func_name, t_list *l);
void		clean_tests(t_list **l);

/*          Util          */
void		*test_new(const char *name, int (*func)(void));
void		test_free(void *test);
void		*xmalloc(size_t size);
#endif
