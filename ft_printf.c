/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergamboa <ergamboa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:33:46 by ergamboa          #+#    #+#             */
/*   Updated: 2025/09/25 18:09:04 by ergamboa         ###   ########.fr       */
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

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*str = "hello";
	int		n = -123;
	unsigned int u = 4294967295;
	char	c = 'A';

	ft_printf("FT_PRINTF              |");
	printf("PRINTF:\n");
	printf("________________________________________________\n");
	ft_printf("String: %s          |", str);
	printf("String: %s\n", str);
	ft_printf("Int: %d              |", n);
	printf("Int: %d\n", n);
	ft_printf("Unsigned: %u   |", u);
	printf("Unsigned: %u\n", u);
	ft_printf("Hex x: %x        |", u);
	printf("Hex x: %x\n", u);
	ft_printf("Hex X: %X        |", u);
	printf("Hex X: %X\n", u);
	ft_printf("Pointer: %p      |", str);
	printf("Pointer: %p\n", str);
	ft_printf("Percent: %%             |");
	printf("Percent: %%\n");
	ft_printf("Char: %c                |", c);
	printf("Char: %c\n", c);
	ft_printf(" %p %p ", 0, 0);
	printf(" %p %p ", (void*)0, (void*)0);
}
