/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:24:27 by mcenci            #+#    #+#             */
/*i  Updated: 2023/03/29 14:41:21 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = b;
	while (i < len)
	{
		str[i] = (char)c;
		i++;
	}
	return (str);
}

#include <stdio.h>
int main()
{
	char a[] = "Daje roma daje";
	printf("%s\n", ft_memset(a, 'g', 6));
}

