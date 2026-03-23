/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_exist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 13:59:40 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/14 18:44:39 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	has_ber_extention(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	if (ft_strncmp(filename + len - 4, ".ber", 4) == 0)
		return (1);
	return (0);
}

int	no_map(char *filename)
{
	if (has_ber_extention(filename) == 0)
	{
		ft_printf("Error\nMap file must have .ber extension\n");
		return (0);
	}
	return (1);
}

int	open_map_file(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nCannot open map file\n");
		return (0);
	}
	close(fd);
	return (1);
}
