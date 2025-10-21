/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:20:00 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/21 20:47:06 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	init_for_main(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img_wall = NULL;
	data->img_floor = NULL;
	data->img_player = NULL;
	data->img_collectible = NULL;
	data->img_exit = NULL;
	data->collectibles_found = 0;
	data->player_count = 0;
	data->moves_count = 0;
	data->exit_found = false;
	data->player_x = 0;
	data->player_y = 0;
	data->map_width = 0;
	data->map_height = 0;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (write(1, "Wrong number of arguments\n", 27), 1);
	if (!valid_extension(av[1]))
		return (write(1, "The map must have a .ber extension\n", 36), 1);
	init_for_main(&data);
	data.map = read_map(av[1], &data);
	if (!data.map)
		return (write(1, "The map cannot be read\n", 24), 1);
	if (!parse_map(data.map, &data))
		return (free_map(data.map, data.map_height), 1);
	init_player_and_collectibles(&data);
	if (!init_mlx(&data))
	{
		write(1, "Unable to initialize MLX\n", 26);
		free_map(data.map, data.map_height);
		exit_game(&data);
		return (1);
	}
	draw_map(&data);
	mlx_hook(data.win, 2, 1L << 0, handle_key, &data);
	mlx_hook(data.win, 17, 0L, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
