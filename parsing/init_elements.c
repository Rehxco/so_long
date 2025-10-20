/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 19:13:58 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/20 21:51:20 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	scan_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
			}
			else if (data->map[y][x] == 'C')
				data->collectibles_total++;
			else if (data->map[y][x] == 'E')
				data->exit_count++;
			x++;
		}
		y++;
	}
}

void	init_player_and_collectibles(t_data *data)
{
	data->collectibles_total = 0;
	data->collectibles_found = 0;
	data->exit_count = 0;
	data->player_x = -1;
	data->player_y = -1;
	scan_map(data);
	if (data->player_x == -1 || data->player_y == -1)
		error_message("Player not found");
	if (data->exit_count != 1)
		error_message("There must be exactly one exit");
	if (data->collectibles_total < 1)
		error_message("You need at least one collectible");
}
