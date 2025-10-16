/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:20:00 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/16 22:01:38 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
	{
		write(1, "Erreur: nombre d'arguments incorrect\n", 36);
		return (1);
	}
	if (!valid_extension(av[1]))
	{
		write(1, "Erreur: extension du fichier doit être .ber\n", 44);
		return (1);
	}
	data.mlx = NULL;
	data.win = NULL;
	data.img_wall = NULL;
	data.img_floor = NULL;
	data.img_player = NULL;
	data.img_collectible = NULL;
	data.img_exit = NULL;
	data.collectibles_found = 0;
	data.player_count = 0;
	data.moves_count = 0;
	data.exit_found = false;
	data.player_x = 0;
	data.player_y = 0;
	data.map = read_map(av[1], &data);
	if (!data.map)
	{
		write(1, "Erreur: impossible de lire la map\n", 34);
		return (1);
	}
	init_player_and_collectibles(&data);
	printf("Map chargée: height=%d, width=%d\n", data.map_height,
		data.map_width);
	printf("Map pointer: %p, height=%d, width=%d\n", data.map, data.map_height,
		data.map_width);
	if (data.map)
		printf("Première ligne: %s\n", data.map[0]);
	if (!init_mlx(&data))
	{
		write(1, "Erreur: impossible d'initialiser MLX\n", 37);
		return (1);
	}
	if (!load_images(&data))
	{
		write(1, "Erreur: impossible de charger les images\n", 40);
		exit_game(&data);
	}
	printf("MLX pointer: %p, img_width=%d, img_height=%d\n", data.mlx,
		data.img_width, data.img_height);
	draw_map(&data);
	mlx_hook(data.win, 2, 1L << 0, handle_key, &data);
	mlx_hook(data.win, 17, 0L, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
