/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:52:08 by klamachi          #+#    #+#             */
/*   Updated: 2024/11/25 11:33:03 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printstr(const char *s, int *count)
{
	if (s == NULL)
	{
		*count += write(1, "(null)", 6);
		return (*count);
	}
	while (*s)
	{
		write(1, s++, 1);
		(*count)++;
	}
	return (*count);
}
