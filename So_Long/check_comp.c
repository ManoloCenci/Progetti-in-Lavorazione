/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:31:16 by mcenci            #+#    #+#             */
/*   Updated: 2023/07/20 18:40:04 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_only(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			return (0);
		i++;
	}
	return (1);
}

int	check_wall_rows(game *map)
{
	int	i;

	i = 1;
	if ((!check_only(map->map_mtx[0], '1')) || \
		(!check_only(map->map_mtx[map->row_map - 1], '1')))
		return (0);
	while ((map->map_mtx[i]) && (i < map->row_map))
	{
		if ((map->map_mtx[i][0] != '1') || \
			(map->map_mtx[i][map->colum_map - 1] != '1'))
			return (0);
		i++;
	}
	return (1);
}

// int	check_correct_comp(game *map)
// {
// 	int	i;

// 	i = 0;
// 	while (map->map[i])
// 	{
// 		if (map->map[i] != 'P' && map->map[i] != 'C' && \
// 			map->map[i] != 'E' && map->map[i] != 'N' && \
// 			map->map[i] != '1' && map->map[i] != '0' && \
// 			map->map[i] != '\n')
// 			// {
// 				// ft_printf("I componenti della tua mappa non sono corretti!");
// 				// exit(1);
// 				return(0);
// 			// }
// 		i++;
// 	}
// 	return (1);
// }
int	check_correct_comp(game *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map_mtx[i] != NULL)
	{
		while (map->map_mtx[i][j])
		{
			if (map->map_mtx[i][j] != 'P' && map->map_mtx[i][j] != 'C' && \
				map->map_mtx[i][j] != 'E' && map->map_mtx[i][j] != 'N' && \
				map->map_mtx[i][j] != '1' && map->map_mtx[i][j] != '0' && \
				map->map_mtx[i][j] != '\n')
				{
					ft_printf("Puoi usare solo P, C, E, N, 0 o 1");
					exit(1);
				}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	count_comp(char **str, char ctr)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	j = 0;
	count = 0;
	while (str[i] != NULL)
	{
		while (str[i][j])
		{
			if (str[i][j] == ctr)
				++count;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

int	check_pce(game *map)
{
	int	i;

	i = 0;
	while (map->map_mtx[i] != NULL)
	{
		if (count_comp(map->map_mtx, 'P') <= 0)
			return (0);
		else if (count_comp(map->map_mtx, 'E') <= 0)
			return (0);
		else if (count_comp(map->map_mtx, 'C') <= 0)
			return (0);
		i++;
	}
	return (1);
}
