/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printpointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:42:49 by klamachi          #+#    #+#             */
/*   Updated: 2024/11/25 11:36:18 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_exa_lo_lx(unsigned long n, int *count)
{
	char	*exa;

	exa = "0123456789abcdef";
	if (n < 16)
	{
		ft_write_incr(exa[n], count);
		return (*count);
	}
	print_exa_lo_lx(n / 16, count);
	ft_write_incr(exa[n % 16], count);
	return (*count);
}

int	printpointer(void *p, int *count)
{
	if (p == NULL)
	{
		return (*count += write(1, "(nil)", 5));
	}
	write(1, "0x", 2);
	(*count) += 2;
	return (print_exa_lo_lx((unsigned long)p, count));
}
