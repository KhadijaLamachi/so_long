/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_characters.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:29:40 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/17 10:51:13 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_repeat(const char *line, char c)
{
	int	count;

	count = 0;
	while (*line)
	{
		if (*line == c)
			count++;
		line++;
	}
	return (count);
}

int	is_valid_character(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] != 'P') && (line[i] != 'C') && (line[i] != 'E')
			&& (line[i] != '1') && (line[i] != '0') && (line[i] != '\n'))
			return (1);
		i++;
	}
	return (0);
}

void	check_map_characters(char **ptr, t_data *data)
{
	int (P), (C), (E), (i);
	P = 0;
	C = 0;
	E = 0;
	i = -1;
	while (ptr[++i])
	{
		if (is_valid_character(ptr[i]) == 1)
			exit_with_error(ptr, "Error\nInvalid character!!!\n");
		P += count_repeat(ptr[i], 'P');
		C += count_repeat(ptr[i], 'C');
		E += count_repeat(ptr[i], 'E');
	}
	if (P != 1)
		exit_with_error(ptr, "Error\nThe number of player is incorrect!!!\n");
	if (C < 1)
		exit_with_error(ptr,
			"Error\nThe number of collectible is incorrect!!!\n");
	if (E != 1)
		exit_with_error(ptr,
			"Error\nThe number of the map exit is incorrect!!!\n");
	data->nbcol = C;
}

int	is_wall(char *line, char c)
{
	size_t	len;
	int		i;

	len = ft_strlen(line);
	i = 0;
	if (line[len - 1] == '\n')
	{
		len--;
		line[len] = '\0';
	}
	if (c == 's' && (line[0] != '1' || line[len - 1] != '1'))
		return (1);
	if ((c == 't' || c == 'b'))
	{
		while (line[i])
		{
			if (line[i] != '1')
				return (1);
			i++;
		}
	}
	return (0);
}

void	check_walls(char **ptr)
{
	int		i;
	char	*prev_line;

	i = 0;
	if (is_wall(ptr[0], 't') == 1)
		exit_with_error(ptr, "Error\nWall problem!!!\n");
	while (ptr[i])
	{
		if (is_wall(ptr[i], 's') == 1)
			exit_with_error(ptr, "Error\nWall problem!!!\n");
		prev_line = ptr[i];
		i++;
	}
	if (is_wall(prev_line, 'b') == 1)
		exit_with_error(ptr, "Error\nWall problem!!!\n");
}
