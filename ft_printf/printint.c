/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:53:18 by klamachi          #+#    #+#             */
/*   Updated: 2024/11/25 11:34:24 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printint(int n, int *count)
{
	if (n == -2147483648)
		return (*count += write(1, "-2147483648", 11));
	if (n < 0)
	{
		n = -n;
		ft_write_incr('-', count);
	}
	if (n >= 0 && n <= 9)
	{
		ft_write_incr(n + '0', count);
		return (*count);
	}
	printint(n / 10, count);
	ft_write_incr(n % 10 + '0', count);
	return (*count);
}
