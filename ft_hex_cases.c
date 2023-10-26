/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:21:06 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/26 23:07:18 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	ft_putnbr_hex(long long n)
{
	static int	fd;
	long long	nbr;

	nbr = n;
	if (!(void *)n)
		printf("%lli", n);
	if (n < 0)
		fd += ft_putchar('-');
	if (n < 0)
		nbr = -nbr;
	if (nbr > 15)
		ft_putnbr_hex(nbr / 16);
	if (nbr > 15)
		ft_putnbr_hex(nbr % 16);
	else
	{
		if (nbr < 10)
			fd += ft_putchar(nbr + '0');
		else
			fd += ft_putchar(nbr + 'a' - 10);
	}
	return (fd);
}

static int	ft_putnbr_hex_up(long long n)
{
	static int	fd;
	long long	nbr;

	nbr = n;
	if (n < 0)
		fd += ft_putchar('-');
	if (n < 0)
		nbr = -nbr;
	if (nbr > 15)
		ft_putnbr_hex(nbr / 16);
	if (nbr > 15)
		ft_putnbr_hex(nbr % 16);
	else
	{
		if (nbr < 10)
			fd += ft_putchar(nbr + '0');
		else
			fd += ft_putchar(nbr + 'A' - 10);
	}
	return (fd);
}

static int	ft_put_pointer(void *n)
{
	static int			counter;
	unsigned long long	nbr;

	nbr = (unsigned long long) n;
	ft_putchar('0');
	ft_putchar('x');
	if (nbr > 15)
		ft_putnbr_hex(nbr / 16);
	if (nbr > 15)
		counter += ft_putnbr_hex(nbr % 16);
	else
	{
		if (nbr < 10)
			counter += ft_putchar(nbr + '0');
		else
			counter += ft_putchar(nbr + 'a' - 10);
	}
	return (counter);
}

int	ft_hex_cases(const char *formato, va_list input)
{
	if (*formato == '%' && formato[1] == 'p')
		return (ft_put_pointer(va_arg(input, void *)) + 2);
	if (*formato == '%' && formato[1] == 'x')
		return (ft_putnbr_hex(va_arg(input, long long)));
	if (*formato == '%' && formato[1] == 'X')
		return (ft_putnbr_hex_up(va_arg(input, long long)));
	return (0);
}
	// ft_putstr("Invalid format\nValid formats: c, s, p, d, i, u, x, X, %\n");
// ! Returns should be bytes printed + 1

// ~ %p (void *) in hexadecimal format
// ~ %x %X hexadecimal uppercase or lowercase
// ~ %% prints '%'