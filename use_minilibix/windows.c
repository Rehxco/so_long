/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 21:07:21 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/14 23:19:38 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	init_mlx(t_data *data)
{
	data->img_wall = NULL;
	data->img_player = NULL;
	data->img_exit = NULL;
	data->img_collectible = NULL;
	data->img_floor = NULL;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (false);
	data->win = mlx_new_window(data->mlx, data->map_width * data->img_width,
			data->map_height * data->img_height, "so_long");
	if (!data->win)
		return (false);
	return (true);
}
bool	load_images(t_data *data)
{
	data->img_wall = mlx_xpm_file_to_image(data->mlx, "textures/wall.xpm",
			&data->img_width, &data->img_height);
	if (!data->img_wall)
		return (false);
	data->img_floor = mlx_xpm_file_to_image(data->mlx, "textures/floor.xpm",
			&data->img_width, &data->img_height);
	if (!data->img_floor)
		return (false);
	data->img_player = mlx_xpm_file_to_image(data->mlx, "textures/greycat.xpm",
			&data->img_width, &data->img_height);
	if (!data->img_player)
		return (false);
	data->img_collectible = mlx_xpm_file_to_image(data->mlx,
			"textures/mushroom.xpm", &data->img_width, &data->img_height);
	if (!data->img_collectible)
		return (false);
	data->img_exit = mlx_xpm_file_to_image(data->mlx, "textures/exit.xpm",
			&data->img_width, &data->img_height);
	if (!data->img_exit)
		return (false);
	return (true);
}
