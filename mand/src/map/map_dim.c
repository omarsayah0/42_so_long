/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 14:32:14 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/20 14:37:29 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clear_fd_rest(int fd)
{
	char	*tmp;

	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
}

static int	scan_dims(int fd, int *h, int *w)
{
	char	*line;
	int		len;

	*h = 0;
	*w = 0;
	line = get_next_line(fd);
	while (line)
	{
		len = line_effective_len(line);
		if (*w == 0)
			*w = len;
		else if (len != *w)
		{
			free(line);
			clear_fd_rest(fd);
			return (0);
		}
		(*h)++;
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

void	map_dim(char *filename, int *out_height, int *out_width)
{
	int	fd;
	int	h;
	int	w;
	int	ok;

	if (!filename || !out_height || !out_width)
		return ;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return ;
	ok = scan_dims(fd, &h, &w);
	close(fd);
	if (!ok)
	{
		*out_height = 0;
		*out_width = 0;
		return ;
	}
	*out_height = h;
	*out_width = w;
}
