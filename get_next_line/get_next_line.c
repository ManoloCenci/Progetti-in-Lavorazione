/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:03:23 by mcenci            #+#    #+#             */
/*   Updated: 2023/04/17 19:38:44 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

/*size_t	allocate_space(int fd)
{
	char	*s;
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	s = malloc((BUFFER_SIZE) + 1);
	while (read(fd, s, BUFFER_SIZE))
	{
		i++;
		count++;
	}
	free (s);
	return (count + 1);
}*/
/*size_t	allocate_space(int fd)
{
	char	*s;

	s = malloc((BUFFER_SIZE) + 1);
	while (n > 0)
	{
		i++;
		count++;
	}
}*/
char	*get_next_line(int fd)
{
	char	*s;
	char	*s1;

	s = malloc(BUFFER_SIZE);
	while (n = read(fd, s, BUFFER_SIZE) > 0)
	{
		while (i <= BUFFER_SIZE && s[i] != '\n')
		{
			s1 = malloc (ft_strlen(s) + n )
			i++;
		}
	}
}

int main()
{
    int fd = open("prova.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
}

/*
int main ()
{
	int fd = open("prova.txt", O_RDONLY);
	printf("%zu", allocate_space(fd));
}*/