/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:14:32 by ymizukam          #+#    #+#             */
/*   Updated: 2025/03/26 03:13:48 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"
#include <stddef.h>

char	*ft_ltoa(long n)
{
	char			buffer[21];
	unsigned long	un;
	char			*c;

	c = &buffer[21];
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
