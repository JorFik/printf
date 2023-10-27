/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_formato.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <JFikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 23:12:34 by JFikents          #+#    #+#             */
/*   Updated: 2023/10/27 18:35:26 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_formato(const char *formato)
{
	int	i;

	i = 0;
	while (formato[i] && formato[i] != '%')
	{
		if (ft_putchar(formato[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}
