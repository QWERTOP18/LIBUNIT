/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 02:17:37 by ymizukam          #+#    #+#             */
/*   Updated: 2025/03/26 03:13:24 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stddef.h>

unsigned int	ft_abs(int n);
int				ft_atoi(const char *str);
long			ft_atol(const char *nptr);
void			*ft_calloc(size_t count, size_t size);
char			*ft_itoa(int n);
char			*ft_ltoa(long n);
void			*ft_orealloc(void *ptr, size_t oldsize, size_t size);
void			*ft_oreallocf(void *ptr, size_t oldsize, size_t size);
void			ft_strs_clear(void *ptr);
void			ft_qsort(void *base, size_t nmemb, size_t size,
					int (*compar)(const void *, const void *));
long			ft_strtol(const char *nptr, char **endptr, int base);
long long		ft_strtoll(const char *nptr, char **endptr, int base);
char			*ft_utoa(unsigned int n);

#endif