/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 03:07:27 by ymizukam          #+#    #+#             */
/*   Updated: 2025/03/26 03:13:24 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "ft_string.h"
#include "ft_utils.h"
#include <stdlib.h>

static char	**ft_nsplit(const char *s, char c, size_t len)
{
	char	**r;
	char	**r_head;

	r_head = (char **)ft_calloc(len + 1, sizeof(char *));
	r = r_head;
	while (r_head && len--)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		*r = (char *)s;
		while (*s && *s != c)
			s++;
		*r = ft_strndup(*r, s - *r);
		if (!*r++)
		{
			while (r_head <= r - 1)
				free(*(--r - 1));
			free(r_head);
			return (NULL);
		}
	}
	return (r_head);
}

char	**ft_split(char const *s, char c)
{
	return (ft_nsplit(s, c, ft_count_words(s, c)));
}
