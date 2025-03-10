/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uns_des.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:40:20 by klamachi          #+#    #+#             */
/*   Updated: 2024/11/25 11:34:42 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_uns_des(unsigned int n, int *count)
{
	if (n <= 9)
	{
		ft_write_incr(n + '0', count);
		return (*count);
	}
	print_uns_des(n / 10, count);
	ft_write_incr(n % 10 + '0', count);
	return (*count);
}
