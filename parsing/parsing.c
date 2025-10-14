/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 22:28:51 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/08 14:45:11 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

bool	parse_map(char **map, t_data *data)
{
	if (check_rectangle(map, data) == false)
		return (false);
	if (check_walls(map, data) == false)
		return (false);
	if (check_elements(map, data) == false)
		return (false);
	if (validate_path(map, data) == false)
		return (false);
	if (data->collectibles_found == 0)
		return (false);
	if (data->exit_found == false)
		return (false);
	return (true);
}
