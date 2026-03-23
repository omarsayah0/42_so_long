/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:27:41 by oaletham          #+#    #+#             */
/*   Updated: 2025/08/27 21:35:06 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr(int n)
{
	char	c;
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	if (n >= 10)
		count += ft_nbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_unsi_nbr(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 10)
		count += ft_unsi_nbr(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_print_hex_low(unsigned int num)
{
	const char	*low;
	int			count;

	low = "0123456789abcdef";
	count = 0;
	if (num >= 16)
		count += ft_print_hex_low(num / 16);
	count += (int)write(1, &low[num % 16], 1);
	return (count);
}

int	ft_print_hex_up(unsigned int num)
{
	const char	*up;
	int			count;

	up = "0123456789ABCDEF";
	count = 0;
	if (num >= 16)
		count += ft_print_hex_up(num / 16);
	count += (int)write(1, &up[num % 16], 1);
	return (count);
}
