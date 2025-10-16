/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 14:30:53 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/16 23:39:04 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_to_free_pos(t_data *data, int new_x, int new_y)
{
	if (data->map[new_y][new_x] != 'E')
		data->map[new_y][new_x] = 'P';
	if (data->map[data->player_y][data->player_x] != 'E')
		data->map[data->player_y][data->player_x] = '0';
	data->player_x = new_x;
	data->player_y = new_y;
	data->moves_count++;
	draw_map(data);
	printf("Moves: %d\n", data->moves_count);
}

bool	is_in_bounds(t_data *data, int x, int y)
{
	if (x < 0 || x >= data->map_width)
		return (false);
	if (y < 0 || y >= data->map_height)
		return (false);
	return (true);
}

void	try_move(t_data *data, int new_x, int new_y, char c)
{
	if (c == '0' || c == 'P')
		move_to_free_pos(data, new_x, new_y);
	else if (c == 'C')
	{
		data->collectibles_found++;
		move_to_free_pos(data, new_x, new_y);
	}
	else if (c == 'E')
	{
		if (data->collectibles_found == data->collectibles_total)
			exit_game(data);
		else
			move_to_free_pos(data, new_x, new_y);
	}
}

int	move_player(t_data *data, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	c;

	new_x = data->player_x + dx;
	new_y = data->player_y + dy;
	if (!is_in_bounds(data, new_x, new_y))
		return (0);
	c = data->map[new_y][new_x];
	try_move(data, new_x, new_y, c);
	return (0);
}

int	handle_key(int keycode, t_data *data)
{
	int	dx;
	int	dy;

	printf("keycode = %d\n", keycode);
	if (keycode == 65307)
		exit_game(data);
	else
	{
		dx = 0;
		dy = 0;
		if (keycode == 119)
			dy = dy - 1;
		else if (keycode == 115)
			dy = dy + 1;
		else if (keycode == 100)
			dx = dx + 1;
		else if (keycode == 97)
			dx = dx - 1;
		printf("Key pressed: %d, dx=%d, dy=%d\n", keycode, dx, dy);
		move_player(data, dx, dy);
	}
	return (0);
}
