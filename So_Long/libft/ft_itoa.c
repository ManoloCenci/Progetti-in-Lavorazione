/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darlan <darlan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:55:43 by darlan            #+#    #+#             */
/*   Updated: 2023/05/04 20:30:58 by dmarcian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lenght(int nb, int base)
{
	int	c;

	c = 0;
	if (nb <= 0)
		++c;
	while (nb && ++c)
		nb /= base;
	return (c);
}

char	*ft_itoa(int nb)
{
	int			len;
	char		*str;
	const char	*d = "0123456789";

	len = lenght(nb, 10);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = 0;
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
		str[0] = '-';
	while (nb)
	{
		if (nb > 0)
			str[--len] = d[nb % 10];
		else
			str[--len] = d[nb % 10 * -1];
		nb /= 10;
	}
	return (str);
}
