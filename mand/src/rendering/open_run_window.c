/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_run_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:09:47 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/20 17:11:52 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	load_components(t_game *gc)
{
	gc->floor.img = mlx_xpm_file_to_image(gc->mlx,
			"textures/floor.xpm", &gc->floor.w, &gc->floor.h);
	if (gc->floor.img == NULL)
		return (0);
	gc->w.img = mlx_xpm_file_to_image(gc->mlx,
			"textures/wall.xpm", &gc->w.w, &gc->w.h);
	if (gc->w.img == NULL)
		return (0);
	gc->player.img = mlx_xpm_file_to_image(gc->mlx,
			"textures/player.xpm", &gc->player.w, &gc->player.h);
	if (gc->player.img == NULL)
		return (0);
	gc->c.img = mlx_xpm_file_to_image(gc->mlx,
			"textures/collect.xpm", &gc->c.w, &gc->c.h);
	if (gc->c.img == NULL)
		return (0);
	gc->exit_closed.img = mlx_xpm_file_to_image(gc->mlx,
			"textures/exit_close.xpm", &gc->exit_closed.w, &gc->exit_closed.h);
	if (gc->exit_closed.img == NULL)
		return (0);
	gc->exit_open_i.img = mlx_xpm_file_to_image(gc->mlx,
			"textures/exit_open.xpm", &gc->exit_open_i.w, &gc->exit_open_i.h);
	if (gc->exit_open_i.img == NULL)
		return (0);
	return (1);
}

void	render_all(t_game *gc)
{
	put_floor(gc);
	put_things(gc, gc->map);
	mlx_put_image_to_window(gc->mlx, gc->win,
		gc->player.img, gc->map->player_col * T, gc->map->player_row * T);
}

int	open_window(t_game *gc)
{
	gc->mlx = mlx_init();
	if (!gc->mlx)
		return (0);
	gc->win = mlx_new_window(gc->mlx, T * gc->map_w, T * gc->map_h, "so_long");
	if (!gc->win)
		return (0);
	if (!load_components(gc))
		return (0);
	if (!find_player_and_clear(gc->map))
		return (0);
	gc->c_left = count_collectibles(gc->map);
	gc->moves = 0;
	gc->exit_open = (gc->c_left == 0);
	render_all(gc);
	mlx_key_hook(gc->win, get_key, gc);
	mlx_hook(gc->win, 17, 0, destroy, gc);
	mlx_loop(gc->mlx);
	return (1);
}
