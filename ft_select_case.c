/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:35:54 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/25 15:53:23 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_select_case1(const char *formato, va_list input)
{
	if (*formato == '%' && formato[1] == 'c')
		ft_putchar_fd(va_arg(input, int), 1);
	if (*formato == '%' && formato[1] == 'c')
		return (2);
	if (*formato == '%' && formato[1] == 's')
		;
	if (*formato == '%' && (formato[1] == 'd' || formato[1] == 'i'))
		;
	if (*formato == '%' && formato[1] == 'u')
		;
	if (*formato == '%' && formato[1] == '%')
		ft_putchar_fd ('%', 1);
	if (*formato == '%' && formato[1] == '%')
		return (2);
	ft_putendl_fd(
		"Invalid format\nValid formats: c, s, p, d, i, u, x, X, %", 1);
	return (0);
}

int	ft_select_case2(const char *formato, va_list input)
{
	va_arg(input, int);
	if (*formato == '%' && formato[1] == 'p')
		;
	if (*formato == '%' && formato[1] == 'x')
		;
	if (*formato == '%' && formato[1] == 'X')
		;
	return (0);
}
// ! Returns should be bytes printed + 1
// * %c char
// * %s str
// * %i int base 10
// * %d decimal base 10 number same shit as %i
// * %u unsigned int base 10

// * %p (void *) in hexadecimal format
// * %x %X hexadecimal uppercase or lowercase
// * %% prints '%'