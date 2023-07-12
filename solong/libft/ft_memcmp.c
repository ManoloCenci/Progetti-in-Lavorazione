/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 14:51:26 by mcenci            #+#    #+#             */
/*   Updated: 2023/04/08 15:08:20 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*ptr1;

	ptr = (unsigned char *)s1;
	ptr1 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == ptr1[i])
			i++;
		else if (ptr[i] != ptr1[i])
			return (ptr[i] - ptr1[i]);
	}
	return (0);
}
