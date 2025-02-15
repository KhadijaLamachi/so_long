/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:48:14 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/15 22:40:26 by klamachi         ###   ########.fr       */
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
}
