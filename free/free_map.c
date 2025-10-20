/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 22:05:28 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/20 20:57:51 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char **map, int height)
{
	int	j;

	if (!map)
		return ;
	j = 0;
	while (j < height)
	{
		if (map[j])
			free(map[j]);
		j++;
	}
	free(map);
}
