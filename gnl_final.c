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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrossi <lgrossi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:17:55 by lgrossi           #+#    #+#             */
/*   Updated: 2023/05/03 18:22:35 by lgrossi          ###   ########.fr       */
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
		while (final[j] != 0)
				new[i++] = final[j++];
			j = 0;
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
	static char	*remind = NULL;
	int			len_read;
	char		*nl;
	size_t		x;

	buff = calloc(BUFFER_SIZE +1, 1);
	if (!buff)
		return (NULL);
	final = NULL;

	if (remind && *remind)
	{
		if ((nl = strchr(remind,'\n')))
		{
			final = gnl_breaker(final,remind);
			nl++;
			x = nl - remind;
			remind += x;
			return (final);
		}
		else
		{
			final = gnl_breaker(final,remind);
			remind = &remind[0];
			remind = "";
		}
	}
	while ((len_read = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		if ((nl = strchr(buff,'\n')))
		{
			final = gnl_breaker(final, buff);
			nl++;
			if (nl[0])
				remind = strdup(&buff[nl - buff]);
			free (buff);
			return (final);
		}
		else
			final = gnl_breaker(final, buff);
		memset(buff, 0, BUFFER_SIZE);
	}
	if (buff)
		free (buff);
	//if (remind)
	//	free (remind);
	if (final)
		return (final);
	else
		return (NULL);
}
