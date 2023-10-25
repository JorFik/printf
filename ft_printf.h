/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:57:54 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/25 15:53:33 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *formato, ...);
int	ft_printf_formato(const char *formato);
int	ft_select_case1(const char *formato, va_list input);
int	ft_select_case2(const char *formato, va_list input);
#endif

// ? Program name libftprintf.a
// _ Turn in files Makefile, *.h, */*.h, *.c, */*.c
// ~ Makefile NAME, all, clean, fclean, re
// * External functs.
// ! malloc, free, write,
// ! va_start, va_arg, va_copy, va_end
// * Libft authorized Yes
// _ Description Write a library that contains ft_printf(), a
// _ function that will mimic the original printf()