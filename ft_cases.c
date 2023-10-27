/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:35:54 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/27 19:44:39 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	if (s)
	{
		while (s[i])
		{
			tmp = ft_putchar(s[i]);
			if (tmp == -1)
				return (-1);
			i ++;
		}
	}
	if (!s)
		return (ft_putstr("(null)"));
	return (i);
}

static int	ft_putnbr(long n, long flag)
{
	static int	fd;
	long		nbr;

	if (flag == 0)
		fd = 0;
	nbr = (long) n;
	if (n < 0)
		fd += ft_putchar('-');
	if (n < 0)
		nbr = -nbr;
	if (nbr > 9)
		ft_putnbr(nbr / 10, 1);
	if (nbr > 9)
		ft_putnbr(nbr % 10, 1);
	else
		fd += ft_putchar(nbr + '0');
	return (fd);
}

int	ft_cases(const char *formato, va_list input)
{
	if (formato[1] == 'c')
		return (ft_putchar(va_arg(input, int)));
	if (formato[1] == 's')
		return (ft_putstr(va_arg(input, char *)));
	if ((formato[1] == 'd' || formato[1] == 'i'))
		return (ft_putnbr(va_arg(input, int), 0));
	if (formato[1] == 'u')
		return (ft_putnbr(va_arg(input, unsigned int), 0));
	if (formato[1] == '%')
		return (ft_putchar ('%'));
	return (ft_hex_cases(formato, input));
}

// ~ %c char
// ~ %s str
// ~ %i int base 10
// ~ %d decimal base 10 number same shit as %i
// ~ %u unsigned int base 10