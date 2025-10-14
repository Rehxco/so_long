/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:20:00 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/14 17:22:50 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if(!mlx)
		return(0);
	win = mlx_new_window(mlx, 800, 600, "Hello MLX!");
	mlx_loop(mlx);
	return (0);
}
