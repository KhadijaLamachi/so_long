// #include "so_long.h"

// void    load_images(void *mlx, t_images *images)
// {
//     int width;
//     int hight;
//     images->wall = mlx_xpm_file_to_image(mlx, "wall.xpm", &width, &hight);
//     images->player = mlx_xpm_file_to_image(mlx, "player.xpm", &width, &hight);
//     images->collectible = mlx_xpm_file_to_image(mlx, "collectible.xpm", &width, &hight);
//     images->floor = mlx_xpm_file_to_image(mlx, "floor.xpm", &width, &hight);
//     images->exit = mlx_xpm_file_to_image(mlx, "exit.xpm", &width, &hight);
// }

// void draw_map(void *mlx, void *win, char **map, t_images images)
// {
//     int i;
//     int j;
//     int tile_size = 32;

//     i = 0;
//     while (map[i])
//     {
//         j = 0;
//         while (map[i][j])
//         {
//             if (map[i][j] == '1')
//                 mlx_put_image_to_window(mlx, win, images.wall, j * tile_size, i * tile_size);
//             else if (map[i][j] == '0')
//                 mlx_put_image_to_window(mlx, win, images.floor, j * tile_size, i * tile_size);
//             else if (map[i][j] == 'P')
//                 mlx_put_image_to_window(mlx, win, images.player, j * tile_size, i * tile_size);
//             else if (map[i][j] == 'C')
//                 mlx_put_image_to_window(mlx, win, images.collectible, j * tile_size, i * tile_size);
//             else if (map[i][j] == 'E')
//                 mlx_put_image_to_window(mlx, win, images.exit, j * tile_size, i * tile_size);
//             j++;
//         }
//         i++;
//     }
// }

// // void press_key()
// // {
    
// // }

// int main(int argc, char **argv)
// {
//     char **map;
//     int hight_map;
//     size_t  width_map;
//     void    *mlx;
//     void    *win;
//     t_images    images;
//     t_data  data;

//     hight_map = 0;
//     width_map = 0;
//     if (argc < 2)
//     {
//         write(1, "\n", 1);
//         return (0);
//     }
//     data.map = handle_input(argv[1], &hight_map, &width_map);
//     data.mlx = mlx_init();
//     if (!(data.mlx))
//     {
//         perror("Error initializing MiniLibX");
//         return (0);
//     }
//     data.win = mlx_new_window(mlx, (width_map * 32), (hight_map * 32), "so_long");
//     load_images(data.mlx, &images);
//     draw_map(data.mlx, data.win, data.map, images);
//     mlx_loop(data.mlx);
// }





// int press_key(int key, t_data *data)
// {
//     int (x), (y);

//     x = 0;
//     y = 0;
//     if (key == 65307)
//         close_window(data);
//     else if (key == 100)
//         x = 1;
//     else if (key == 97)
//         x = -1;
//     else if (key == 115)
//         y = 1;
//     else if (key == 119)
//         y = -1;
//     if (x != 0 || y != 0)
//         stepping(data, x, y);
//     if ((data->map[data->player_y + y][data->player_x + x] == 'E') && (data->c_ate == data->nb_collectibles))
//         close_window(data);
//     // if (data->map[data->player_y + y][data->player_x + x] == '1')
//     //     return (0);
//     mlx_clear_window(data->mlx, data->win);
//     draw_map(data);
//     return (0);
// }




// void stepping(t_data *data, int x, int y)
// {
//     static int exit;

//     if ((data->map[data->player_y + y][data->player_x + x] == 'E') && (data->c_ate == data->nb_collectibles))
//     {
//         data->map[data->player_y][data->player_x] = '0';
//         one_step(&data->player_x, &data->player_y, x, y);
//         data->map[data->player_y][data->player_x] = 'P';
//         mlx_clear_window(data->mlx, data->win);
//         draw_map(data);
//         close_window(data);
//     }
//     else if ((data->map[data->player_y + y][data->player_x + x] == 'C') || (data->map[data->player_y + y][data->player_x + x] == '0') || (data->map[data->player_y + y][data->player_x + x] == 'E'))
//     {
//         data->map[data->player_y][data->player_x] = '0';
//         if (exit == 1)
//             data->map[data->player_y][data->player_x] = 'E';
//         one_step(&data->player_x, &data->player_y, x, y);
//         if (data->map[data->player_y][data->player_x] == 'C')
//             data->c_ate++;
//         data->nb_moves++;
//         printf("nb_moves : %d\n", data->nb_moves);
//         if (data->map[data->player_y][data->player_x] == 'E')
//             exit = 1;
//         else
//             exit = 0;
//         data->map[data->player_y][data->player_x] = 'P';
//     }
//     else if ((data->map[data->player_y + y][data->player_x + x] == 'E') && (data->c_ate != data->nb_collectibles))
//         one_step(&data->player_x, &data->player_y, x, y);
//     else
//         return ;
// }







111111111111111111111111
1P0000000000000000000001
100000000000000000000001
10111CC01111011110111101
101C1CC0CCC10CCC101CC101
10CC1CC01111011110CCC101
10CC1CC0CCC10CCC10CCC101
101111101111011110CCC101
100000000000000000000001
1000000000000000000000E1
111111111111111111111111








// har    **handle_input(t_data  *data, char *path, int *nb_lines, size_t *len_line)
// {
//     (void)data;
//     (void)path;
//     (void)nb_lines;
//     (void)len_line;
    // int (fd), (i);e
    // char    *line;
    // char    **ptr;

    // ptr = NULL;
    // i = 0;
    // is_valid_path_ext(path);
    // fd = open(path, O_RDONLY);
    // is_rectangular(fd, len_line);
    // *nb_lines = is_rectangular(fd, len_line);
    // close(fd);
    // ptr = malloc(sizeof(char *) * (*nb_lines + 1));
    // if (!ptr)
    //     exit_with_error(ptr, "Error:!!!\n");
    // fd = open(path, O_RDONLY);
    // line = get_next_line(fd);
    // while (line)
    // {
    //     ptr[i] = line;
    //     line = get_next_line(fd);
    //     i++;
    // }
    // ptr[i] = NULL;
    // close(fd);
    // check_walls(ptr);
    // return (check_map_characters(ptr, data), ptr);
// }



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:48:14 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/15 22:26:05 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "so_long.h"
#include <stdio.h>

void    is_valid_path_ext(char *path)
{
    int fd;
    char    *ext;

    ext = ft_strrchr(path, '.');
    if (!ext || ft_strcmp(ext, ".ber"))
    {
        perror("Error: Invalid file extension\n");
        exit(1);
    }
    fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file!!!\n");
        exit(1);
    }
    close(fd);
}

static void free_line(char *line, const char *msg)
{
    free(line);
    perror(msg);
    exit(1);
}

int is_rectangular(int fd, size_t *len_line)
{
   // printf("------>    here   <--------");
    char    *line;
    char *ptr;
    int     nb_lines;

    nb_lines = 0;
    line = get_next_line(fd);
    if (!line)
        free_line(NULL, "Error\nMap is empty!!!\n");
    *len_line = ft_strlen(line);
    ptr = line;
    ptr += *len_line - 1;
    if (*len_line > 0 && line[*len_line - 1] == '\n') 
    {
        (*len_line)--;
        line[*len_line] = '\0';
    }
    while (line)
    {
        if (*len_line != ft_strlen(line))
        {
            free(ptr);
            free_line(line, "Error\nOh sorry, the map is not rectangular!!\n");
        }
        free(line);
        line = get_next_line(fd);
        if (line && ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
            line[ft_strlen(line) - 1] = '\0';
        nb_lines++;
    }
    return (nb_lines);
}

int count_repeat(const  char *line, char c)
{
    int count;

    count = 0;
    while (*line)
    {
        if (*line == c)
            count++;
        line++;
    }
    return (count);
}

void exit_with_error(char **map, const char *msg)
{
    int i;

    if (map)  
    {
        i = 0;
        while (map[i])
        {
            free(map[i]);
            i++;
        }
        free(map);
    }
    perror(msg);
    exit(1);
}

int    is_valid_character(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if ((line[i] != 'P') && (line[i] != 'C') && (line[i] != 'E') && (line[i] != '1') && (line[i] != '0') && (line[i] != '\n'))
            return (1);
        i++;
    }
    return (0);
}

void    check_map_characters(char **ptr, t_data  *data)
{
    int P = 0, C = 0, E = 0, i = 0;

    while (ptr[i])
    {
        if (is_valid_character(ptr[i]) == 1)
            exit_with_error(ptr, "Error:Invalid character!!!\n");
        P += count_repeat(ptr[i], 'P');
        C += count_repeat(ptr[i], 'C');
        E += count_repeat(ptr[i], 'E');
        i++;
    }
    if (P != 1)
    {
        printf("%d\n", P);
        exit_with_error(ptr, "Error:The number of player is incorrect!!!\n");
    }
    if (C < 1)
        exit_with_error(ptr, "Error:The number of collectible is incorrect!!!\n");
    if (E != 1)
        exit_with_error(ptr, "Error:The number of the map exit is incorrect!!!\n");
    data->nb_collectibles = C;
}




// int is_rectangular(int fd, size_t *len_line)
// {
//     char    *line;
//     int     nb_lines;
//     static char *reminder;

//     nb_lines = 0;
//     line = get_next_line(fd, &reminder);
//     if (!line)
//         free_line(NULL, "Error\nMap is empty!!!\n", &reminder);
//     *len_line = ft_strlen(line);
//     while (line)
//     {
//         if (*len_line == ft_strlen(line) || (*len_line - 1) == ft_strlen(line))
//         {
//             if (line[*len_line - 1] == '\0' || line[*len_line - 1] == '\n')
//             {
//                 free(line);
//                 line = get_next_line(fd, &reminder);
//             }
//             else if ()
//                 free_line(line, "Error\nOh sorry, the map is not rectangular!!\n", &reminder);
//         }
//         else
//             free_line(line, "Error\nOh sorry, the map is not rectangular!!\n", &reminder);
//         nb_lines++;
//     }
//     (*len_line)--;
//     return (nb_lines);
// }




int    is_wall(char *line, char c)
{
    size_t len;
    int i;

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

void check_walls(char **ptr)
{
    int i;
    char    *prev_line;

    i = 0;
    if (is_wall(ptr[0], 't') == 1)
        exit_with_error(ptr, "Error:Wall problem!!!\n");
    while (ptr[i])
    {
        if (is_wall(ptr[i], 's') == 1)
            exit_with_error(ptr, "Error:Wall problem!!!\n");
        prev_line = ptr[i];
        i++;
    }
    if (is_wall(prev_line, 'b') == 1)
        exit_with_error(ptr, "Error:Wall problem!!!\n");
}

char    **handle_input(t_data  *data, char *path, int *nb_lines, size_t *len_line)
{
    int (fd), (i);
    char    *line;
    char    **ptr;

    ptr = NULL;
    i = 0;
    is_valid_path_ext(path);
    fd = open(path, O_RDONLY);
    *nb_lines = is_rectangular(fd, len_line);
    close(fd);
    ptr = malloc(sizeof(char *) * (*nb_lines + 1));
    if (!ptr)
        exit_with_error(ptr, "Error:!!!\n");
    fd = open(path, O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        ptr[i] = line;
        line = get_next_line(fd);
        i++;
    }
    ptr[i] = NULL;
    close(fd);
    check_walls(ptr);
    return (check_map_characters(ptr, data), ptr);
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:48:14 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/15 21:13:52 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "so_long.h"
#include <stdio.h>

void    is_valid_path_ext(char *path)
{
    int fd;
    char    *ext;

    ext = ft_strrchr(path, '.');
    if (!ext || ft_strcmp(ext, ".ber"))
    {
        perror("Error: Invalid file extension\n");
        exit(1);
    }
    fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file!!!\n");
        exit(1);
    }
    close(fd);
}

static void free_line(char *line, const char *msg)
{
    free(line);
    perror(msg);
    exit(1);
}

int is_rectangular(int fd, size_t *len_line)
{
    char    *line;
    int     nb_lines;

    nb_lines = 0;
    line = get_next_line(fd);
    printf("%s", line);
    if (!line)
        free_line(NULL, "Error\nMap is empty!!!\n");
    *len_line = ft_strlen(line);
    if (*len_line > 0 && line[*len_line - 1] == '\n') 
    {
        (*len_line)--;
        line[*len_line] = '\0';
    }
    while (line)
    {
        if (*len_line != ft_strlen(line)) 
            free_line(line, "Error\nOh sorry, the map is not rectangular!!\n");
        free(line);
        line = get_next_line(fd);
        if (line && ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
            line[ft_strlen(line) - 1] = '\0';
        nb_lines++;
    }
    return (nb_lines);
}

int count_repeat(const  char *line, char c)
{
    int count;

    count = 0;
    while (*line)
    {
        if (*line == c)
            count++;
        line++;
    }
    return (count);
}

void exit_with_error(char **map, const char *msg)
{
    int i;

    if (map)  
    {
        i = 0;
        while (map[i])
        {
            free(map[i]);
            i++;
        }
        free(map);
    }
    perror(msg);
    exit(1);
}

int    is_valid_character(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if ((line[i] != 'P') && (line[i] != 'C') && (line[i] != 'E') && (line[i] != '1') && (line[i] != '0') && (line[i] != '\n'))
            return (1);
        i++;
    }
    return (0);
}

void    check_map_characters(char **ptr, t_data  *data)
{
    int P = 0, C = 0, E = 0, i = 0;

    while (ptr[i])
    {
        if (is_valid_character(ptr[i]) == 1)
            exit_with_error(ptr, "Error:Invalid character!!!\n");
        P += count_repeat(ptr[i], 'P');
        C += count_repeat(ptr[i], 'C');
        E += count_repeat(ptr[i], 'E');
        i++;
    }
    if (P != 1)
    {
        printf("%d\n", P);
        exit_with_error(ptr, "Error:The number of player is incorrect!!!\n");
    }
    if (C < 1)
        exit_with_error(ptr, "Error:The number of collectible is incorrect!!!\n");
    if (E != 1)
        exit_with_error(ptr, "Error:The number of the map exit is incorrect!!!\n");
    data->nb_collectibles = C;
}

int    is_wall(char *line, char c)
{
    size_t len;
    int i;

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

void check_walls(char **ptr)
{
    int i;
    char    *prev_line;

    i = 0;
    if (is_wall(ptr[0], 't') == 1)
        exit_with_error(ptr, "Error:Wall problem!!!\n");
    while (ptr[i])
    {
        if (is_wall(ptr[i], 's') == 1)
            exit_with_error(ptr, "Error:Wall problem!!!\n");
        prev_line = ptr[i];
        i++;
    }
    if (is_wall(prev_line, 'b') == 1)
        exit_with_error(ptr, "Error:Wall problem!!!\n");
}

char    **handle_input(t_data  *data, char *path, int *nb_lines, size_t *len_line)
{
    int (fd), (i);
    char    *line;
    char    **ptr;

    ptr = NULL;
    i = 0;
    is_valid_path_ext(path);
    fd = open(path, O_RDONLY);
    *nb_lines = is_rectangular(fd, len_line);
    close(fd);
    ptr = malloc(sizeof(char *) * (*nb_lines + 1));
    if (!ptr)
        exit_with_error(ptr, "Error:!!!\n");
    fd = open(path, O_RDONLY);
    line = get_next_line(fd);
    while (line)
    {
        ptr[i] = line;
        line = get_next_line(fd);
        i++;
    }
    ptr[i] = NULL;
    close(fd);
    check_walls(ptr);
    return (check_map_characters(ptr, data), ptr);
    return (ptr);
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



// int press_key(int key, t_data *data)
// {
//     if (key == 65307)
//         close_window(data);
//     else if (key == 100 || key == 97 || key == 115 || key == 119)
//     {
//         if (key == 100)
//         {
//             if ((data->map[data->player_y][data->player_x + 1] != '1') && (data->map[data->player_y][data->player_x + 1] != 'E'))
//             {
//                 data->map[data->player_y][data->player_x] = '0';
//                 data->player_x += 1;
//                 if ((data->map[data->player_y][data->player_x] == 'E') && (data->c_ate == data->nb_collectibles))
//                     close_window(data);
//             }
//         }
//         else if (key == 97)
//         {
//             if ((data->map[data->player_y][data->player_x - 1] != '1') && (data->map[data->player_y][data->player_x - 1] != 'E'))
//             {
//                 data->map[data->player_y][data->player_x] = '0';
//                 data->player_x -= 1;
//                 if ((data->map[data->player_y][data->player_x] == 'E') && (data->c_ate == data->nb_collectibles))
//                     close_window(data);
//             }
//         }
//         else if (key == 115)
//         {
//             if ((data->map[data->player_y + 1][data->player_x] != '1') && (data->map[data->player_y + 1][data->player_x] != 'E'))
//             {
//                 data->map[data->player_y][data->player_x] = '0';
//                 data->player_y += 1;
//                 if ((data->map[data->player_y][data->player_x] == 'E') && (data->c_ate == data->nb_collectibles))
//                     close_window(data);
//             }
//         }
//         else if (key == 119)
//         {
//             if ((data->map[data->player_y - 1][data->player_x] != '1') && (data->map[data->player_y - 1][data->player_x] != 'E'))
//             {
//                 data->map[data->player_y][data->player_x] = '0';
//                 data->player_y -= 1;
//             }
//         }
//         if ((data->map[data->player_y][data->player_x] == 'E') && (data->c_ate == data->nb_collectibles))
//             close_window(data);
//         else
//             data->map[data->player_y][data->player_x] = '0';
//     }
//     else
//         return (0);
//     if (data->map[data->player_y][data->player_x] == 'C')
//     {
//         data->c_ate++;
//         printf("nb_collectibles_ate : %d\n", data->c_ate);
//     }
//     data->map[data->player_y][data->player_x] = 'P';
//     mlx_clear_window(data->mlx, data->win);
//     draw_map(data);
//     return (0);
// }




int press_key(int key, t_data *data)
{
    if (key == 65307)
        close_window(data);
    else if (key == 100 || key == 97 || key == 115 || key == 119)
    {
        if ((data->map[data->player_y][data->player_x + 1] == 'E') && (data->c_ate == data->nb_collectibles))
            close_window(data);
        else if ((data->map[data->player_y][data->player_x - 1] == 'E') && (data->c_ate == data->nb_collectibles))
            close_window(data);
        else if ((data->map[data->player_y + 1][data->player_x] == 'E') && (data->c_ate == data->nb_collectibles))
            close_window(data);
        else if ((data->map[data->player_y - 1][data->player_x] == 'E') && (data->c_ate == data->nb_collectibles))
            close_window(data);
        if (key == 100)
        {
            if (data->map[data->player_y][data->player_x + 1] != '1')
            {
                data->map[data->player_y][data->player_x] = '0';
                data->player_x += 1;
                data->nb_moves++;
                printf("nb_moves : %d\n", data->nb_moves);
            }
        }
        else if (key == 97)
        {
            if (data->map[data->player_y][data->player_x - 1] != '1')
            {
                data->map[data->player_y][data->player_x] = '0';
                data->player_x -= 1;
                data->nb_moves++;
                printf("nb_moves : %d\n", data->nb_moves);
            }
        }
        else if (key == 115)
        {
            if (data->map[data->player_y + 1][data->player_x] != '1')
            {
                data->map[data->player_y][data->player_x] = '0';
                data->player_y += 1;
                data->nb_moves++;
                printf("nb_moves : %d\n", data->nb_moves);
            }
        }
        else if (key == 119)
        {
            if (data->map[data->player_y - 1][data->player_x] != '1')
            {
                data->map[data->player_y][data->player_x] = '0';
                data->player_y -= 1;
                data->nb_moves++;
                printf("nb_moves : %d\n", data->nb_moves);
            }
        }
    }
    else
        return (0);
    if (data->map[data->player_y][data->player_x] == 'C')
        data->c_ate++;
    data->map[data->player_y][data->player_x] = 'P';
    mlx_clear_window(data->mlx, data->win);
    draw_map(data);
    return (0);
}




// int press_key(int key, t_data *data)
// {
//     if (key == 65307)
//         close_window(data);
//     else if (key == 100 || key == 97 || key == 115 || key == 119)
//     {
//         if (key == 100)
//         {
//             if (((data->map[data->player_y][data->player_x + 1] == 'C') || (data->map[data->player_y][data->player_x + 1] == '0') || ((data->map[data->player_y][data->player_x] == 'E') && (data->c_ate == data->nb_collectibles))))
//             {
//                 data->map[data->player_y][data->player_x] = '0';
//                 data->player_x += 1;
//             }
//         }
//         else if (key == 97)
//         {
//             if (((data->map[data->player_y][data->player_x - 1] == 'C') || (data->map[data->player_y][data->player_x - 1] == '0') || ((data->map[data->player_y][data->player_x] == 'E') && (data->c_ate == data->nb_collectibles))))
//             {
//                 data->map[data->player_y][data->player_x] = '0';
//                 data->player_x -= 1;
//             }
//         }
//         else if (key == 115)
//         {
//             if (((data->map[data->player_y + 1][data->player_x] == 'C') || (data->map[data->player_y + 1][data->player_x] == '0') || ((data->map[data->player_y][data->player_x] == 'E') && (data->c_ate == data->nb_collectibles))))
//             {
//                 data->map[data->player_y][data->player_x] = '0';
//                 data->player_y += 1;
//             }
//         }
//         else if (key == 119)
//         {
//             if (((data->map[data->player_y - 1][data->player_x] == 'C') || (data->map[data->player_y - 1][data->player_x] == '0') || ((data->map[data->player_y][data->player_x] == 'E') && (data->c_ate == data->nb_collectibles))))
//             {
//                 data->map[data->player_y][data->player_x] = '0';
//                 data->player_y -= 1;
//             }
//         }
//         if ((data->map[data->player_y][data->player_x] == 'E') && (data->c_ate == data->nb_collectibles))
//             close_window(data);
//     }
//     else
//         return (0);
//     if (data->map[data->player_y][data->player_x] == 'C')
//     {
//         data->c_ate++;
//         printf("nb_collectibles_ate : %d\n", data->c_ate);
//     }
//     data->map[data->player_y][data->player_x] = 'P';
//     mlx_clear_window(data->mlx, data->win);
//     draw_map(data);
//     return (0);
// }





111111111111111111111111
1P0000000000000000000001
100000000000000000000001
10CCC000CCCC0CCCC0CCCC01
10C0C000000C0000C0C00C01
1000C000CCCC0CCCC0000C01
1000C000000C0000C0000C01
10CCCCC0CCCC0CCCC0000C01
100000000000000000000001
1000000000000000000000E1
111111111111111111111111









111111111111111111111111
1P0000000000000000000001
100000000000000000000001
101110000111101111011101
101010000000100000100011
100011000111101111000011
100011000000100000000011
101111110111101111000011
100000000000000000000001
1000000000000000C00000E1
111111111111111111111111
















































































































// Function to load image from path
// void *load_image(void *mlx, char *path)
// {
//     void *img;
//     int img_width;
//     int img_height;

//     img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
//     if (!img)
//     {
//         perror("Error loading image");
//         exit(1);
//     }
//     return img;
// }

// // Function to draw map
// void draw_map(void *mlx, void *win, char **map, t_images images)
// {
//     int x, y;
//     int tile_size = 32;  // Size of each tile in pixels

//     y = 0;
//     while (map[y])
//     {
//         x = 0;
//         while (map[y][x])
//         {
//             if (map[y][x] == '1')  // Wall
//                 mlx_put_image_to_window(mlx, win, images.wall, x * tile_size, y * tile_size);
//             else if (map[y][x] == 'P')  // Player
//                 mlx_put_image_to_window(mlx, win, images.player, x * tile_size, y * tile_size);
//             else if (map[y][x] == 'C')  // Collectible
//                 mlx_put_image_to_window(mlx, win, images.collectible, x * tile_size, y * tile_size);
//             else if (map[y][x] == '0')  // Floor
//                 mlx_put_image_to_window(mlx, win, images.floor, x * tile_size, y * tile_size);
//             else if (map[y][x] == 'E')  // Exit
//                 mlx_put_image_to_window(mlx, win, images.exit, x * tile_size, y * tile_size);
//             x++;
//         }
//         y++;
//     }
// }

// int main(int argc, char **argv)
// {
//     void *mlx;
//     void *win;
//     char **map;
//     int len_window = 0;
//     size_t width_window = 0;

//     // Check if the map file path is provided
//     if (argc < 2)
//     {
//         write(2, "Error\n", 6);
//         exit(1);
//     }

//     map = handle_input(argv[1], &len_window, &width_window);

//     // Initialize MiniLibX
//     mlx = mlx_init();
//     if (!mlx)
//     {
//         perror("Error initializing MiniLibX");
//         return (0);
//     }

//     // Create a window
//     win = mlx_new_window(mlx, ((width_window) * 32), ((len_window) * 32), "so long");
//     // win = mlx_new_window(mlx, 800, 420, "so long");
//     if (!win)
//     {
//         perror("Error creating window");
//         return (0);
//     }
//     // Load images
//     t_images images;
//     images.wall = load_image(mlx, "/home/klamachi/Desktop/so_long/wall.xpm");
//     images.player = load_image(mlx, "/home/klamachi/Desktop/so_long/player.xpm");
//     images.collectible = load_image(mlx, "/home/klamachi/Desktop/so_long/collectible.xpm");
//     images.exit = load_image(mlx, "/home/klamachi/Desktop/so_long/exit.xpm");
//     images.floor = load_image(mlx, "/home/klamachi/Desktop/so_long/floor.xpm");

//     // Draw the map
//     draw_map(mlx, win, map, images);

//     // Start the MiniLibX event loop
//     mlx_loop(mlx);

//     return (0);
// }


// int main(int argc, char **argv)
// {
//     void    *mlx;
//     void    *win;
//     char    **map;
//     if (argc < 2)
//     {
//         write(2, "Error\n", 6);
//         exit(1);
//     }
//     map = handle_input(argv[1]);
//     mlx = mlx_init();
//     if (!mlx)
//     {
//         perror("Error initializing MiniLibX");
//         return (0);
//     }
//     win = mlx_new_window(mlx, 800, 600, "so long");
//     if (!win)
//     {
//         perror("Error creating window");
//         return (0);
//     }
//     mlx_loop(mlx);
//     return (0);
// }