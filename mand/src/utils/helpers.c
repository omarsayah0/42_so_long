/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 14:06:23 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/19 21:29:50 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	line_effective_len(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
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
