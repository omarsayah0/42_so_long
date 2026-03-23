/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:52:49 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/22 15:03:42 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map_copy(char **m, int h)
{
	int	i;

	if (!m)
		return ;
	i = 0;
	while (i < h)
	{
		free(m[i]);
		i++;
	}
	free(m);
}

static void	fill_flod(t_game *flod, int row, int column)
{
	char	state;

	if (row < 0 || column < 0 || row >= flod->map_h || column >= flod->map_w)
		return ;
	state = flod->map->map[row][column];
	if (state == '1' || state == 'D')
		return ;
	if (state == 'E')
	{
		flod->exit_found = 1;
		return ;
	}
	if (state == 'C')
		flod->c_left--;
	if (state == 'E')
		flod->exit_found = 1;
	flod->map->map[row][column] = 'D';
	fill_flod(flod, row + 1, column);
	fill_flod(flod, row - 1, column);
	fill_flod(flod, row, column + 1);
	fill_flod(flod, row, column - 1);
}

static int	run_flood(t_mapinfo *info_map, int c_left_init)
{
	t_game		flod;
	t_mapinfo	mapcpy;

	mapcpy.map = cpy_map(info_map->map, info_map->height, info_map->width);
	if (!mapcpy.map)
		return (0);
	flod.map = &mapcpy;
	flod.map_h = info_map->height;
	flod.map_w = info_map->width;
	flod.c_left = c_left_init;
	flod.exit_found = 0;
	fill_flod(&flod, info_map->player_row, info_map->player_col);
	free_map_copy(mapcpy.map, info_map->height);
	return (flod.c_left == 0 && flod.exit_found);
}

static int	check_reach(t_mapinfo *info_map)
{
	int	row;
	int	col;
	int	c_left;

	if (info_map->player_row < 0 || info_map->player_row >= info_map->height
		|| info_map->player_col < 0 || info_map->player_col >= info_map->width)
		return (0);
	c_left = 0;
	row = 0;
	while (row < info_map->height)
	{
		col = 0;
		while (col < info_map->width)
			c_left += (info_map->map[row][col++] == 'C');
		row++;
	}
	return (run_flood(info_map, c_left));
}

int	check_path(char **map, int h, int w)
{
	int			row;
	int			column;
	t_mapinfo	info_of_map;

	info_of_map.map = map;
	info_of_map.player_row = 0;
	info_of_map.player_col = 0;
	info_of_map.height = h;
	info_of_map.width = w;
	row = 0;
	while (row < h)
	{
		column = 0;
		while (column < w)
		{
			if (map[row][column] == 'P')
			{
				info_of_map.player_row = row;
				info_of_map.player_col = column;
			}
			column++;
		}
		row++;
	}
	return (check_reach(&info_of_map));
}
