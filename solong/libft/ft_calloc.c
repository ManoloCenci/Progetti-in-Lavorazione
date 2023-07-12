/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:12:20 by mcenci            #+#    #+#             */
/*   Updated: 2023/04/08 11:30:13 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	if (count + size < count || count + size < size)
		return (NULL);
	str = (void *)malloc(count * size);
	if (!str)
		return (NULL);
	ft_bzero(str, (count * size));
	return (str);
}
