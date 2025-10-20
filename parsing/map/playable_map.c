/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:54:32 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/20 21:07:57 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	*player_position(char **map, int map_height)
{
	int	i;
	int	j;
	int	*tab;

	i = 0;
	j = 0;
	tab = malloc(2 * sizeof(int));
	if (!tab)
		return (NULL);
	while (j < map_height)
	{
		while (map[j][i])
		{
			if (map[j][i] == 'P')
			{
				tab[0] = j;
				tab[1] = i;
				return (tab);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (NULL);
}

char	**copy_map(char **map, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	copy[height] = NULL;
	return (copy);
}

void	explore(char **map_copy, int y, int x, t_data *data)
{
	if (x < 0 || x >= data->map_width || y < 0 || y >= data->map_height)
		return ;
	if (map_copy[y][x] == '1')
		return ;
	if (map_copy[y][x] == 'X')
		return ;
	if (map_copy[y][x] == 'C')
		data->collectibles_found = data->collectibles_found + 1;
	if (map_copy[y][x] == 'E')
		data->exit_found = true;
	map_copy[y][x] = 'X';
	explore(map_copy, y - 1, x, data);
	explore(map_copy, y + 1, x, data);
	explore(map_copy, y, x - 1, data);
	explore(map_copy, y, x + 1, data);
}

bool	validate_path(char **map, t_data *data)
{
	char	**map_copy;
	bool	valid;

	data->collectibles_found = 0;
	data->exit_found = false;
	map_copy = copy_map(map, data->map_height);
	if (!map_copy)
		return (false);
	explore(map_copy, data->player_y, data->player_x, data);
	valid = (data->collectibles_found == data->collectibles_total
			&& data->exit_found);
	free_map(map_copy, data->map_height);
	return (valid);
}

int	count_collectibles(char **map, int map_height)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (y < map_height)
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
