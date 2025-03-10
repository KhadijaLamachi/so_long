/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:48:14 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/17 22:12:15 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "so_long.h"
#include <stdio.h>

void	is_valid_path_ext(char *path)
{
	int		fd;
	char	*ext;

	ext = ft_strrchr(path, '.');
	if (!ext || ft_strcmp(ext, ".ber"))
	{
		perror("Error\nInvalid file extension\n");
		exit(1);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\nopening file problem!!!\n");
		exit(1);
	}
	close(fd);
}

int	is_rectangular(int fd, size_t *len_line)
{
	char		*line;
	int			nb_lines;
	static char	*reminder;

	nb_lines = 0;
	line = get_next_line(fd, &reminder);
	if (!line)
		free_line(NULL, "Error\nMap is empty!!!\n", &reminder);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	*len_line = ft_strlen(line);
	while (line)
	{
		if (ft_strlen(line) && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (ft_strlen(line) != *len_line)
			free_line(line, "Error\nOh sorry, the map is not rectangular!!\n",
				&reminder);
		nb_lines++;
		free(line);
		line = get_next_line(fd, &reminder);
	}
	return (nb_lines);
}

void	exit_with_error(char **map, const char *msg)
{
	int	i;

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

char	**handle_input(t_data *data, char *path, int *nbLines, size_t *lenLine)
{
	char		*line;
	char		**map;
	static char	*reminder;

	int (fd), (i);
	map = NULL;
	i = 0;
	is_valid_path_ext(path);
	fd = open(path, O_RDONLY);
	*nbLines = is_rectangular(fd, lenLine);
	close(fd);
	map = malloc(sizeof(char *) * (*nbLines + 1));
	if (!map)
		exit_with_error(map, "Error\nMemory allocation failed.\n");
	fd = open(path, O_RDONLY);
	line = get_next_line(fd, &reminder);
	while (line)
	{
		map[i++] = line;
		line = get_next_line(fd, &reminder);
	}
	map[i] = NULL;
	close(fd);
	return (check_walls(map), check_map_characters(map, data),
		free_gnl(&reminder), map);
}
