/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 08:45:45 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/17 23:48:11 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	one_step(int *player_x, int *player_y, int x, int y)
{
	*player_x += x;
	*player_y += y;
}

void	stepping(t_data *data, int x, int y)
{
	static int	exit;
	char		next_pos;

	next_pos = data->map[data->player_y + y][data->player_x + x];
	if (next_pos == 'E' && data->cate == data->nbcol)
		close_window(data);
	else if (next_pos == 'C' || next_pos == '0' || next_pos == 'E')
	{
		if (exit == 1)
			data->map[data->player_y][data->player_x] = 'E';
		else
			data->map[data->player_y][data->player_x] = '0';
		data->player_x += x;
		data->player_y += y;
		if (data->map[data->player_y][data->player_x] == 'C')
			data->cate++;
		data->nb_moves++;
		ft_printf("nb_moves : %d\n", data->nb_moves);
		exit = 0;
		if (data->map[data->player_y][data->player_x] == 'E')
			exit = 1;
		data->map[data->player_y][data->player_x] = 'P';
	}
}

int	press_key(int key, t_data *data)
{
	int (x), (y);
	x = 0;
	y = 0;
	if (key == 65307)
		close_window(data);
	else if (key == 100)
		x = 1;
	else if (key == 97)
		x = -1;
	else if (key == 115)
		y = 1;
	else if (key == 119)
		y = -1;
	if (x == 0 && y == 0)
		return (0);
	stepping(data, x, y);
	mlx_clear_window(data->mlx, data->win);
	draw_map(data);
	return (0);
}

static void	initialize_data(t_data *data)
{
	data->player_x = 1;
	data->player_y = 1;
	data->cate = 0;
	data->nbcol = 0;
	data->nb_moves = 0;
	data->cate = 0;
	data->nb_E = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		height_map;
	size_t	width_map;

	initialize_data(&data);
	if (argc < 2)
		return (write(2, "Error\nUsage: ./so_long <map_file.ber>\n", 38), 0);
	data.img.tile_size = 32;
	data.map = handle_input(&data, argv[1], &height_map, &width_map);
	player_path(&data, height_map, width_map);
	data.cate = 0;
	data.mlx = mlx_init();
	if (!data.mlx)
		return (write(2, "Error\nMLX failed to initialize\n", 32), 1);
	data.win = mlx_new_window(data.mlx, (width_map * data.img.tile_size),
			(height_map * data.img.tile_size), "so_long");
	if (!data.win)
		return (write(2, "Error\nMLX failed to open the window\n", 32), 1);
	load_images(data.mlx, &(data.img));
	draw_map(&data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_hook(data.win, 2, 1L << 0, press_key, &data);
	mlx_loop(data.mlx);
}
