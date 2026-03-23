/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_anim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 18:59:52 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/19 19:04:57 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static const char	*get_frame_path(int dir, int frame)
{
	static const char	*paths[PLAYER_DIRECTIONS][PLAYER_FRAMES] = {
	{"textures/down/ideal_down.xpm",
		"textures/down/walk1_down.xpm",
		"textures/down/walk2_down.xpm",
		"textures/down/walk3_down.xpm" },
	{"textures/left/ideal_left.xpm",
		"textures/left/walk1_left.xpm",
		"textures/left/walk2_left.xpm",
		"textures/left/walk3_left.xpm" },
	{"textures/right/ideal_right.xpm",
		"textures/right/walk1_right.xpm",
		"textures/right/walk2_right.xpm",
		"textures/right/walk3_right.xpm" },
	{"textures/up/ideal_up.xpm",
		"textures/up/walk1_up.xpm",
		"textures/up/walk2_up.xpm",
		"textures/up/walk3_up.xpm" }
	};

	if (dir < 0 || dir >= PLAYER_DIRECTIONS
		|| frame < 0 || frame >= PLAYER_FRAMES)
		return (NULL);
	return (paths[dir][frame]);
}

static void	do_anim_struct(t_anim *anim)
{
	int	dir;
	int	frame;

	dir = 0;
	while (dir < PLAYER_DIRECTIONS)
	{
		anim->frame_counts[dir] = 0;
		frame = 0;
		while (frame < PLAYER_FRAMES)
		{
			anim->frames[dir][frame].img = NULL;
			anim->frames[dir][frame].w = 0;
			anim->frames[dir][frame].h = 0;
			frame++;
		}
		dir++;
	}
	anim->current_dir = DIR_RIGHT;
	anim->current = 0;
	anim->tick = 0;
	anim->delay = PLAYER_ANIM_DELAY;
	anim->playing = 0;
	anim->frames_left = 0;
}

static int	load_frame(t_game *g, t_img *frame, const char *path)
{
	frame->img = mlx_xpm_file_to_image(g->mlx,
			(char *)path, &frame->w, &frame->h);
	if (frame->img == NULL)
		return (0);
	return (1);
}

int	do_player_anim(t_game *g)
{
	int	dir;
	int	frame;

	do_anim_struct(&g->player_anim);
	dir = 0;
	while (dir < PLAYER_DIRECTIONS)
	{
		frame = 0;
		while (frame < PLAYER_FRAMES)
		{
			if (!load_frame(g, &g->player_anim.frames[dir][frame],
				get_frame_path(dir, frame)))
			{
				destroy_player_anim(g);
				return (0);
			}
			g->player_anim.frame_counts[dir]++;
			frame++;
		}
		dir++;
	}
	g->last_move_time = current_time_ms();
	g->player = g->player_anim.frames[g->player_anim.current_dir][0];
	return (1);
}
