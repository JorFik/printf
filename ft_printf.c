/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:29:51 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/27 19:58:05 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *formato, ...)
{
	int				bytes_printed;
	int				tmp;
	int				i;
	va_list			input;

	va_start(input, formato);
	bytes_printed = 0;
	i = 0;
	while (formato[i])
	{
		if (formato[i] != '%')
			tmp = ft_printf_formato(&formato[i]);
		if (formato[i] != '%')
			i += tmp;
		else if (formato[i] == '%')
		{
			tmp = ft_cases(&formato[i], input);
			i += 2;
		}
		bytes_printed += tmp;
		if (tmp == -1)
			return (-1);
	}
	va_end(input);
	return (bytes_printed);
}

// int	main(void)
// {
// 	int	a;
// 	int	c;

// 	a = ft_printf ("ft_printf = %p", 0);
// 	ft_printf("\n");
// 	c = printf ("   printf = %p", (void *)0);
// 	printf ("\nft_printf = %d\n   printf = %d\n     Diff = %d\n", a, c, a - c);
// 	return (0);
// }
