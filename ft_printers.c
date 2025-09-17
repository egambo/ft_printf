/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergamboa <ergamboa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 18:12:26 by ergamboa          #+#    #+#             */
/*   Updated: 2025/09/17 18:15:26 by ergamboa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

#include "ft_printf.h"

int	ft_print_str(char *s)
{
	int	len;

	len = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[len])
	{
		write(1, &s[len], 1);
		len++;
	}
	return (len);
}

#include "ft_printf.h"

static int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		len += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		len += ft_putnbr(n / 10);
	len += write(1, &"0123456789"[n % 10], 1);
	return (len);
}

int	ft_print_int(int n)
{
	return (ft_putnbr(n));
}

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += ft_print_unsigned(n / 10);
	len += write(1, &"0123456789"[n % 10], 1);
	return (len);
}

#include "ft_printf.h"

static int	ft_put_hex(unsigned long long nbr, char specifier)
{
	int		len;

	len = 0;
	if (nbr >= 16)
		len += ft_put_hex(nbr / 16, specifier);
	if (specifier == 'X' && (nbr % 16) > 9)
		len += write(1, &"0123456789ABCDEF"[nbr % 16], 1);
	else if ((nbr % 16) > 9)
		len += write(1, &"0123456789abcdef"[nbr % 16], 1);
	else
		len += write(1, &"0123456789"[nbr % 16], 1);
	return (len);
}

int	ft_print_hex(unsigned long long nbr, char specifier)
{
	int	len;

	len = 0;
	if (specifier == 'p')
	{
		len += write(1, "0x", 2);
	}
	if (nbr == 0)
	{
		if (specifier == 'p')
			return (len += write(1, "0", 1));
		else
			return (write(1, "0", 1));
	}
	len += ft_put_hex(nbr, specifier);
	return (len);
}

