/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:55:02 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/25 18:25:10 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	launch_example(void);

int	main(void)
{
	int	status;

	status = 0;
	status |= launch_example();
	return (status * -1);
}
