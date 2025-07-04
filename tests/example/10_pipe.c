/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10.pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 15:10:36 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/25 15:10:45 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	pipe_test(void)
{
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		return (0);
	close(pipefd[0]);
	write(pipefd[1], "x", 1);
	return (0);
}
