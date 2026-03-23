/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:06:23 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/20 18:28:03 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

long	current_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

static void	draw_moves(t_game *g)
{
	char	*num;
	int		win_w;
	int		text_len;
	int		text_w;
	int		x;

	if (!g || !g->mlx || !g->win)
		return ;
	num = ft_itoa(g->moves);
	if (!num)
		return ;
	win_w = g->map_w * T;
	text_len = ft_strlen("Moves: ") + ft_strlen(num);
	text_w = text_len * 10;
	x = (win_w - text_w) / 2;
	mlx_string_put(g->mlx, g->win, x, 20, 0xFFFFFF, "Moves: ");
	mlx_string_put(g->mlx, g->win, x + 60, 20, 0xFFFFFF, num);
	free(num);
}

void	render_all(t_game *gc)
{
	int	i;

	put_floor(gc);
	put_things(gc, gc->map);
	mlx_put_image_to_window(gc->mlx, gc->win,
		gc->player.img, gc->map->player_col * T, gc->map->player_row * T);
	if (gc->enemy_count > 0 && gc->enemies)
	{
		i = 0;
		while (i < gc->enemy_count)
		{
			mlx_put_image_to_window(gc->mlx, gc->win,
				gc->enemy_img.img,
				gc->enemies[i].col * T,
				gc->enemies[i].row * T);
			i++;
		}
	}
	draw_moves(gc);
}

static void	free_partial_copy(char **cpy, int rows_allocated)
{
	int	k;

	k = 0;
	while (k < rows_allocated)
	{
		free(cpy[k]);
		k++;
	}
	free(cpy);
}

char	**cpy_map(char **map, int h, int w)
{
	char	**cpy;
	int		i;
	int		j;

	cpy = (char **)malloc(sizeof(char *) * h);
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < h)
	{
		cpy[i] = (char *)malloc(w + 1);
		if (!cpy[i])
		{
			free_partial_copy(cpy, i);
			return (NULL);
		}
		j = 0;
		while (j < w)
		{
			cpy[i][j] = map[i][j];
			j++;
		}
		cpy[i++][w] = '\0';
	}
	return (cpy);
}
