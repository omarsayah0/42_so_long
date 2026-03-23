/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaletham <oaletham@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:36:33 by oaletham          #+#    #+#             */
/*   Updated: 2025/08/27 21:43:18 by oaletham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *fmt, ...);

int	ft_print_char(char c);
int	ft_print_string(const char *s);
int	ft_nbr(int n);
int	ft_unsi_nbr(unsigned int n);
int	ft_print_hex_low(unsigned int num);
int	ft_print_hex_up(unsigned int num);
int	ft_print_hex_low_ptr(unsigned long num);
int	ft_print_ptr(void *p);

#endif
