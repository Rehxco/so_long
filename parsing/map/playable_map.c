/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:54:32 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/02 15:34:23 by sbrochar         ###   ########.fr       */
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
}

char	**copy_map(char **map, int map_height)
{
	char	**tmp;
	int		j;

	j = 0;
	tmp = malloc(map_height * sizeof(char *));
	if (!tmp)
		return (NULL);
	while (j < map_height)
	{
		tmp[j] = ft_strdup(map[j]);
		if (!tmp[j])
		{
			while (j > 0)
			{
				free(tmp[j - 1]);
				j--;
			}
			free(tmp);
			return (NULL);
		}
		j++;
	}
	return (tmp);
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
	char	**tmp;
	int		*position;
	int		j;

	j = 0;
	tmp = copy_map(map, data->map_height);
	data->collectibles_found = 0;
	data->exit_found = false;
	position = player_position(map, data->map_height);
	explore(tmp, position[0], position[1], data);
	free(position);
	free_map(tmp, data->map_height);
	free(tmp);
	if (data->exit_found == true
		&& data->collectibles_found == data->collectibles_total)
		return (true);
	else
		return (false);
}
