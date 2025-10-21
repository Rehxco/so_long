/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:24:02 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/21 21:03:27 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool	scan_map_elements(char **map, t_data *data)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (map[y][x])
		{
			c = map[y][x];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P'
				&& c != '\n' && c != '\r')
			{
				write(1, "What are you doing, buddy? Make an effort.\n", 43);
				return (false);
			}
			store_map_info(c, data, x, y);
			x++;
		}
		y++;
	}
	return (true);
}

bool	check_elements(char **map, t_data *data)
{
	if (!scan_map_elements(map, data))
		return (false);
	if (data->player_count != 1)
	{
		write(1, "Wrong number of Teemo, sorry:(\n", 32);
		return (false);
	}
	if (data->collectibles_found < 1)
	{
		write(1, "I think there's a mushroom missing here\n", 41);
		return (false);
	}
	if (!data->exit_found)
	{
		write(1, "Where did I put the pet carrier, in the closet?\n", 49);
		return (false);
	}
	return (true);
}

void	store_map_info(char c, t_data *data, int x, int y)
{
	if (c == 'C')
		data->collectibles_found++;
	if (c == 'E')
		data->exit_found = true;
	if (c == 'P')
	{
		data->player_x = x;
		data->player_y = y;
		data->player_count++;
	}
}
