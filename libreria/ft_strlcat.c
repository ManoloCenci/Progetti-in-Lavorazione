/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 11:59:38 by mcenci            #+#    #+#             */
/*   Updated: 2023/04/01 12:53:43 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
size_t	ft_strlen(const char *s)
{
	size_t	a;
	a = 0;
	while (s[a] != '\0')
		a++;
	return (a);
}
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;
	size_t	len_src;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	j = len_dst;
	i = 0;
	if ((dstsize - 1) > len_dst)
		return (0);
	else if (dstsize - 1 == len_dst)
		return (len_src + dstsize - 1);
	else
		return (len_src + (dstsize));
	while (len_dst < (dstsize - 1) && src[i] != '\0')
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	return (j);
}
