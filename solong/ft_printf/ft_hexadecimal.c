/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:47:33 by mcenci            #+#    #+#             */
/*   Updated: 2023/04/24 13:03:16 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexadecimal(unsigned int n, char *str)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_hexadecimal(n / 16, str);
	i += ft_putchar(str[n % 16]);
	return (i);
}
