/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergamboa <ergamboa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:33:46 by ergamboa          #+#    #+#             */
/*   Updated: 2025/09/26 09:49:57 by ergamboa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_process_format( const char **format, va_list args)
{
	int	len;

	if (**format == '%')
	{
		(*format)++;
		len = ft_handle_format(**format, args);
	}
	else
		len = write(1, *format, 1);
	if (len < 0)
		return (-1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		len;

	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		len = ft_process_format(&format, args);
		if (len < 0)
		{
			va_end(args);
			return (-1);
		}
		count += len;
		format++;
	}
	va_end(args);
	return (count);
}
