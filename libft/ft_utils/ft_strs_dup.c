/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 02:11:55 by ymizukam          #+#    #+#             */
/*   Updated: 2025/03/26 03:13:24 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"
#include <stdlib.h>

char	**ft_strs_dup(char **ss)
{
	char	**dup;
	int		i;

	if (!ss)
		return (NULL);
	i = 0;
	while (ss[i])
		i++;
	dup = (char **)malloc(sizeof(char *) * (i + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (ss[i])
	{
		dup[i] = ft_strdup(ss[i]);
		if (!dup[i])
			return (ft_strs_clear(dup), NULL);
		i++;
	}
	dup[i] = NULL;
	return (dup);
}
