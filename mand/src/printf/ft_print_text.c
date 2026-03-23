/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 18:34:43 by oaletham          #+#    #+#             */
/*   Updated: 2025/08/27 21:41:51 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	return ((int)write (1, &c, 1));
}

int	ft_print_string(const char *s)
{
	int	count;

	count = 0;
	if (!s)
		return ((int)write(1, "(null)", 6));
	while (*s)
		count += ((int)write(1, s++, 1));
	return (count);
}
