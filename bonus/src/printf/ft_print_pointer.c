/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:25:45 by oaletham          #+#    #+#             */
/*   Updated: 2025/08/27 21:36:13 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex_low_ptr(unsigned long num)
{
	const char	*low;
	int			count;

	low = "0123456789abcdef";
	count = 0;
	if (num >= 16)
		count += ft_print_hex_low_ptr(num / 16);
	count += (int)write(1, &low[num % 16], 1);
	return (count);
}

int	ft_print_ptr(void *p)
{
	unsigned long	v;
	int				count;

	count = 0;
	if (!p)
		return (write(1, "(nil)", 5));
	v = (unsigned long)p;
	count += write(1, "0x", 2);
	count += ft_print_hex_low_ptr(v);
	return (count);
}
