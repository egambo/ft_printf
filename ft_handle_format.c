/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergamboa <ergamboa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:42:24 by ergamboa          #+#    #+#             */
/*   Updated: 2025/09/17 17:46:48 by ergamboa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_format(char specifier, va_list args)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (specifier == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		len += ft_print_int(va_arg(args, int));
	else if (specifier == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), specifier);
	else if (specifier == 'p')
		len += ft_print_hex(va_arg(args, unsigned long long), specifier);
	else if (specifier == '%')
		len += write(1, "%", 1);
	return (len);
}