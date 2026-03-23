/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_anim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:13:27 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/19 19:12:04 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reset_player_anim(t_game *g)
{
	int	dir;

	if (!g)
		return ;
	dir = g->player_anim.current_dir;
	if (dir < 0 || dir >= PLAYER_DIRECTIONS)
		return ;
	if (g->player_anim.frame_counts[dir] == 0)
		return ;
	g->player_anim.current = 0;
	g->player_anim.tick = 0;
	g->player = g->player_anim.frames[dir][0];
}

void	start_player_anim_cycle(t_game *g)
{
	int	dir;
	int	count;

	if (!g)
		return ;
	dir = g->player_anim.current_dir;
	if (dir < 0 || dir >= PLAYER_DIRECTIONS)
		return ;
	count = g->player_anim.frame_counts[dir];
	if (count <= 1)
		return ;
	g->player_anim.playing = 1;
	g->player_anim.frames_left = count - 1;
	reset_player_anim(g);
}

int	set_player_anim_dir(t_game *g, int dir)
{
	if (!g)
		return (0);
	if (dir < 0 || dir >= PLAYER_DIRECTIONS)
		return (0);
	if (g->player_anim.frame_counts[dir] == 0)
		return (0);
	if (g->player_anim.current_dir == dir)
		return (0);
	g->player_anim.current_dir = dir;
	start_player_anim_cycle(g);
	return (1);
}

static void	player_animation_loop_reset(t_game *g)
{
	if (g->player_anim.frames_left > 0)
	{
		g->player_anim.frames_left--;
		if (g->player_anim.frames_left == 0)
		{
			g->player_anim.playing = 0;
			reset_player_anim(g);
		}
	}
}

int	player_animation_loop(void *param)
{
	t_game	*g;
	int		dir;
	int		count;
	int		next;

	g = (t_game *)param;
	if (!g)
		return (0);
	dir = g->player_anim.current_dir;
	if (dir < 0 || dir >= PLAYER_DIRECTIONS)
		return (0);
	count = g->player_anim.frame_counts[dir];
	if (!g->player_anim.playing || count <= 1)
		return (0);
	g->player_anim.tick++;
	if (g->player_anim.tick < g->player_anim.delay)
		return (0);
	g->player_anim.tick = 0;
	next = (g->player_anim.current + 1) % count;
	g->player_anim.current = next;
	g->player = g->player_anim.frames[dir][next];
	player_animation_loop_reset(g);
	if (g->map && g->win)
		render_all(g);
	return (0);
}
