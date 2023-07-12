/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:35:59 by mcenci            #+#    #+#             */
/*   Updated: 2023/07/03 10:36:19 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    get_map(char *argv, my_map *m)
{
  int		fd;
	char	*str;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		 ft_printf("Error, your file is empty");
            exit(1);
	}

	m->map = malloc(1);
	m->map[0] = '\0';
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		m->map = ft_strjoin(m->map, str);
		free(str);
	}
	m->map_mtx = ft_split(m->map, '\n');
	close(fd);

}
