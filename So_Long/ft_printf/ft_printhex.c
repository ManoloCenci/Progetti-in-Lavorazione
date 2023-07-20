/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarcian <dmarcian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:48:53 by dmarcian          #+#    #+#             */
/*   Updated: 2023/05/13 15:37:02 by dmarcian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long n, char *format)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_printhex(n / 16, format);
	i += ft_printchar(format[n % 16]);
	return (i);
}
