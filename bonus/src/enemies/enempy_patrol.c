/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enempy_patrol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:08:52 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/22 15:01:04 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	enemy_count_on_map(t_game *g)
{
	int	r;
	int	c;
	int	count;

	count = 0;
	r = 0;
	while (r < g->map->height)
	{
		c = 0;
		while (c < g->map->width)
		{
			if (g->map->map[r][c] == 'M')
				count++;
			c++;
		}
		r++;
	}
	return (count);
}

static void	enemy_fill_from_map(t_game *g)
{
	int	r;
	int	c;
	int	i;

	r = 0;
	i = 0;
	while (r < g->map->height)
	{
		c = 0;
		while (c < g->map->width)
		{
			if (g->map->map[r][c] == 'M' && i < g->enemy_count)
			{
				g->enemies[i].row = r;
				g->enemies[i].col = c;
				g->enemies[i].dir = -1;
				g->enemies[i].steps = 0;
				g->enemies[i].max_steps = 3;
				g->map->map[r][c] = '0';
				i++;
			}
			c++;
		}
		r++;
	}
}

int	enemy_from_map(t_game *g)
{
	int	count;

	if (!g || !g->map || !g->map->map)
		return (0);
	if (g->enemies)
	{
		free(g->enemies);
		g->enemies = NULL;
	}
	g->enemy_count = 0;
	count = enemy_count_on_map(g);
	if (count <= 0)
		return (0);
	g->enemies = (t_enemy *)malloc(sizeof(t_enemy) * count);
	if (!g->enemies)
		return (0);
	g->enemy_count = count;
	enemy_fill_from_map(g);
	return (g->enemy_count);
}

static int	enemy_step(t_game *g, t_enemy *e)
{
	int		nr;
	char	cell;

	if (e->dir != -1 && e->dir != 1)
		e->dir = -1;
	nr = e->row + e->dir;
	if (nr < 0 || nr >= g->map->height)
	{
		e->dir *= -1;
		return (0);
	}
	cell = g->map->map[nr][e->col];
	if (cell == '1')
		return (e->dir *= -1, 0);
	e->row = nr;
	e->steps++;
	if (e->steps >= e->max_steps)
	{
		e->steps = 0;
		e->dir *= -1;
	}
	if (e->row == g->map->player_row && e->col == g->map->player_col)
		return (-1);
	return (1);
}

int	enemy_patrol(t_game *g)
{
	static long	last = 0;
	long		now;
	int			i;
	int			moved_any;
	int			r;

	if (!g || !g->map || !g->map->map || g->enemy_count <= 0 || !g->enemies)
		return (0);
	now = current_time_ms();
	if (now - last < 400)
		return (0);
	last = now;
	moved_any = 0;
	i = 0;
	while (i < g->enemy_count)
	{
		r = enemy_step(g, &g->enemies[i]);
		if (r == -1)
			return (destroy(g));
		if (r == 1)
			moved_any = 1;
		i++;
	}
	return (moved_any);
}
