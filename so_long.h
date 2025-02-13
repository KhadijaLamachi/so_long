/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 08:46:12 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/13 14:46:47 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stddef.h>
#include <fcntl.h>
#include "mlx.h"
#include "get_next_line/get_next_line.h"

typedef struct s_images
{
    void *wall;
    void *player;
    void *collectible;
    void *exit;
    void *floor;
    int tile_size;
} t_images;

typedef struct s_data
{
    void    *mlx;
    void    *win;
    char    **map;
    t_images    img;
    int c_ate;
    int nb_collectibles;
    int player_x;  // Added player x coordinate
    int player_y;  // Added player y coordinate
}               t_data;


// Function declarations
void load_images(void *mlx, t_images *images);
void    draw_map(t_data *data);
// void draw_map(void *mlx, void *win, char **map, t_images images);


// handle the input
void    is_valid_path_ext(char *path);
char    **handle_input(t_data  *data, char *path, int *height_map, size_t *width_map);
int    is_rectangular(int fd, size_t *len_line);
void check_walls(char **ptr);
void    check_map_characters(char **ptr, t_data  *data);
void exit_with_error(char **map, const char *msg);


int    is_wall(char *line, char c);
int    is_valid_character(char *line);
int count_repeat(const  char *line, char c);



char	*ft_strrchr(const char *s, int c);
int	ft_strcmp(const char *s1, const char *s2);

#endif









// #ifndef SO_LONG_H
// # define SO_LONG_H

// #include <stddef.h>
// #include <fcntl.h>
// #include "mlx.h"
// #include "get_next_line/get_next_line.h"

// // typedef struct so_long{
// //     // void    *mlx;
// //     // int player_x;
// //     // int player_y;
// //     // int count_moves;
// // }   so_long;

// // handle the input
// void    is_valid_path_ext(char *path);
// int    handle_input(char *path);
// int    is_rectangular(int fd);
// void check_walls(char **ptr);
// void    check_map_characters(char **ptr);
// void exit_with_error(char **map, const char *msg);


// int    is_wall(char *line, char c);
// int    is_valid_character(char *line);
// int count_repeat(const  char *line, char c);



// char	*ft_strrchr(const char *s, int c);
// int	ft_strcmp(const char *s1, const char *s2);

// #endif