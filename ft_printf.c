/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:29:51 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/26 23:13:00 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *formato, ...)
{
	va_list		input;
	static int	s_to_print;
	int			i;
	int			tmp;

	i = 0;
	s_to_print = 0;
	va_start(input, formato);
	while (formato[i])
	{
		if (formato[i] != '%')
		{
			tmp = ft_printf_formato(&formato[i]);
			i += tmp;
			s_to_print += tmp;
		}
		if (formato[i] == '%')
		{
			s_to_print += ft_cases(&formato[i], input);
			i += 2;
		}
	}
	va_end(input);
	return (s_to_print);
}

int	main(void)
{
	int		a;
	int		c;

	a = ft_printf ("ft_printf = %p \n", (void *)16);
	c = printf ("000printf = %p \n", (void *)16);
	printf ("ft_printf = %d\nprintf = %d\n", a, c);
	return (0);
}
// LONG_MIN LONG MAX
// INT MIN INT MAX
// ULONG MAX -ULONG MAX
// 0, 0