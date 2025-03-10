/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:25:46 by klamachi          #+#    #+#             */
/*   Updated: 2025/03/10 10:29:32 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(t_data *data)
{
	int (width), (height);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm",
			&width, &height);
	data->img.floor = mlx_xpm_file_to_image(data->mlx, "textures/floor.xpm",
			&width, &height);
	data->img.player = mlx_xpm_file_to_image(data->mlx, "textures/player.xpm",
			&width, &height);
	data->img.collectible = mlx_xpm_file_to_image(data->mlx,
			"textures/collectible.xpm", &width, &height);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, "textures/exit.xpm",
			&width, &height);
	if (!data->img.wall || !data->img.floor || !data->img.player
		|| !data->img.collectible || !data->img.exit)
	{
		perror("Error\nImage not found!!");
		close_window(data);
	}
}

void	put_img(t_data *data, char tile, int j, int i)
{
	if (tile == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall, (j
				* data->img.tile_size), (i * data->img.tile_size));
	else if (tile == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img.floor, (j
				* data->img.tile_size), (i * data->img.tile_size));
	else if (tile == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->img.player, (j
				* data->img.tile_size), (i * data->img.tile_size));
	else if (tile == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img.collectible, (j
				* data->img.tile_size), (i * data->img.tile_size));
	else if (tile == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img.exit, (j
				* data->img.tile_size), (i * data->img.tile_size));
}

void	draw_map(t_data *data)
{
	int (i), (j);
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			put_img(data, data->map[i][j], j, i);
			j++;
		}
		i++;
	}
}
