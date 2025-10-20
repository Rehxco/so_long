/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:34:12 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/20 19:31:00 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	exit_game(t_data *data)
{
	printf(">>> exit_game()\n");
	mlx_destroy_window(data->mlx, data->win);
	free_map(data->map, data->map_height);
	exit(0);
}

int	close_window(t_data *data)
{
	exit_game(data);
	return (0);
}


void error_exit(const char *error_message)
{
    write(1, error_message, ft_strlen(error_message));
    write(1, "\n", 1);
    exit(1);
}
