/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 21:17:59 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/02 16:47:04 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_gnl_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

static char	*ft_gnl_memcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

char	*ft_gnl_substr(const char *s, size_t start, size_t len)
{
	size_t	slen;
	char	*out;

	if (!s)
		return (NULL);
	slen = ft_gnl_strlen(s);
	if (start >= slen)
	{
		out = (char *)malloc(1);
		if (!out)
			return (NULL);
		out[0] = '\0';
		return (out);
	}
	if (start + len > slen)
		len = slen - start;
	out = (char *)malloc(len + 1);
	if (!out)
		return (NULL);
	ft_gnl_memcpy(out, s + start, len);
	out[len] = '\0';
	return (out);
}

char	*ft_gnl_strjoin_free(char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*out;

	len1 = ft_gnl_strlen(s1);
	len2 = ft_gnl_strlen(s2);
	out = (char *)malloc(len1 + len2 + 1);
	if (!out)
	{
		free(s1);
		return (NULL);
	}
	if (s1)
		ft_gnl_memcpy(out, s1, len1);
	if (s2)
		ft_gnl_memcpy(out + len1, s2, len2);
	out[len1 + len2] = '\0';
	free(s1);
	return (out);
}
