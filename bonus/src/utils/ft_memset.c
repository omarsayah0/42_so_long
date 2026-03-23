/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:16:28 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/20 16:38:38 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *s, int c, int n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n)
	{
		*ptr = (unsigned char)c;
		ptr++;
		n--;
	}
	return (s);
}
