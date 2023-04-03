/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:10:04 by mcenci            #+#    #+#             */
/*   Updated: 2023/04/03 12:20:12 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new;
	int	i;

	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(s1));
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	return (new);
}