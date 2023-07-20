/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarcian <dmarcian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:31:27 by dmarcian          #+#    #+#             */
/*   Updated: 2023/05/13 15:47:01 by dmarcian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnumb(int nb)
{
	int	tot;

	tot = 0;
	if (nb == -2147483648)
	{
		tot += ft_printstring("-2");
		nb = (147483648);
	}
	if (nb < 0)
	{
		tot += ft_printchar('-');
		nb *= -1;
	}
	if (nb >= 10)
		tot += ft_printnumb(nb / 10);
	tot += ft_printchar(nb % 10 + 48);
	return (tot);
}
