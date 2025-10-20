/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:11:08 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/20 21:09:27 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

size_t	len_with_or_not_n(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len > 0 && (str[len - 1] == '\n'))
		return (len - 1);
	else
		return (len);
}

bool	check_rectangle(char **map, t_data *data)
{
	size_t	first_len;
	size_t	len;
	int		i;

	i = 0;
	if (data->map_height == 0)
		return (false);
	first_len = len_with_or_not_n(map[i]);
	while (i < (data->map_height))
	{
		len = len_with_or_not_n(map[i]);
		if (first_len != len)
			return (false);
		i++;
	}
	return (true);
}

bool	valid_extension(char *filename)
{
	int	len;

	if (!filename)
		return (false);
	len = ft_strlen(filename);
	if (len < 4)
		return (false);
	if (filename[len - 4] == '.' && filename[len - 3] == 'b' && filename[len
			- 2] == 'e' && filename[len - 1] == 'r')
		return (true);
	return (false);
}
