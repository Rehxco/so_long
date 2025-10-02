/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:24:02 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/02 15:33:25 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool	valid_count_p(char **map, int height)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (j < height)
	{
		while (map[j][i])
		{
			if (map[j][i] == 'P')
				count++;
			i++;
		}
		i = 0;
		j++;
	}
	if (count != 1)
		return (false);
	return (true);
}

bool	valid_count_e(char **map, int height)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (j < height)
	{
		while (map[j][i])
		{
			if (map[j][i] == 'E')
				count++;
			i++;
		}
		i = 0;
		j++;
	}
	if (count != 1)
		return (false);
	return (true);
}

bool	valid_count_c(char **map, int height)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (j < height)
	{
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				count++;
			i++;
		}
		i = 0;
		j++;
	}
	if (count == 0)
		return (false);
	return (true);
}

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
			i++;
		}
		i = 0;
		j++;
	}
	if (valid_count_c(map, data->map_height) == false)
		return (false);
	if (valid_count_p(map, data->map_height) == false)
		return (false);
	if (valid_count_e(map, data->map_height) == false)
		return (false);
	return (true);
}
