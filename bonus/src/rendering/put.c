/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:55:55 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/19 19:15:18 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_floor(t_game *w)
{
	int	r;
	int	c;

	r = 0;
	while (r < w->map_h)
	{
		c = 0;
		while (c < w->map_w)
		{
			mlx_put_image_to_window(w->mlx, w->win, w->floor.img, c * T, r * T);
			c++;
		}
		r++;
	}
}

static void	put_exit(t_game *g, int r, int c)
{
	if (g->exit_open == 1)
		mlx_put_image_to_window(g->mlx, g->win,
			g->exit_open_i.img, c * T, r * T);
	else
		mlx_put_image_to_window(g->mlx, g->win,
			g->exit_closed.img, c * T, r * T);
}

void	put_things(t_game *g, t_mapinfo *map)
{
	int		r;
	int		c;
	char	ch;

	r = 0;
	while (r < map->height)
	{
		c = 0;
		while (c < map->width)
		{
			ch = map->map[r][c];
			if (ch == '1')
				mlx_put_image_to_window(g->mlx, g->win, g->w.img, c * T, r * T);
			else if (ch == 'C')
				mlx_put_image_to_window(g->mlx, g->win, g->c.img, c * T, r * T);
			else if (ch == 'E')
			{
				put_exit(g, r, c);
			}
			c++;
		}
		r++;
	}
}
