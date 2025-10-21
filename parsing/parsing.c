/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:28:51 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/21 20:14:27 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	check_map_size(t_data *data)
{
	if (data->map_width > MAX_WIDTH || data->map_height > MAX_HEIGHT)
	{
		write(1, "The map is too big\n", 20);
		return (false);
	}
	return (true);
}

void	init_var_parse(t_data *data)
{
	data->player_x = -1;
	data->player_y = -1;
	data->player_count = 0;
	data->collectibles_found = 0;
	data->collectibles_total = 0;
	data->exit_found = false;
}

bool	parse_map(char **map, t_data *data)
{
	init_var_parse(data);
	if (!check_map_size(data))
		return (false);
	if (check_rectangle(map, data) == false)
		return (write(1, "The map is not rectangular !\n", 30), false);
	if (check_walls(map, data) == false)
	{
		write(1, "My cat is going to run away, put up a wall !\n", 46);
		return (false);
	}
	if (check_elements(map, data) == false)
		return (false);
	data->collectibles_total = count_collectibles(map, data->map_height);
	if (validate_path(map, data) == false)
		return (write(1, "I can't get through! Meow\n", 27), false);
	if (data->collectibles_found == 0)
		return (false);
	if (data->exit_found == false)
		return (false);
	return (true);
}
