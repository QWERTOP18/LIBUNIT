/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:04:00 by ymizukam          #+#    #+#             */
/*   Updated: 2025/03/26 03:14:02 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_substr_r(const char *str, char delimiter)
{
	char	*pos;

	if (!str)
		return (NULL);
	pos = ft_strchr(str, delimiter);
	if (!pos)
		return (ft_strdup(""));
	return (ft_strdup(pos + 1));
}
