/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:15:58 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/17 14:43:33 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_player_and_clear(t_mapinfo *m)
{
	int	r;
	int	c;
	int	found;

	if (!m || !m->map)
		return (0);
	found = 0;
	r = 0;
	while (r < m->height)
	{
		c = 0;
		while (c < m->width)
		{
			if (m->map[r][c] == 'P')
			{
				m->player_row = r;
				m->player_col = c;
				m->map[r][c] = '0';
				found = 1;
			}
			c++;
		}
		r++;
	}
	return (found);
}

static int	can_enter(t_game *g, int r, int c)
{
	char	ch;

	if (r < 0 || c < 0 || r >= g->map->height || c >= g->map->width)
		return (0);
	ch = g->map->map[r][c];
	if (ch == '1')
		return (0);
	if (ch == 'E' && g->c_left > 0)
		return (0);
	return (1);
}

static int	apply_enter(t_game *g, int r, int c)
{
	char	*cell;

	cell = &g->map->map[r][c];
	if (*cell == 'C')
	{
		*cell = '0';
		g->c_left--;
	}
	if (g->c_left == 0)
		g->exit_open = 1;
	g->map->player_row = r;
	g->map->player_col = c;
	g->moves++;
	start_player_anim_cycle(g);
	if (*cell == 'E' && g->exit_open)
		return (2);
	return (1);
}

int	move_player(t_game *g, int *dr, int *dc)
{
	int	nr;
	int	nc;

	nr = g->map->player_row + *dr;
	nc = g->map->player_col + *dc;
	if (!can_enter(g, nr, nc))
		return (0);
	return (apply_enter(g, nr, nc));
}
