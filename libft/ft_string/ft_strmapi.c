/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:25:25 by ymizukam          #+#    #+#             */
/*   Updated: 2025/03/26 03:13:24 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*r;

	if (!s || !f)
		return (NULL);
	i = 0;
	r = ft_strdup(s);
	if (r)
	{
		while (r[i])
		{
			r[i] = f(i, r[i]);
			i++;
		}
	}
	return (r);
}
