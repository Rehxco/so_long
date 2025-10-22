/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 14:57:27 by mac               #+#    #+#             */
/*   Updated: 2025/10/22 18:04:10 by sbrochar         ###   ########.fr       */
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

char	**alloc_map(int height, int *fd, char *file)
{
	char	**map;

	*fd = open(file, O_RDONLY);
	if (*fd < 0)
		return (NULL);
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		close(*fd);
	return (map);
}

char	*process_line(char *line, t_data *data)
{
	int		len;
	char	*new_line;

	if (!line)
		return (NULL);
	len = 0;
	while (line[len] && line[len] != '\n')
		len++;
	if (len == 0)
	{
		free(line);
		return (NULL);
	}
	new_line = ft_substr(line, 0, len);
	if (data->map_width == 0)
		data->map_width = len;
	data->map_height++;
	free(line);
	return (new_line);
}

char	**read_map(char *file, t_data *data)
{
	int		fd;
	int		i;
	int		height;
	char	**map;
	char	*line;

	i = 0;
	height = count_height(file);
	if (height <= 0)
		return (NULL);
	map = alloc_map(height, &fd, file);
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		line = process_line(line, data);
		if (line)
			map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
