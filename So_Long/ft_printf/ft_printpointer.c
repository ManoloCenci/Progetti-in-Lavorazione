/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarcian <dmarcian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:24:15 by dmarcian          #+#    #+#             */
/*   Updated: 2023/05/13 15:48:37 by dmarcian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printpointer(unsigned long n, char *format)
{
	int	res;

	res = 0;
	res += ft_printchar('0');
	res += ft_printchar('x');
	res += ft_printhex(n, format);
	return (res);
}
