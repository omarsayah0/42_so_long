/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 16:58:25 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/20 17:12:48 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define K_ESC 65307
# define K_W   119
# define K_A   97
# define K_S   115
# define K_D   100
# define KEY_UP		65362
# define KEY_LEFT	65361
# define KEY_RIGHT	65363
# define KEY_DOWN	65364

# define T 40

# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct s_img
{
	void	*img;
	int		w;
	int		h;
}	t_img;

typedef struct s_mapinfo
{
	char	**map;
	int		height;
	int		width;
	int		player_row;
	int		player_col;
}	t_mapinfo;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			map_w;
	int			map_h;
	int			moves;
	int			c_left;
	int			exit_open;
	int			exit_found;
	t_img		floor;
	t_img		w;
	t_img		player;
	t_img		c;
	t_img		exit_closed;
	t_img		exit_open_i;
	t_mapinfo	*map;
}	t_game;

void		*ft_memset(void *s, int c, int n);
int			line_effective_len(char *s);
int			no_map(char *filename);
int			open_map_file(char *filename);
void		map_dim(char *filename, int *out_height, int *out_width);
char		**read_map(char *filename, int h, int w);
int			check_allowd_chars(char **map, int h, int w);
int			check_counts(char **map, int h, int w);
int			check_rectangle(char **map, int h, int w);
int			check_walls(char **map, int h, int w);
int			check_path(char **map, int h, int w);
int			count_collectibles(t_mapinfo *the_map);
int			get_key(int key, t_game *game);
int			get_key(int key, t_game *game);
int			destroy(t_game *g);
int			move_player(t_game *g, int *dr, int *dc);
int			ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, int n);
int			find_player_and_clear(t_mapinfo *m);
void		*ft_memcpy(void *dest, const void *src, int n);
void		render_all(t_game *gc);
void		put_floor(t_game *w);
void		put_things(t_game *g, t_mapinfo *map);
char		**cpy_map(char **map, int h, int w);
int			open_window(t_game *gc);
#endif
