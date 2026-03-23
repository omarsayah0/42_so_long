/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destory.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:19:36 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/20 18:00:19 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_images(t_game *g)
{
	if (g->floor.img)
		mlx_destroy_image(g->mlx, g->floor.img);
	if (g->w.img)
		mlx_destroy_image(g->mlx, g->w.img);
	if (g->player.img)
		mlx_destroy_image(g->mlx, g->player.img);
	if (g->c.img)
		mlx_destroy_image(g->mlx, g->c.img);
	if (g->exit_closed.img)
		mlx_destroy_image(g->mlx, g->exit_closed.img);
	if (g->exit_open_i.img)
		mlx_destroy_image(g->mlx, g->exit_open_i.img);
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
	if (g)
	{
		destroy_images(g);
		if (g->win)
		{
			mlx_destroy_window(g->mlx, g->win);
			g->win = NULL;
		}
		if (g->mlx)
		{
			mlx_destroy_display(g->mlx);
			free(g->mlx);
			g->mlx = NULL;
		}
		if (g->map)
		{
			free_map_mem(g->map);
			free(g->map);
			g->map = NULL;
		}
	}
	exit(0);
	return (0);
}
