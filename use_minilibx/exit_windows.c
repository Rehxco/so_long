/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:34:12 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/21 20:39:13 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_game(t_data *data)
{
	if (data->img_collectible)
		mlx_destroy_image(data->mlx, data->img_collectible);
	if (data->img_exit)
		mlx_destroy_image(data->mlx, data->img_exit);
	if (data->img_floor)
		mlx_destroy_image(data->mlx, data->img_floor);
	if (data->img_wall)
		mlx_destroy_image(data->mlx, data->img_wall);
	if (data->img_collectible)
		mlx_destroy_image(data->mlx, data->img_player);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_map(data->map, data->map_height);
	exit(0);
}

int	close_window(t_data *data)
{
	exit_game(data);
	return (0);
}

void	error_message(const char *error_message)
{
	write(1, error_message, ft_strlen(error_message));
	write(1, "\n", 1);
	exit(1);
}
