/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarcian <dmarcian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:38:51 by dmarcian          #+#    #+#             */
/*   Updated: 2023/05/13 15:50:33 by dmarcian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsigned(unsigned int nb)
{
	int	res;

	res = 0;
	if (nb > 9)
		res += ft_printnumb(nb / 10);
	res += ft_printchar(nb % 10 + 48);
	return (res);
}
