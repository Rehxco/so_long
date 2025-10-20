/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 22:05:28 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/20 18:23:53 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void	free_map(char **map, int height)
{
	int	j;

	if (!map)
		return ;
	for (j = 0; j < height; j++)
	{
		if (map[j])
		{
			free(map[j]);
		}
	}
	free(map);
}
