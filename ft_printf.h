/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergamboa <ergamboa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:00:21 by ergamboa          #+#    #+#             */
/*   Updated: 2025/09/18 16:21:35 by ergamboa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_print_char(int c);
int	ft_print_str(char *s);
static int	ft_putnbr(int n);
int	ft_print_int(int n);
int	ft_print_unsigned(unsigned int n);
static int	ft_put_hex(unsigned long long nbr, char specifier);
int	ft_print_hex(unsigned long long nbr, char specifier);
int	ft_handle_format(char specifier, va_list args);

#endif