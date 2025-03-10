/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamachi <klamachi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:26:58 by klamachi          #+#    #+#             */
/*   Updated: 2025/02/16 21:10:37 by klamachi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freee(char ***ptr)
{
	int	i;

	i = 0;
	if (!*ptr)
		return ;
	while ((*ptr)[i])
	{
		free((*ptr)[i]);
		i++;
	}
	free(*ptr);
	*ptr = NULL;
}

void	ft_free_img(void *mlx, t_images *img)
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

int	close_window(t_data *data)
{
	ft_freee(&(data->map));
	ft_free_img(data->mlx, &(data->img));
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}

void	free_gnl(char **reminder)
{
	if (reminder && *reminder)
	{
		free(*reminder);
		*reminder = NULL;
	}
}

void	free_line(char *line, const char *msg, char **reminder)
{
	if (line)
		free(line);
	perror(msg);
	free_gnl(reminder);
	exit(1);
}
