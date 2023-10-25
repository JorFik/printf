/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formato.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:12:34 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/25 15:53:25 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf_formato(const char *formato)
{
	int		s_to_print;

	s_to_print = 0;
	while (formato[s_to_print] && formato[s_to_print] != '%')
	{
		s_to_print++;
		ft_putchar_fd(formato[s_to_print], 1);
	}
	return (s_to_print);
}
