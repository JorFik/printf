/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 22:29:51 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/25 15:53:34 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_printf(const char *formato, ...)
{
	va_list		input;
	static int	s_to_print;
	int			i;

	i = 0;
	va_start(input, formato);
	while (formato[i])
	{
		if (formato[i] != '%')
			s_to_print += ft_printf_formato(formato);
		if (formato[i] != '%')
			i += s_to_print - i;
		if (formato[i] == '%')
			i += ft_select_case1(formato, input);
		if (formato[i] == '%' && s_to_print != i)
			s_to_print += i - s_to_print - 1;
		else
			return (0);
	}
	va_end(input);
	return (s_to_print);
}
