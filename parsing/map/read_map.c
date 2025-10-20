/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:57:27 by mac               #+#    #+#             */
/*   Updated: 2025/10/20 20:59:59 by sbrochar         ###   ########.fr       */
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

char	*process_line(char *line, t_data *data)
{
	int	len;

	len = 0;
	if (!line)
		return (NULL);
	while (line[len] && line[len] != '\n')
		len++;
	if (len == 0)
	{
		free(line);
		return (NULL);
	}
	if (data->map_width == 0)
		data->map_width = len;
	data->map_height++;
	line[len] = '\0';
	return (line);
}

char	**alloc_map(char *filename, int height, int *fd)
{
	char	**map;

	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * (height + 1));
	return (map);
}

char	**read_map(char *filename, t_data *data)
{
	int		fd;
	char	**map;
	char	*line;
	int		i;

	i = 0;
	data->map_height = 0;
	data->map_width = 0;
	map = alloc_map(filename, count_height(filename), &fd);
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (line != NULL)
	{
		line = process_line(line, data);
		if (line)
			map[i++] = line;
	}
	close(fd);
	map[i] = NULL;
	return (map);
}
