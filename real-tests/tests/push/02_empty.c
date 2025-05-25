/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_empty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:55:08 by ymizukam          #+#    #+#             */
/*   Updated: 2025/05/25 15:40:05 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cyclic_list.h"
#include "libunit.h"

int empty_test(void)
{
    t_clst *list_a;
    t_clst *list_b;

    list_a = clst_new(5);
    list_b = clst_new(10);
    if (!list_a || !list_b)
        return (-1);
    if (push(list_a, list_b) != 1)
    {
        clst_clear(list_a);
        clst_clear(list_b);
        return (-1);
    }
    clst_clear(list_a);
    clst_clear(list_b);
    return (0);
}
