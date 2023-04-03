/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 13:17:14 by mcenci            #+#    #+#             */
/*   Updated: 2023/04/02 18:26:01 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	len_set(const char *s, const char *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while(s[i] == set[j])
		{
			j++;
		}
		i++;
	}
	return (s[i]);
}

char	*ft_strtrim(char const *s1, char const *s2)
{
	char	*new;
	int	i;

	i = 0;
	new = (char *)malloc(sizeof(char) * len_set(s1, s2));
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int main()
{
	char a[] = "Ciao a tutti";
	char b[] = "tu";
	printf("%s\n", ft_strtrim(a, b));
}