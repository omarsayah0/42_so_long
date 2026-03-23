/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:37:47 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/20 14:26:47 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_allowd_chars(char **map, int h, int w)
{
	int		row;
	int		column;
	char	c;

	row = 0;
	column = 0;
	while (row < h)
	{
		column = 0;
		while (column < w)
		{
			c = map[row][column];
			if (c != '0' && c != '1' && c != 'C'
				&& c != 'E' && c != 'P' && c != 'M')
				return (0);
			column++;
		}
		row++;
	}
	return (1);
}

static int	count_char(char **map, int h, int w, char target)
{
	int	row;
	int	column;
	int	count;

	count = 0;
	row = 0;
	while (row < h)
	{
		column = 0;
		while (column < w)
		{
			if (map[row][column] == target)
				count++;
			column++;
		}
		row++;
	}
	return (count);
}

int	check_counts(char **map, int h, int w)
{
	int	p_count;
	int	c_count;
	int	e_count;

	e_count = count_char(map, h, w, 'E');
	p_count = count_char(map, h, w, 'P');
	c_count = count_char(map, h, w, 'C');
	if (e_count != 1 || p_count != 1)
		return (0);
	if (c_count < 1)
		return (2);
	return (1);
}

int	check_walls(char **map, int h, int w)
{
	int	row;
	int	column;

	column = 0;
	while (column < w)
	{
		if (map[0][column] != '1' || map[h - 1][column] != '1')
			return (0);
		column++;
	}
	row = 0;
	while (row < h)
	{
		if (map[row][0] != '1' || map[row][w - 1] != '1')
			return (0);
		row++;
	}
	return (1);
}
