/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:02:57 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/17 23:57:06 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(char **map, int *x, int *y)
{
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x])
		{
			if (map[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

void	flood_fill(t_data *data, char **test_map, t_point player, int map_height, int map_width)
{
	if (test_map[player.y][player.x] == '1' || test_map[player.y][player.x] == 'V')
		return ;
	else if (test_map[player.y][player.x] == 'C')
		data->cate++;
	else if (test_map[player.y][player.x] == 'E')
		data->nb_E++;
	test_map[player.y][player.x] = 'V';
	flood_fill(data, test_map, (t_point){player.x, player.y + 1}, map_height, map_width);
	flood_fill(data, test_map, (t_point){player.x, player.y - 1}, map_height, map_width);
	flood_fill(data, test_map, (t_point){player.x + 1, player.y}, map_height, map_width);
	flood_fill(data, test_map, (t_point){player.x - 1, player.y}, map_height, map_width);
}

char **map_copy(char **map, int nb_lines, int len_line)
{
	int	i;
	int	j;
	char **test_map;

	i = -1;
	test_map = malloc(sizeof(char *) * (nb_lines + 1));
	if (!test_map)
		return (NULL);
	while (++i < nb_lines)
	{
		test_map[i] = malloc(sizeof(char) * (len_line + 1));
		if (!test_map[i])
			return (ft_freee(&test_map), NULL);
	}
	test_map[i] = NULL;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			test_map[i][j] = map[i][j];
		test_map[i][j] = '\0';
	}
	return (test_map);
}

void	player_path(t_data *data, int map_height, int map_width)
{
	t_point	player;
	char **test_map;
	int x;
	int y;
	
	x = 0;
	y = 0;
	test_map = map_copy(data->map, map_height, map_width);
	find_player(test_map, &x, &y);
	player.x = x;
	player.y = y;
	flood_fill(data, test_map, player, map_height, map_width);
	if ((data->nb_E != 1) || (data->nbcol != data->cate))
	{
		ft_freee(&test_map);
		exit_with_error(data->map, "Error\nThe player cannot reach all collectibles or the exit!");
	}
	ft_freee(&test_map);
}
