/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:51:26 by mcenci            #+#    #+#             */
/*   Updated: 2023/03/31 15:07:38 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	unsigned char	*ptr;
	unsigned char	*ptr1;

	ptr = (unsigned char *)s1;
	ptr1 = (unsigned char *)s2;
	i = 0;
	if (ptr[i] == '\0' || ptr1[i] == '\0')
		return (0);
	while ((ptr[i] != '\0' && ptr1[i] != '\0') && (i < n))
	{
		if (ptr[i] == ptr1[i])
			i++;
		else if (ptr[i] != ptr1[i])
			return ((int)(ptr[i] - ptr1[i]));
	}
	return (0);
}
