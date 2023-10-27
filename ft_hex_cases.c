/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:21:06 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/27 19:32:11 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_putnbr_hex(unsigned int n, int flag)
{
	static int	fd;
	long long	nbr;

	nbr = n;
	if (flag == 0)
		fd = 0;
	if (n < 0)
		fd += ft_putchar('-');
	if (n < 0)
		nbr = -nbr;
	if (nbr > 15)
		ft_putnbr_hex(nbr / 16, 1);
	if (nbr > 15)
		ft_putnbr_hex(nbr % 16, 1);
	else
	{
		if (nbr < 10)
			fd += ft_putchar(nbr + '0');
		else
			fd += ft_putchar(nbr + 'a' - 10);
	}
	return (fd);
}

static int	ft_putnbr_hex_up(unsigned int n, int flag)
{
	static int	fd;
	long long	nbr;

	nbr = n;
	if (flag == 0)
		fd = 0;
	if (n < 0)
		fd += ft_putchar('-');
	if (n < 0)
		nbr = -nbr;
	if (nbr > 15)
		ft_putnbr_hex_up(nbr / 16, 1);
	if (nbr > 15)
		ft_putnbr_hex_up(nbr % 16, 1);
	else
	{
		if (nbr < 10)
			fd += ft_putchar(nbr + '0');
		else
			fd += ft_putchar(nbr + 'A' - 10);
	}
	return (fd);
}

static int	ft_putnbr_uhex(long long n, int flag)
{
	static int			fd;
	unsigned long long	nbr;

	nbr = (unsigned long long) n;
	if (flag == 0)
		fd = 0;
	if (nbr > 15)
		ft_putnbr_uhex(nbr / 16, 1);
	if (nbr > 15)
		ft_putnbr_uhex(nbr % 16, 1);
	else
	{
		if (nbr < 10)
			fd += ft_putchar(nbr + '0');
		else
			fd += ft_putchar(nbr + 'a' - 10);
	}
	return (fd);
}

int	ft_hex_cases(const char *formato, va_list input)
{
	if (formato[1] == 'p')
	{
		ft_putchar('0');
		ft_putchar('x');
		return (ft_putnbr_uhex(va_arg(input, unsigned long long), 0) + 2);
	}
	if (formato[1] == 'X')
		return (ft_putnbr_hex_up(va_arg(input, unsigned int), 0));
	if (formato[1] == 'x')
		return (ft_putnbr_hex(va_arg(input, unsigned int), 0));
	return (0);
}
	// ft_putstr("Invalid format\nValid formats: c, s, p, d, i, u, x, X, %\n");
// ! Returns should be bytes printed + 1

// ~ %p (void *) in hexadecimal format
// ~ %x %X hexadecimal uppercase or lowercase
// ~ %% prints '%'