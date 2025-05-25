/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_bus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:55:12 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/25 15:07:16 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

int	bus_test(void)
{
	FILE	*fp;
	int		fd;
	char	*map;

	fp = tmpfile();
	if (!fp)
		return (0);
	fd = fileno(fp);
	if (ftruncate(fd, 1) == -1)
		return (0);
	map = mmap(NULL, 4096, PROT_READ, MAP_PRIVATE, fd, 0);
	if (map == MAP_FAILED)
		return (0);
	map[1] = 'X';
	return (0);
}
