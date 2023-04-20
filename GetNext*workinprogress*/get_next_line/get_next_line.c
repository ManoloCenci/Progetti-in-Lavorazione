/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogrossi <lorenzogrossi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:41:40 by lorenzogros       #+#    #+#             */
/*   Updated: 2023/04/20 12:20:20 by lorenzogros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

char	*get_next_line(int fd)
{
	char		*buff;
	char		*final;
	static char	*remind;
	size_t	i;
	size_t read_len;

	buff = malloc(BUFFER_SIZE + 1);
	buff[BUFFER_SIZE] = 0;
	final = malloc(BUFFER_SIZE + 1);
	final[BUFFER_SIZE] = 0;
	if (remind)
		final = strdup(remind);
	while (!strchr(buff,'\n') && (read_len = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		i = 0;
		while (buff[i] && buff[i] != '\n')
			i++;
		if (buff[i] == '\n')
		{
			strncat(final, buff, i);
			
			remind = (char *)malloc(BUFFER_SIZE - i);
			strncpy(remind, &buff[i + 1], BUFFER_SIZE - i);
			printf("BUFF ora è :\n%s\n____________________\n", buff);
			printf("FINAL ora è :\n%s\n____________________\n", final);
			printf("REMIND ora è :\n%s\n\n___||_||....fine....||_||___\n \nGET_NEXT RESTITUISCE: ", remind);
		}
		else
		{
			strcat(final, buff);
			printf("BUFF ora è :%s\n____________________\n", buff);
			printf("FINAL ora è :%s\n____________________\n", final);
		}
		if (read_len < BUFFER_SIZE)
        {
            free(buff);
            return (final);
        }
	}
	free (buff);
	free (remind);
	return (final);
}
int main()
{
    int fd = open("provaprova.txt", O_RDONLY);
    char *line;

    if ((line = get_next_line(fd)))
    {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
}
