/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergamboa <ergamboa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:33:46 by ergamboa          #+#    #+#             */
/*   Updated: 2025/09/17 17:45:42 by ergamboa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;               // avança para o especificador
			if (*format == '\0')    // se a string termina com '%'
				break;              // evita ler além do '\0'
			count += ft_handle_format(*format, &args);
		}
		else
		{
			int w = write(1, format, 1);
			if (w < 0)             // se write falhar
			{
				va_end(args);
				return (-1);       // erro (como printf real faz)
			}
			count += w;
		}
		format++;
	}
	va_end(args);
	return (count);
}
