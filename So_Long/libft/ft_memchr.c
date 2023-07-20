/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarcian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 20:40:52 by dmarcian          #+#    #+#             */
/*   Updated: 2023/05/04 20:47:58 by dmarcian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cpy;
	size_t			i;

	cpy = (unsigned char *)s;
	i = 0;
	while (n > i)
	{
		if (cpy[i] == (unsigned char)c)
			return (&cpy[i]);
		i++;
	}
	return (NULL);
}
