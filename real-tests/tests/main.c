/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:55:38 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/25 17:07:03 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	launch_setup(void);
int	launch_rotate(void);
int	launch_swap(void);
int	launch_push(void);
int	launch_reverse_rotate(void);

int	main(void)
{
	int	status;

	status = 0;
	status |= launch_setup();
	status |= launch_swap();
	status |= launch_push();
	status |= launch_rotate();
	status |= launch_reverse_rotate();
	return (status * -1);
}
