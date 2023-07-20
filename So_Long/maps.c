/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:35:59 by mcenci            #+#    #+#             */
/*   Updated: 2023/07/20 19:32:04 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_map(char *argv, game *m)
{
	int		fd;
	char	*str;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Errore, non esiste o é vuoto!");
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
	free(str);
	m->map_mtx = ft_split(m->map, '\n');
	close(fd);
	get_hero(m);
	get_collector(m);
	get_enemy(m);
}

void	get_hero(game *m)
{
	int	i;
	int	j;

	i = 0;
	while (m->map_mtx[i])
	{
		j = 0;
		while (m->map_mtx[i][j])
		{
			if (m->map_mtx[i][j] == 'P')
			{
				m->hi = i;
				m->hj = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	get_collector(game *m)
{
	int	i;
	int	j;

	i = 0;
	m->colect = 0;
	while (m->map_mtx[i])
	{
		j = 0;
		while (m->map_mtx[i][j])
		{
			if (m->map_mtx[i][j] == 'C')
				m->colect++;
			j++;
		}
		i++;
	}
}
