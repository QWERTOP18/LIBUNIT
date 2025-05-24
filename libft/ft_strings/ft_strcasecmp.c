/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 03:26:20 by ymizukam          #+#    #+#             */
/*   Updated: 2025/03/26 03:13:24 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ctype.h"

int	ft_strcasecmp(const char *s1, const char *s2)
{
	unsigned char	c1;
	unsigned char	c2;

	while (1)
	{
		c1 = (unsigned char)ft_tolower((unsigned char)*s1++);
		c2 = (unsigned char)ft_tolower((unsigned char)*s2++);
		if (c1 != c2 || c1 == '\0')
			return (c1 - c2);
	}
	return (0);
}
