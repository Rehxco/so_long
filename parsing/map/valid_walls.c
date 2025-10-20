/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:00:09 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/20 14:52:17 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

bool	check_w_top(char **map)
{
	int	i;

	i = 0;
	while (map[0][i - 1])
	{
		if (map[0][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	check_w_bot(char **map, int height)
{
	int	i;

	i = 0;
	while (map[height - 1][i])
	{
		if (map[height - 1][i] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	check_walls(char **map, t_data *data)
{
	int		j;
	size_t	len;

	if (check_w_top(map) == false)
		return (false);
	if (check_w_bot(map, data->map_height) == false)
		return (false);
	j = 1;
	while (j != (data->map_height - 1))
	{
		len = len_with_or_not_n(map[j]);
		if (map[j][0] != '1' || map[j][len - 1] != '1')
			return (false);
		j++;
	}
	return (true);
}
