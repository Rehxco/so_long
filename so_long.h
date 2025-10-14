/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbrochar <sbrochar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:31:24 by sbrochar          #+#    #+#             */
/*   Updated: 2025/10/08 15:50:45 by sbrochar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int		map_height;
	int		map_width;
	int		collectibles_total;
	int		collectibles_found;
	bool	exit_found;
	char	**map;
	int		player_x;
	int		player_y;
	int		player_count;
	int		moves;
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
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
bool		check_rectangle(char **map, int height);
void		free_map(char **map, int height);
int			*player_position(char **map, int height);
char		**copy_map(char **map, int height);
void		explore(char **map_copy, int y, int x, t_data *data);
bool		validate_path(char **map, t_data *data);
bool		valid_count_p(char **map, int height);
bool		valid_count_c(char **map, int height);
bool		valid_count_e(char **map, int height);
bool		check_elements(char **map, t_data *data);
bool		check_w_top(char **map);
bool		check_w_bot(char **map, int height);
bool		check_walls(char **map, t_data *data);
bool		parse_map(char **map, t_data *data);
void		store_map_info(char c, t_data *data, int x, int y);
;

#endif