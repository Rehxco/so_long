/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:31:24 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/16 23:42:43 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int		map_height;
	int		map_width;
	char	**map;

	int		collectibles_total;
	int		collectibles_found;
	bool	exit_found;
	int		player_x;
	int		player_y;
	int		player_count;

	void	*mlx;
	void	*win;

	void	*img_wall;
	void	*img_floor;
	void	*img_collectible;
	void	*img_exit;
	void	*img_player;
	int		img_width;
	int		img_height;

	int		moves_count;

}			t_data;

char		*get_next_line(int fd);
char		*ft_strjoin(char const *str1, char const *str2);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *src);
char		*ft_substr(char const *str, unsigned int start, size_t len);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
void		all_free(char **ptr);
int			count_height(char *filename);
char		**read_map(char *filename, t_data *data);
size_t		len_with_or_not_n(char *str);
bool		check_rectangle(char **map, t_data *data);
void		free_map(char **map, int height);
int			*player_position(char **map, int height);
char		**copy_map(char **map, int height);
void		explore(char **map_copy, int y, int x, t_data *data);
bool		validate_path(char **map, t_data *data);
bool		check_elements(char **map, t_data *data);
bool		check_w_top(char **map);
bool		check_w_bot(char **map, int height);
bool		check_walls(char **map, t_data *data);
bool		parse_map(char **map, t_data *data);
void		store_map_info(char c, t_data *data, int x, int y);
bool		init_mlx(t_data *data);
bool		load_images(t_data *data);
void		draw_map(t_data *data);
void		put_image(t_data *data, char c, int x, int y);
bool		valid_extension(char *filename);
void		init_player_and_collectibles(t_data *data);
int			handle_key(int keycode, t_data *data);
int			move_player(t_data *data, int dx, int dy);
void		move_to_free_pos(t_data *data, int new_pos_x, int new_pos_y);
void		exit_game(t_data *data);
int			close_window(t_data *data);
void		try_move(t_data *data, int new_x, int new_y, char c);
void		draw_cell(t_data *data, int x, int y);

#endif