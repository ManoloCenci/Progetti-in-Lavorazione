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
    char    *buff;
    char    *final;
    char    *remind;
    size_t  len_final;
    size_t  len_read;
    size_t  new_line;
    size_t  i;

    new_line = 0;
    len_final = 1;
    buff = malloc(BUFFER_SIZE + 1);//                buff = |_| |_| |_| |_| |_|
    buff[BUFFER_SIZE] = 0;//                        buff = |_| |_| |_| |_| |\0|

    while{new_line == 0 && (read_len = read(fd,buff,BUFFER_SIZE) > 0)}
    {
        i = 0;
        while (buff[i] && buff[i] != '\n')
            i++;
        if (buff[i] == '\n')
        {
            new_line++;
            len_final += i + 1;
            final = malloc(len_final);
            final[len_final -1] = 0;
            remind = malloc(BUFFER_SIZE - i);
            remind[BUFFER_SIZE - i -1] = 0;
                if (final == 0)
                {
                    memcpy(final,buff, len_final);
                }
                else
                {
                    final += BUFFER_SIZE;
                    memcpy(final,buff,len_final);
                }
            memcpy(remind, &buff[i + 1], BUFFER_SIZE - i);
            printf("BUFF ora è :\n%s\n____________________\n", buff);
			printf("FINAL ora è :\n%s\n____________________\n", final);
			printf("REMIND ora è :\n%s\n\n___||_||....fine....||_||___\n \nGET_NEXT RESTITUISCE: ", remind);
        }
        else
        {
            len_final += BUFFER_SIZE;
            final = malloc(len_final);
            final[len_final - 1] = 0;
                if (final == 0);
                {
                    memcpy(final,buff,len_final);
                    final += (BUFFER_SIZE);
                }
                else
                {
                    final += BUFFER_SIZE;
                    memcpy(final,buff,len_final);
                }
        printf("BUFF ora è :%s\n____________________\n", buff);
		printf("FINAL ora è :%s\n____________________\n", final);
                
        }
    }
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