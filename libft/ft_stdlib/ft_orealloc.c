/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_orealloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 03:51:06 by ymizukam          #+#    #+#             */
/*   Updated: 2025/03/26 03:13:24 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>
#include <stdlib.h>

void	*ft_orealloc(void *ptr, size_t oldsize, size_t size)
{
	void	*newptr;

	if (!ptr)
		return (malloc(size));
	if (!size)
		return (free(ptr), NULL);
	newptr = malloc(size);
	if (!newptr)
		return (NULL);
	if (oldsize < size)
		ft_memcpy(newptr, ptr, oldsize);
	else
		ft_memcpy(newptr, ptr, size);
	free(ptr);
	return (newptr);
}
