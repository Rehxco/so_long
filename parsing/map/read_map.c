/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:57:27 by mac               #+#    #+#             */
/*   Updated: 2025/10/08 14:44:50 by sbrochar         ###   ########.fr       */
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
