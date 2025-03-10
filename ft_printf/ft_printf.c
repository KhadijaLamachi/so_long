/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 10:51:39 by klamachi          #+#    #+#             */
/*   Updated: 2024/11/26 20:16:33 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format(va_list arg, const char *s, int *count)
{
	if (*s == 'c')
		printchr(va_arg(arg, int), count);
	else if (*s == 's')
		printstr(va_arg(arg, char *), count);
	else if (*s == 'd' || *s == 'i')
		printint(va_arg(arg, int), count);
	else if (*s == 'u')
		print_uns_des(va_arg(arg, unsigned int), count);
	else if (*s == 'x' || *s == 'X')
		print_exa(va_arg(arg, unsigned int), *s, count);
	else if (*s == 'p')
		printpointer(va_arg(arg, void *), count);
	else if (*s == '%')
	{
		ft_write_incr('%', count);
		s++;
	}
	return (*count);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		count;

	if (s == NULL || (s[0] == '%' && s[1] == '\0'))
		return (-1);
	count = 0;
	va_start(arg, s);
	while (*s)
	{
		if (*s != '%')
			ft_write_incr(*s, &count);
		else if (*s++ == '%')
			format(arg, s, &count);
		s++;
	}
	va_end(arg);
	return (count);
}
