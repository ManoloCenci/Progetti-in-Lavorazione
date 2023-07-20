/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarcian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:20:50 by dmarcian          #+#    #+#             */
/*   Updated: 2023/05/04 21:17:45 by dmarcian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	t;
	char	*news;
	int		i;

	i = 0;
	news = (char *)s;
	t = c;
	while (news[i] != t)
	{
		if (news[i] == '\0')
			return (0);
		i++;
	}
	return ((char *)news + i);
}
