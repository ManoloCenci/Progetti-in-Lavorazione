/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmarcian <dmarcian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:22:53 by dmarcian          #+#    #+#             */
/*   Updated: 2023/07/14 15:24:39 by dmarcian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlenn(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_search(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == ('\n'))
			return (&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ptr;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (0);
	ptr = (char *)malloc((ft_strlenn(s1) + ft_strlenn(s2) + 1) * sizeof(char));
	if (!ptr)
		return (0);
	i = -1;
	while (s1[++i] != 0)
		ptr[i] = s1[i];
	j = 0;
	while (s2[j] != 0)
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free(s1);
	return (ptr);
}

char	*ft_putline(char *str)
{
	char	*mal;
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	mal = (char *)malloc(sizeof(char) * (i + 2));
	if (!mal)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		mal[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		mal[i] = str[i];
		i++;
	}
	mal[i] = '\0';
	return (mal);
}

char	*ft_new(char *str)
{
	char	*mal;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	mal = (char *)malloc(sizeof(char *) * (ft_strlenn(str) - i + 1));
	if (!mal)
		return (NULL);
	i++;
	j = 0;
	while (str[i])
		mal[j++] = str[i++];
	mal[j] = '\0';
	free(str);
	return (mal);
}
