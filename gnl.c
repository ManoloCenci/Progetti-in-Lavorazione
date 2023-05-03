/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenzogrossi <lorenzogrossi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:22:23 by lorenzogros       #+#    #+#             */
/*   Updated: 2023/05/03 13:40:58 by lorenzogros      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

char	*gnl_breaker(char	*final, char	*buff)
{
	char	*new;
	int		size;
	char	*nl;
	int		i;
	int		j;

	j = 0;
	nl = NULL;
	i = 0;	
	if (final != NULL)//								FINAL GIA ESISTE.. CONCATENAZIONE
	{
		if ((nl = strchr(buff,'\n')))//									SE FINAL ESISTE E BUFF CONTIENE nl
			size = strlen(final) + (nl - buff + 1);
		else//															SE FINAL ESISTE MA BUFF NON CONTIENE NL
			size = strlen(final) + strlen (buff);
		new = calloc(size + 1, 1);
		if (!new)
			return (NULL);
		if (final != NULL)
		{
			while (final[j] != 0)
				new[i++] = final[j++];
			j = 0;
		}
		while (buff[j] != 0 && buff[j] != '\n')
			new[i++] = buff[j++];
		if (buff[j] == '\n')
			new[i++] = buff[j++];
		free (final);
	}
	else//												SE FINAL NON ESISTE.. COPIA
	{
		if ((nl = strchr(buff,'\n')))//								FINAL NON ESISTE E BUFF CONTIENE NL
			size = nl - buff + 1;
		else//														FINAL NON ESISTE E BUFF NON CONTIENE NL
			size = strlen (buff);
		new = calloc (size + 1, 1);
		while (buff[j] != 0 && buff[j] != '\n')
			new[i++] = buff[j++];
		if (buff[j] == '\n')
			new[i++] = buff[j++];
	}
	return (new);
}

char	*get_next_line(int fd)
{
	char		*final;
	char		*buff;
	static char	*remind;
	int			len_read;
	char		*nl;
	
	buff = calloc(BUFFER_SIZE +1, 1);
	remind = NULL;
	if (!buff)
		return (NULL);
	final = NULL;
	
	if (remind)
	{
		if ((nl = strchr(remind,'\n')))
		{
			final = gnl_breaker(final,remind);
			remind = nl++;
			return (final);
		}
		else
		{
			final = gnl_breaker(final,remind);
			remind = &remind[0];
			free (remind);
		}
	}
	while ((len_read = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		if ((nl = strchr(buff,'\n')))
		{
			final = gnl_breaker(final, buff);
			if (*nl++)
				remind = gnl_breaker(remind,&buff[nl - buff]);
			free (buff);
			return (final);
		}
		else
			final = gnl_breaker(final, buff);
		memset(buff, 0, BUFFER_SIZE);
	}
	free (buff);
	if (remind != NULL)
		free (remind);
	if (final)
		return (final);
	else
		return (NULL);
}

/*int main()
{
    int fd;
    char *line;

    fd = open("43_no_nl", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return (0);
}*/
