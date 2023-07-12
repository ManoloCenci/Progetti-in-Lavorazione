/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:39:03 by mcenci            #+#    #+#             */
/*   Updated: 2023/04/24 13:24:36 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checker(const char str, va_list args)
{
	int	c;

	c = 0;
	if (str == 'c')
		c += ft_putchar((char)va_arg(args, int));
	else if (str == 's')
		c += ft_putstr(va_arg(args, char *));
	else if (str == 'p')
		c += ft_voidhex(va_arg(args, unsigned long), "0123456789abcdef");
	else if (str == 'd' || str == 'i')
		c += ft_putnbr(va_arg(args, int));
	else if (str == 'u')
		c += ft_unsint(va_arg(args, unsigned int));
	else if (str == 'x')
		c += ft_hexadecimal(va_arg(args, unsigned int), "0123456789abcdef");
	else if (str == 'X')
		c += ft_hexadecimal(va_arg(args, unsigned long), "0123456789ABCDEF");
	else if (str == '%')
		c += ft_putchar('%');
	return (c);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		a;

	i = 0;
	a = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			a += ft_checker(str[i], args);
		}
		else
			a += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (a);
}
