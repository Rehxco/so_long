/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:28:51 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/22 20:19:32 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	check_map_size(t_data *data)
{
	if (data->map_width > MAX_WIDTH || data->map_height > MAX_HEIGHT)
	{
		write(1, "The map is too big\n", 20);
		return (false);
	}
	return (true);
}

bool	verif_map_with_emptiness(char *filename)
{
	size_t	first_len;
	size_t	len;
	int		fd;
	char	*tmp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	tmp = get_next_line(fd);
	if (!tmp)
		return (close(fd), false);
	first_len = len_with_or_not_n(tmp);
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(fd);
		if (!tmp)
			return (close(fd), true);
		len = len_with_or_not_n(tmp);
		if (len != first_len)
			return (get_next_line(-42), free(tmp), close(fd), false);
	}
	return (free(tmp), get_next_line(-42), close(fd), true);
}

void	init_var_parse(t_data *data)
{
	data->player_x = -1;
	data->player_y = -1;
	data->player_count = 0;
	data->collectibles_found = 0;
	data->collectibles_total = 0;
	data->exit_found = false;
}

bool	parse_map(char **map, t_data *data)
{
	init_var_parse(data);
	if (!check_map_size(data))
		return (false);
	if (check_rectangle(map, data) == false)
		return (write(1, "The map is not rectangular !\n", 30), false);
	if (check_walls(map, data) == false)
	{
		write(1, "My cat is going to run away, put up a wall !\n", 46);
		return (false);
	}
	if (check_elements(map, data) == false)
		return (false);
	data->collectibles_total = count_collectibles(map, data->map_height);
	if (validate_path(map, data) == false)
		return (write(1, "I can't get through! Meow\n", 27), false);
	if (data->collectibles_found == 0)
		return (false);
	if (data->exit_found == false)
		return (false);
	return (true);
}
