/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:06:54 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/20 18:58:29 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_grid(char **map, int row)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i < row)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static int	fill_map(char **map, int fd, int h, int w)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd);
	while (i < h && line)
	{
		if (line_effective_len(line) != w)
		{
			free(line);
			return (i);
		}
		map[i] = (char *)malloc(w + 1);
		if (!map[i])
		{
			free(line);
			return (i);
		}
		ft_memcpy(map[i], line, w);
		map[i][w] = '\0';
		free(line);
		i++;
		line = get_next_line(fd);
	}
	return (i);
}

char	**read_map(char *filename, int h, int w)
{
	int		fd;
	char	**map;
	int		filled;

	if (!filename)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map = (char **)malloc(sizeof(char *) * (h + 1));
	if (!map)
	{
		close(fd);
		return (NULL);
	}
	filled = fill_map(map, fd, h, w);
	close(fd);
	if (filled != h)
	{
		free_grid(map, filled);
		return (NULL);
	}
	map[h] = NULL;
	return (map);
}
