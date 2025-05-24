/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:23:19 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/17 21:18:00 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strs_clear(void *ptr)
{
	char	**array;
	size_t	i;

	i = 0;
	array = (char **)ptr;
	if (!array)
		return ;
	while (array[i])
		free(array[i++]);
	free(array);
}
