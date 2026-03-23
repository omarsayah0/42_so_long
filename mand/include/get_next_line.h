/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 15:43:11 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/02 15:54:34 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

size_t	ft_gnl_strlen(const char *s);
char	*ft_gnl_strchr(const char *s, int c);
char	*ft_gnl_strjoin_free(char *s1, const char *s2);
char	*ft_gnl_substr(const char *s, size_t start, size_t len);

#endif