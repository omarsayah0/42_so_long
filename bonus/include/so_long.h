/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 16:58:25 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/20 16:42:10 by oaletham         ###   ########.fr       */
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
# define PLAYER_FRAMES 4
# define PLAYER_DIRECTIONS 4
# define PLAYER_ANIM_DELAY 8000
# define DIR_DOWN 0
# define DIR_LEFT 1
# define DIR_RIGHT 2
# define DIR_UP 3
# define T 40
# define ENEMY_DIRECTIONS 2
# define ENEMY_DIR_UP     0
# define ENEMY_DIR_DOWN   1

# include <unistd.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include <sys/time.h>
# include "get_next_line.h"
# include "ft_printf.h"
# include <mlx.h>

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

typedef struct s_anim
{
	t_img	frames[PLAYER_DIRECTIONS][PLAYER_FRAMES];
	int		frame_counts[PLAYER_DIRECTIONS];
	int		current_dir;
	int		current;
	int		tick;
	int		delay;
	int		playing;
	int		frames_left;
}	t_anim;

typedef struct s_enemy
{
	int	row;
	int	col;
	int	dir;
	int	steps;
	int	max_steps;
}	t_enemy;

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
	t_anim		player_anim;
	t_img		c;
	t_img		exit_closed;
	t_img		exit_open_i;
	t_mapinfo	*map;
	int			last_key;
	int			key_down;
	long		last_move_time;
	t_enemy		*enemies;
	int			enemy_count;
	t_img		enemy_img;
	long		last_anim_time;
}	t_game;

void		*ft_memset(void *s, int c, int n);
void		put_things(t_game *g, t_mapinfo *map);
void		put_floor(t_game *w);
int			enemy_patrol(t_game *g);
int			enemy_from_map(t_game *g);
char		*ft_itoa(int n);
int			get_key(int key, t_game *game);
long		current_time_ms(void);
void		start_player_anim_cycle(t_game *g);
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
int			open_window(t_game *gc);
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
int			player_animation_loop(void *parm);
int			set_player_anim_dir(t_game *g, int dir);
void		reset_player_anim(t_game *g);
void		destroy_player_anim(t_game *g);
int			do_player_anim(t_game *g);
char		**cpy_map(char **map, int h, int w);
#endif
