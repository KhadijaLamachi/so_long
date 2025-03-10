/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:57:27 by klamachi          #+#    #+#             */
/*   Updated: 2024/11/25 10:11:17 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>

int		printchr(int c, int *count);
int		printstr(const char *s, int *count);
int		printint(int n, int *count);
int		print_uns_des(unsigned int n, int *count);
int		print_exa(unsigned int n, char x, int *count);
int		printpointer(void *p, int *count);
void	ft_write_incr(int c, int *count);
int		ft_printf(const char *s, ...);
#endif