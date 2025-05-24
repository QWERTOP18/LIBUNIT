/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 00:09:55 by ymizukam          #+#    #+#             */
/*   Updated: 2025/03/26 03:13:24 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"
#include <stddef.h>

char	*ft_itoa(int n)
{
	char			buffer[12];
	unsigned int	un;
	char			*c;

	c = &buffer[12];
	*--c = '\0';
	un = ft_abs(n);
	while (un || !*c)
	{
		*--c = un % 10 + '0';
		un /= 10;
	}
	if (n < 0)
		*--c = '-';
	return (ft_strdup(c));
}
