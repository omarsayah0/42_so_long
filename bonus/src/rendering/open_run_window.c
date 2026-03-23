/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_run_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:09:47 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/20 16:43:50 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	load_static_images(t_game *gc)
{
	gc->floor.img = mlx_xpm_file_to_image(gc->mlx,
			"textures/floor.xpm", &gc->floor.w, &gc->floor.h);
	if (!gc->floor.img)
		return (0);
	gc->w.img = mlx_xpm_file_to_image(gc->mlx,
			"textures/wall.xpm", &gc->w.w, &gc->w.h);
	if (!gc->w.img)
		return (0);
	gc->c.img = mlx_xpm_file_to_image(gc->mlx,
			"textures/collect.xpm", &gc->c.w, &gc->c.h);
	if (!gc->c.img)
		return (0);
	gc->exit_closed.img = mlx_xpm_file_to_image(gc->mlx,
			"textures/exit_close.xpm", &gc->exit_closed.w, &gc->exit_closed.h);
	if (!gc->exit_closed.img)
		return (0);
	gc->exit_open_i.img = mlx_xpm_file_to_image(gc->mlx,
			"textures/exit_open.xpm", &gc->exit_open_i.w, &gc->exit_open_i.h);
	if (!gc->exit_open_i.img)
		return (0);
	gc->enemy_img.img = mlx_xpm_file_to_image(gc->mlx,
			"textures/enemy.xpm", &gc->enemy_img.w, &gc->enemy_img.h);
	if (!gc->enemy_img.img)
		return (0);
	return (1);
}

static int	load_components(t_game *gc)
{
	if (!load_static_images(gc))
		return (0);
	if (!do_player_anim(gc))
		return (0);
	return (1);
}

static int	key_release(int key, t_game *game)
{
	(void)key;
	game->key_down = 0;
	game->last_move_time = 0;
	return (0);
}

static int	hold_key(t_game *game)
{
	long	now;
	int		i;

	now = current_time_ms();
	i = 0;
	if (game->enemy_count > 0 && game->enemies)
	{
		while (i < game->enemy_count)
		{
			if (game->enemies[i].row == game->map->player_row
				&& game->enemies[i].col == game->map->player_col)
				return (destroy(game));
			i++;
		}
	}
	if (game->key_down && now - game->last_move_time >= 150)
	{
		get_key(game->last_key, game);
		game->last_move_time = now;
	}
	if (enemy_patrol(game))
		render_all(game);
	player_animation_loop(game);
	return (0);
}

int	open_window(t_game *gc)
{
	gc->mlx = mlx_init();
	if (!gc->mlx)
		return (0);
	gc->win = mlx_new_window(gc->mlx, T * gc->map_w, T * gc->map_h, "so_long");
	mlx_do_key_autorepeatoff(gc->mlx);
	if (!gc->win)
		return (0);
	if (!load_components(gc))
		return (0);
	if (!find_player_and_clear(gc->map))
		return (0);
	gc->c_left = count_collectibles(gc->map);
	gc->moves = 0;
	gc->exit_open = (gc->c_left == 0);
	gc->enemies = NULL;
	gc->enemy_count = 0;
	gc->key_down = 0;
	enemy_from_map(gc);
	render_all(gc);
	mlx_hook(gc->win, 2, 1L << 0, get_key, gc);
	mlx_hook(gc->win, 3, 1L << 1, key_release, gc);
	mlx_loop_hook(gc->mlx, hold_key, gc);
	mlx_hook(gc->win, 17, 0, destroy, gc);
	mlx_loop(gc->mlx);
	return (1);
}
