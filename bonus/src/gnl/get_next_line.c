/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:17:16 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/02 18:26:04 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_the_line(char **string)
{
	char	*ptr_to_new_line;
	size_t	ll;
	char	*line;
	char	*rest;

	ptr_to_new_line = ft_gnl_strchr(*string, '\n');
	if (ptr_to_new_line)
	{
		ll = (size_t)(ptr_to_new_line - *string) + 1;
		line = ft_gnl_substr(*string, 0, ll);
		rest = ft_gnl_substr(*string, ll, ft_gnl_strlen(*string) - ll);
		free(*string);
		*string = rest;
		return (line);
	}
	line = ft_gnl_substr(*string, 0, ft_gnl_strlen(*string));
	free(*string);
	*string = NULL;
	if (line && *line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

static int	read_until_new_line2(int fd, char **string, char *buffer)
{
	ssize_t	read_bytes;

	read_bytes = 0;
	while (!ft_gnl_strchr(*string, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(buffer);
			return (-1);
		}
		if (read_bytes == 0)
		{
			free(buffer);
			return (0);
		}
		buffer[read_bytes] = '\0';
		*string = ft_gnl_strjoin_free(*string, buffer);
		if (!*string)
		{
			free(buffer);
			return (-1);
		}
	}
	return (1);
}

static int	read_until_new_line(int fd, char **string)
{
	char	*buffer;
	int		n;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	n = read_until_new_line2(fd, string, buffer);
	if (n == -1)
		return (-1);
	if (n == 0)
		return (0);
	free(buffer);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*string;
	int			status;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	status = read_until_new_line(fd, &string);
	if (status == -1)
	{
		free(string);
		string = NULL;
		return (NULL);
	}
	line = extract_the_line(&string);
	return (line);
}
