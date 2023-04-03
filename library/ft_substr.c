/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 16:30:50 by mcenci            #+#    #+#             */
/*   Updated: 2023/04/03 12:36:31 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	slen;
	size_t	finish;

	i = 0;
	slen = ft_strlen(s);
	while (i < start)
		i++;
	while (i >= start && s[i] != '\0')
	{
		if (start < slen)
			finish = slen - start;
		if (finish > len)
			finish = len;
		i++;
	}
	if (start > slen)
		return (NULL);
	new = (char *)malloc(sizeof(char) * finish + 1);
	if (!new)
		return (0);
	ft_strlcpy(new, &s[start], finish + 1);
	new[finish + 1] = '\0';
	return (new);
}