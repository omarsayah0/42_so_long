/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:26:32 by oaletham          #+#    #+#             */
/*   Updated: 2025/09/01 16:11:23 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle(char c, va_list ar)
{
	if (c == 'c')
		return (ft_print_char((char)va_arg(ar, int)));
	if (c == 's')
		return (ft_print_string(va_arg(ar, char *)));
	if (c == 'i' || c == 'd')
		return (ft_nbr(va_arg(ar, int)));
	if (c == 'u')
		return (ft_unsi_nbr(va_arg(ar, unsigned int)));
	if (c == 'x')
		return (ft_print_hex_low(va_arg(ar, unsigned int)));
	if (c == 'X')
		return (ft_print_hex_up(va_arg(ar, unsigned int)));
	if (c == 'p')
		return (ft_print_ptr(va_arg(ar, void *)));
	if (c == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_printf(const char *arg, ...)
{
	va_list	ar;
	int		i;
	int		printed;

	printed = 0;
	if (!arg)
		return (-1);
	i = 0;
	va_start(ar, arg);
	while (arg[i])
	{
		if (arg[i] == '%' && arg[i + 1])
		{
			printed += handle(arg[i + 1], ar);
			i = i + 2;
		}
		else
			printed += ft_print_char(arg[i++]);
	}
	va_end(ar);
	return (printed);
}
