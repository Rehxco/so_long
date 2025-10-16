/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:57:27 by mac               #+#    #+#             */
/*   Updated: 2025/10/16 23:31:22 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	count_height(char *filename)
{
	char	*str;
	int		i;
	int		fd;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	str = get_next_line(fd);
	while (str != NULL)
	{
		free(str);
		i++;
		str = get_next_line(fd);
	}
	close(fd);
	return (i);
}
void	init_player_and_collectibles(t_data *data)
{
	int	y;
	int	x;

	data->collectibles_total = 0;
	data->player_x = -1;
	data->player_y = -1;
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
			{
				data->collectibles_total++;
			}
			x++;
		}
		y++;
	}
	if (data->player_x == -1 || data->player_y == -1)
	{
		write(1, "Erreur: joueur non trouvé sur la map\n", 37);
		exit(1);
	}
}

char	**read_map(char *filename, t_data *data)
{
	int		fd;
	char	**map;
	int		i;
	char	*str;

	i = 0;
	data->map_height = count_height(filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * (data->map_height + 1));
	if (!map)
		return (NULL);
	str = get_next_line(fd);
	while (str != NULL)
	{
		map[i] = str;
		i++;
		str = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	data->map_width = len_with_or_not_n(map[0]);
	return (map);
}
