/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:24:02 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/20 21:57:48 by sbrochar         ###   ########.fr       */
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
				return (false);
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
		write(1, "You forgot to put Teemo :(\n", 28);
		return (false);
	}
	if (data->collectibles_found < 1)
	{
		write(1, "I think there's a mushroom missing here\n", 41);
		return (false);
	}
	if (!data->exit_found)
	{
		write(1, "Where did I put the cage, in the closet?\n", 42);
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
