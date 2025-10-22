/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 22:05:28 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/22 15:21:46 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char **map, int height)
{
	int	i;

	if (!*map)
		return ;
	i = 0;
	while (i < height)
	{
		if (map[i])
			free(map[i]);
		map[i] = NULL;
		i++;
	}
	if (map)
		free(map);
}
