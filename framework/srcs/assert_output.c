/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:27:05 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/25 19:59:39 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	assert_output(int fd, const char *expected)
{
	char	buffer[1024];
	int		bytes_read;
	int		result;

	if (fd < 0)
		return (-1);
	if (!expected)
		return (0);
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	if (bytes_read < 0)
		return (-1);
	buffer[bytes_read] = '\0';
	result = ft_strcmp(buffer, expected);
	if (result == 0)
		return (0);
	else
		return (1);
}
