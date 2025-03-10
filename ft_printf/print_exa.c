/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:35:48 by klamachi          #+#    #+#             */
/*   Updated: 2024/11/25 11:39:57 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_exa_lo(unsigned int n, int *count)
{
	char	*exa;

	exa = "0123456789abcdef";
	if (n < 16)
	{
		ft_write_incr(exa[n], count);
		return (*count);
	}
	print_exa_lo(n / 16, count);
	ft_write_incr(exa[n % 16], count);
	return (*count);
}

static int	print_exa_up(unsigned int n, int *count)
{
	char	*exa;

	exa = "0123456789ABCDEF";
	if (n < 16)
	{
		ft_write_incr(exa[n], count);
		return (*count);
	}
	print_exa_up(n / 16, count);
	ft_write_incr(exa[n % 16], count);
	return (*count);
}

int	print_exa(unsigned int n, char x, int *count)
{
	if (x == 'x')
		return (print_exa_lo(n, count));
	if (x == 'X')
		return (print_exa_up(n, count));
	return (0);
}
