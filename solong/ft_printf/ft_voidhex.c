/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voidhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:56:51 by mcenci            #+#    #+#             */
/*   Updated: 2023/04/24 13:07:32 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex(unsigned long n, char *str)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += hex(n / 16, str);
	i += ft_putchar(str[n % 16]);
	return (i);
}

int	ft_voidhex(unsigned long n, char *str)
{
	int	x;

	x = 2;
	ft_putchar('0');
	ft_putchar('x');
	x += hex(n, str);
	return (x);
}
