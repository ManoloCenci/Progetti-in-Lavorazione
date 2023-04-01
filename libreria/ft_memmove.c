/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 10:27:34 by mcenci            #+#    #+#             */
/*   Updated: 2023/03/31 10:37:00 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (0);
	i = 0;
	while (i < len && ((char *)src)[i] != '\0')
	{
		(((char *)dst)[i] = ((char *)src)[i]);
		i++;
	}
	((char *)dst)[i] = '\0';
	return (dst);
}
