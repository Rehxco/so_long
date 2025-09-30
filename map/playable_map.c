/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playable_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:54:32 by sbrochar          #+#    #+#             */
/*   Updated: 2025/09/30 20:31:52 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	*player_position(char **map, int height)
{
	int	i;
	int	j;
	int	*tab;

	i = 0;
	j = 0;
	tab = malloc(2 * sizeof(int));
	if (!tab)
		return (NULL);
	while (j < height)
	{
		while (map[j][i])
		{
			if (map[j][i] == 'P')
			{
				tab[0] = j;
				tab[1] = i;
				return (tab);
			}
			i++;
		}
		i = 0;
		j++;
	}
}

char	**copy_map(char **map, int height)
{
	char	**tmp;
	int		j;

	j = 0;
	tmp = malloc(height * sizeof(char *));
	if (!tmp)
		return (NULL);
	while (j < height)
	{
		tmp[j] = ft_strdup(map[j]);
		if (!tmp[j])
		{
			while (j > 0)
			{
				free(tmp[j - 1]);
				j--;
			}
			free(tmp);
			return (NULL);
		}
		j++;
	}
	return (tmp);
}
void	explore(char **map_copy, int y, int x, t_data *data)
{
}