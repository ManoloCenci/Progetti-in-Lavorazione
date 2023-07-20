/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarcian <dmarcian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 22:04:05 by dmarcian          #+#    #+#             */
/*   Updated: 2023/05/13 15:36:10 by dmarcian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	types(const char c, va_list args)
{
	int	res;

	res = 0;
	if (c == 'c')
		res += ft_printchar((char)va_arg(args, int));
	else if (c == 's')
		res += ft_printstring(va_arg(args, char *));
	else if (c == 'd' || c == 'i')
		res += ft_printnumb(va_arg(args, int));
	else if (c == 'p')
		res += ft_printpointer(va_arg(args, unsigned long), "0123456789abcdef");
	else if (c == 'u')
		res += ft_printunsigned(va_arg(args, unsigned int));
	else if (c == 'x')
		res += ft_printhex(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		res += ft_printhex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else
		res += ft_printperc();
	return (res);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		j;
	va_list	args;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	va_start(args, s);
	while (s && s[i])
	{
		if (s[i] == '%')
			j += types(s[++i], args);
		else
			j += ft_printchar(s[i]);
		i++;
	}
	va_end(args);
	return (j);
}
