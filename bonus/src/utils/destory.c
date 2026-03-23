/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:19:36 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/20 17:17:08 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_images(t_game *g)
{
	if (g->floor.img)
		mlx_destroy_image(g->mlx, g->floor.img);
	if (g->w.img)
		mlx_destroy_image(g->mlx, g->w.img);
	destroy_player_anim(g);
	if (g->c.img)
		mlx_destroy_image(g->mlx, g->c.img);
	if (g->exit_closed.img)
		mlx_destroy_image(g->mlx, g->exit_closed.img);
	if (g->exit_open_i.img)
		mlx_destroy_image(g->mlx, g->exit_open_i.img);
	if (g->enemy_img.img)
		mlx_destroy_image(g->mlx, g->enemy_img.img);
}

static void	free_map_mem(t_mapinfo *m)
{
	int	r;

	if (!m || !m->map)
		return ;
	r = 0;
	while (r < m->height)
	{
		free(m->map[r]);
		r++;
	}
	free(m->map);
	m->map = NULL;
}

int	destroy(t_game *g)
{
	if (!g)
		exit(1);
	destroy_images(g);
	if (g->win)
	{
		mlx_destroy_window(g->mlx, g->win);
		g->win = NULL;
	}
	if (g->mlx)
	{
		mlx_do_key_autorepeaton(g->mlx);
		mlx_destroy_display(g->mlx);
		free(g->mlx);
		g->mlx = NULL;
	}
	free(g->enemies);
	g->enemies = NULL;
	g->enemy_count = 0;
	if (g->map)
	{
		free_map_mem(g->map);
		free(g->map);
		g->map = NULL;
	}
	exit(1);
}

static void	reset_destroy_player_anim(t_game *g)
{
	g->player_anim.current = 0;
	g->player_anim.tick = 0;
	g->player_anim.current_dir = DIR_DOWN;
	g->player_anim.delay = PLAYER_ANIM_DELAY;
	g->player_anim.playing = 0;
	g->player_anim.frames_left = 0;
	g->player.img = NULL;
	g->player.w = 0;
	g->player.h = 0;
}

void	destroy_player_anim(t_game *g)
{
	int	dir;
	int	frame;

	if (!g)
		return ;
	dir = 0;
	while (dir < PLAYER_DIRECTIONS)
	{
		frame = 0;
		while (frame < PLAYER_FRAMES)
		{
			if (g->player_anim.frames[dir][frame].img)
				mlx_destroy_image(g->mlx,
					g->player_anim.frames[dir][frame].img);
			g->player_anim.frames[dir][frame].img = NULL;
			g->player_anim.frames[dir][frame].w = 0;
			g->player_anim.frames[dir][frame].h = 0;
			frame++;
		}
		g->player_anim.frame_counts[dir] = 0;
		dir++;
	}
	reset_destroy_player_anim(g);
}
