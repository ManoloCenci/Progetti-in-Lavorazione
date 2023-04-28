/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrossi <lgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:22:18 by lgrossi           #+#    #+#             */
/*   Updated: 2023/04/28 18:09:00 by lgrossi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

char	*ft_strjoin(char  *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(strlen(s1) + strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char			*buff;
	static char		*remind;
	char			*final;
	int				len_read;
	char			*n_chr;
	int				nn_chr;
	char 			*temp;
	int j = 0;
	final = "";
	buff = calloc(BUFFER_SIZE +1 ,1);
	if (!buff)
		return (NULL);
	if (remind)
	{
		final = remind;
		remind = NULL;
	}
	while((len_read = read(fd, buff,BUFFER_SIZE)) > 0)
	{
		if ((n_chr = strchr(buff,'\n')))
		{
			nn_chr = n_chr - buff;
			if(nn_chr < BUFFER_SIZE - 1 && buff[nn_chr + 1])
			{
			remind = calloc (BUFFER_SIZE - nn_chr, 1);
			if (!remind)
				return (NULL);
			memcpy(remind, &buff[nn_chr + 1], BUFFER_SIZE - (nn_chr + 1));
			}
			if(!strncat(final, buff, nn_chr + 1))
				return NULL;
			if (buff)
				free (buff);
			return (final);

		}
		else
		{
			if(j > 0)
				temp = final;
			final = ft_strjoin(final,buff);
			if (j > 0)
				free (temp);
		}
		if (buff){
		free (buff);
		buff = calloc(BUFFER_SIZE +1 ,1);
		if(!buff)
			return NULL;
			j++;
		}
	}
	if (buff)
		free (buff);
	if (remind)
		free (remind);
	if (*final)
		return (final);
	return (NULL);
}

/*int main()
{
    int fd = open("prova.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
}*/
