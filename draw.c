/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:25:46 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/17 10:51:57 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_images(void *mlx, t_images *img)
{
	int (width), (height);
	img->wall = mlx_xpm_file_to_image(mlx, "wall.xpm", &width, &height);
	img->floor = mlx_xpm_file_to_image(mlx, "floor.xpm", &width, &height);
	img->player = mlx_xpm_file_to_image(mlx, "player.xpm", &width, &height);
	img->collectible = mlx_xpm_file_to_image(mlx, "collectible.xpm", &width,
			&height);
	img->exit = mlx_xpm_file_to_image(mlx, "exit.xpm", &width, &height);
	if (!img->wall || !img->floor || !img->player || !img->collectible
		|| !img->exit)
	{
		perror("Image not found!!");
		exit(1);
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
