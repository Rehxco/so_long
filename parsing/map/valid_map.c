/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 12:11:08 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/02 15:32:08 by sbrochar         ###   ########.fr       */
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

