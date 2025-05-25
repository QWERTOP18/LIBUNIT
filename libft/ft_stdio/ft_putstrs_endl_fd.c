/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrs_endl_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 23:38:31 by ymizukam          #+#    #+#             */
/*   Updated: 2025/03/26 03:13:24 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

int	ft_putstrs_endl_fd(char **strs, char *delimiter, int fd)
{
	int		count;
	int		i;
	char	*str;

	if (!strs || !delimiter)
		return (0);
	count = 0;
	i = 0;
	while (strs[i])
	{
		if (i > 0)
			count += ft_putstr_fd(delimiter, fd);
		str = strs[i];
		count += ft_putstr_fd(str, fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
	return (count + 1);
}
