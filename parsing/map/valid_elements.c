/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:24:02 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/08 16:14:59 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool	check_elements(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < data->map_height)
	{
		while (map[j][i])
		{
			if ((map[j][i] != '1') && (map[j][i] != '0') && (map[j][i] != 'C')
				&& (map[j][i] != 'E') && (map[j][i] != 'P'))
				return (false);
			store_map_info(map[j][i], data, i, j);
			i++;
		}
		i = 0;
		j++;
	}
	if (data->player_count != 1)
		return (false);
	if (data->collectibles_found < 1)
		return (false);
	if (data->exit_found == false)
		return (false);
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
