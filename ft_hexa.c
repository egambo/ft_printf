/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergamboa <ergamboa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:23:09 by ergamboa          #+#    #+#             */
/*   Updated: 2025/09/25 18:06:32 by ergamboa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_hex(unsigned long long nbr, char specifier)
{
	int		len;

	len = 0;
	if (nbr >= 16)
		len += ft_put_hex(nbr / 16, specifier);
	if (specifier == 'X')
		len += write(1, &"0123456789ABCDEF"[nbr % 16], 1);
	else
		len += write(1, &"0123456789abcdef"[nbr % 16], 1);
	return (len);
}

int	ft_print_hex(unsigned long long nbr, char specifier)
{
	int	len;

	len = 0;
	if (specifier == 'p')
		len += write(1, "0x", 2);
	if (nbr == 0)
		return (len + write(1, "0", 1));
	len += ft_put_hex(nbr, specifier);
	return (len);
}
