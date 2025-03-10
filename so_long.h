/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 08:46:12 by klamachi          #+#    #+#             */
/*   Updated: 2025/03/10 10:22:20 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

typedef struct s_images
{
	void	*wall;
	void	*player;
	void	*collectible;
	void	*exit;
	void	*floor;
	int		tile_size;
}		t_images;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	t_images	img;
	int			cate;
	int			nb_e;
	int			nbcol;
	int			player_x;
	int			player_y;
	int			nb_moves;
}		t_data;

// handle the input
char	**handle_input(t_data *data, char *path, int *nbLines, size_t *lenLine);
void	exit_with_error(char **map, const char *msg);
int		is_rectangular(int fd, size_t *len_line);
void	is_valid_path_ext(char *path);
// flood_fill
void	find_player(char **map, int *x, int *y);
void	flood_fill(t_data *data, char **test_map, int p_x, int p_y);
char	**map_copy(char **map, int nb_lines, int len_line);
void	player_path(t_data *data, int map_height, int map_width);

//draw window, images
void	load_images(t_data *data);
void	put_img(t_data *data, char tile, int j, int i);
void	draw_map(t_data *data);

//check wall and characters
void	check_walls(char **ptr);
int		is_wall(char *line, char c);
void	check_map_characters(char **ptr, t_data *data);
int		is_valid_character(char *line);
int		count_repeat(const char *line, char c);

// free & close 
int		close_window(t_data *data);
void	ft_free_img(void *mlx, t_images *img);
void	ft_freee(char ***ptr);
void	free_gnl(char **reminder);
void	free_line(char *line, const char *msg, char **reminder);

// utils
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);

#endif
