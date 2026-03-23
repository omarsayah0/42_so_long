/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 13:54:11 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/20 18:55:04 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map(char **map, int h)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < h)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static int	valid_map2(char **map, int h, int w)
{
	if (!check_walls(map, h, w))
	{
		ft_printf("Error\nThe map is not enclosed by walls");
		free_map(map, h);
		return (0);
	}
	if (!check_path(map, h, w))
	{
		ft_printf("Error\nThere is no valid path");
		free_map(map, h);
		return (0);
	}
	return (1);
}

static int	valid_map(char **map, int h, int w)
{
	int	check_count;

	check_count = check_counts(map, h, w);
	if (check_count == 0)
	{
		ft_printf("Error\nThere is duplicate charectaers(exit/start)");
		free_map(map, h);
		return (0);
	}
	if (check_count == 2)
	{
		ft_printf("Error\nThere is no collecntions");
		free_map(map, h);
		return (0);
	}
	if (!check_allowd_chars(map, h, w))
	{
		ft_printf("Error\nThere is an char that is not allowd");
		free_map(map, h);
		return (0);
	}
	return (valid_map2(map, h, w));
}

static int	init_game(t_game *map, char *filename)
{
	if (no_map(filename) == 0 || open_map_file(filename) == 0)
		return (0);
	map_dim(filename, &map->map_h, &map->map_w);
	if (map->map_h == 0 || map->map_w == 0)
	{
		ft_printf("Error\nThe map is not rectangle");
		return (0);
	}
	map->map = malloc(sizeof(*map->map));
	if (!map->map)
		return (0);
	map->map->height = map->map_h;
	map->map->width = map->map_w;
	map->map->map = read_map(filename, map->map_h, map->map_w);
	if (!map->map->map || !valid_map(map->map->map, map->map_h, map->map_w))
	{
		free(map->map);
		map->map = NULL;
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_game	map;

	ft_memset(&map, 0, sizeof(map));
	if (argc != 2)
	{
		ft_printf("Error\nMissing .ber map file\n");
		return (0);
	}
	if (!init_game(&map, argv[1]))
		return (1);
	if (!open_window(&map))
		destroy(&map);
	return (0);
}
