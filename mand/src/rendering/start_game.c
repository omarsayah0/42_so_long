/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 16:54:45 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/15 15:54:24 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collectibles(t_mapinfo *the_map)
{
	int	row;
	int	column;
	int	count;

	if (!the_map || !the_map->map
		|| the_map->height <= 0 || the_map->width <= 0)
		return (0);
	count = 0;
	row = 0;
	while (row < the_map->height)
	{
		column = 0;
		while (column < the_map->width)
		{
			if (the_map->map[row][column] == 'C')
				count++;
			column++;
		}
		row++;
	}
	return (count);
}

static int	key_to_dir(int key, int *dr, int *dc)
{
	*dr = 0;
	*dc = 0;
	if (key == K_W || key == KEY_UP)
		*dr = -1;
	else if (key == K_S || key == KEY_DOWN)
		*dr = 1;
	else if (key == K_A || key == KEY_LEFT)
		*dc = -1;
	else if (key == K_D || key == KEY_RIGHT)
		*dc = 1;
	else
		return (0);
	return (1);
}

int	get_key(int key, t_game *game)
{
	int	row_walk;
	int	column_walk;
	int	state_of_player;

	if (key == K_ESC)
		return (destroy(game));
	if (!key_to_dir(key, &row_walk, &column_walk))
		return (0);
	state_of_player = move_player(game, &row_walk, &column_walk);
	if (state_of_player != 0)
	{
		render_all(game);
		ft_printf("Moves: %d\n", game->moves);
		if (state_of_player == 2)
			destroy(game);
	}
	return (0);
}
