/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 08:45:45 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/13 14:52:13 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_images(void *mlx, t_images *img)
{
    int width, height;

    img->wall = mlx_xpm_file_to_image(mlx, "wall.xpm", &width, &height);
    img->floor = mlx_xpm_file_to_image(mlx, "floor.xpm", &width, &height);
    img->player = mlx_xpm_file_to_image(mlx, "player.xpm", &width, &height);
    img->collectible = mlx_xpm_file_to_image(mlx, "collectible.xpm", &width, &height);
    img->exit = mlx_xpm_file_to_image(mlx, "exit.xpm", &width, &height);
    if (!img->wall || !img->floor || !img->player || !img->collectible || !img->exit)
    {
        perror("Image not found!!");
        exit(1);
    }
}

void    put_img(t_data *data, char tile, int j, int i)
{
    if (tile == '1')
        mlx_put_image_to_window(data->mlx, data->win, data->img.wall, (j * data->img.tile_size), (i * data->img.tile_size));
    else if (tile == '0')
        mlx_put_image_to_window(data->mlx, data->win, data->img.floor, (j * data->img.tile_size), (i * data->img.tile_size));
    else if (tile == 'P')
        mlx_put_image_to_window(data->mlx, data->win, data->img.player, (j * data->img.tile_size), (i * data->img.tile_size));
    else if (tile == 'C')
        mlx_put_image_to_window(data->mlx, data->win, data->img.collectible, (j * data->img.tile_size), (i * data->img.tile_size));
    else if (tile == 'E')
        mlx_put_image_to_window(data->mlx, data->win, data->img.exit, (j * data->img.tile_size), (i * data->img.tile_size));
}

void    draw_map(t_data *data)
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

void    ft_freee(char ***ptr)
{
    int i;

    i = 0;
    if (*ptr)
    {
        while ((*ptr)[i])
        {
            free((*ptr)[i]);
            i++;
        }
    }
    free(*ptr);
    *ptr = NULL;
}


void    ft_free_img(void *mlx, t_images *img)
{
    if (img->wall)
        mlx_destroy_image(mlx, img->wall);
    if (img->player)
        mlx_destroy_image(mlx, img->player);
    if (img->collectible)
        mlx_destroy_image(mlx, img->collectible);
    if (img->floor)
        mlx_destroy_image(mlx, img->floor);
    if (img->exit)
        mlx_destroy_image(mlx, img->exit);
}

int close_window(t_data *data)
{
    ft_freee(&(data->map));
    ft_free_img(data->mlx, &(data->img));
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    exit(0);
    return (0);
}



// #include <stdio.h>

// int press_key(int key, t_data *data)
// {
//     if (key == 65307)
//         close_window(data);
//     else if (key == 100)
//     {
//         if (data->map[data->player_y][data->player_x + 1] != '1')
//         {
//             data->map[data->player_y][data->player_x] = '0';
//             data->player_x += 1;
//             data->map[data->player_y][data->player_x] = 'P';
//             mlx_clear_window(data->mlx, data->win);
//             draw_map(data);
//         }
//     }
//     return (0);
// }


int press_key(int key, t_data *data)
{
    if (key == 65307)
        close_window(data);
    else if (key == 100 || key == 97 || key == 115 || key == 119)
    {
        if (key == 100)
        {
            if (data->map[data->player_y][data->player_x + 1] != '1')
            {
                data->map[data->player_y][data->player_x] = '0';
                data->player_x += 1;
                if ((data->map[data->player_y][data->player_x] == 'E') && (data->c_ate == data->nb_collectibles))
                    close_window(data);
            }
        }
        else if (key == 97)
        {
            if (data->map[data->player_y][data->player_x - 1] != '1')
            {
                data->map[data->player_y][data->player_x] = '0';
                data->player_x -= 1;
                if ((data->map[data->player_y][data->player_x] == 'E') && (data->c_ate == data->nb_collectibles))
                    close_window(data);
            }
        }
        else if (key == 115)
        {
            if (data->map[data->player_y + 1][data->player_x] != '1')
            {
                data->map[data->player_y][data->player_x] = '0';
                data->player_y += 1;
                if ((data->map[data->player_y][data->player_x] == 'E') && (data->c_ate == data->nb_collectibles))
                    close_window(data);
            }
        }
        else if (key == 119)
        {
            if (data->map[data->player_y - 1][data->player_x] != '1')
            {
                data->map[data->player_y][data->player_x] = '0';
                data->player_y -= 1;
            }
        }
        if ((data->map[data->player_y][data->player_x] == 'E') && (data->c_ate == data->nb_collectibles))
            close_window(data);
    }
    else
        return (0);
    if (data->map[data->player_y][data->player_x] == 'C')
    {
        data->c_ate++;
        printf("nb_collectibles_ate : %d\n", data->c_ate);
    }
    data->map[data->player_y][data->player_x] = 'P';
    mlx_clear_window(data->mlx, data->win);
    draw_map(data);
    return (0);
}

int main(int argc, char **argv)
{
    t_data  data;
    int height_map;
    size_t width_map;
    data.player_x = 1;
    data.player_y = 1;
    data.c_ate = 0;
    data.nb_collectibles = 0;

    if (argc < 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    data.img.tile_size = 32;
    data.map = handle_input(&data, argv[1], &height_map, &width_map);
    data.mlx = mlx_init();
    data.win = mlx_new_window(data.mlx, (width_map * data.img.tile_size), (height_map * data.img.tile_size), "so_long");
    load_images(data.mlx, &(data.img));
    draw_map(&data);
    mlx_hook(data.win, 17, 0, close_window, &data);
    mlx_key_hook(data.win, press_key, &data);
    mlx_loop(data.mlx);
}

