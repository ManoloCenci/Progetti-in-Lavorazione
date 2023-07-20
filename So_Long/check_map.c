/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:35:01 by mcenci            #+#    #+#             */
/*   Updated: 2023/07/20 19:30:18 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	set_len(game *mtx)
{
	int	i;
	int	j;

	i = 0;
	while (mtx->map_mtx[i] != '\0')
	{
		j = 0;
		while (mtx->map_mtx[i][j] != '\0')
			j++;
		i++;
	}
	if (j < 3)
		return (0);
	mtx->colum_map = j;
	mtx->row_map = i;
	return (1);
}

int	check_rect(game *mtx)
{
	size_t	len;
	int		ctr;

	len = ft_strlen(mtx->map_mtx[0]);
	if (len < 4)
		return (0);
	ctr = 1;
	while (mtx->map_mtx[ctr])
	{
		if (ft_strlen(mtx->map_mtx[ctr]) != len)
			return (0);
		ctr++;
	}
	set_len(mtx);
	return (1);
}

int	count(char *s)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (s[i])
	{
		if (s[i] == '.')
			x++;
		i++;
	}
	return (x);
}

int	check_ext(char *name)
{
	int	i;
	int	x;

	x = count(name);
	i = ft_strlen(name);
	if (i < 5 || (x != 1))
		return (0);
	else if ((name[i - 1] != 'r') || (name[i - 2] != 'e') \
		|| (name[i - 3] != 'b') || (name[i - 4] != '.'))
		return (0);
	return (1);
}

int	supreme_check(game *map, char *name)
{
	if (!check_ext(name))
	{
		ft_printf("Errore, la tua mappa non é .ber!");
		exit(1);
	}
	else if (!check_rect(map))
	{
		ft_printf("Errore, la forma della tua mappa non é valida!");
		exit(1);
	}
	else if (!check_wall_rows(map))
	{
		ft_printf("Errore, la tua mappa non é chiusa da muri!");
		exit(1);
	}
	 else if (!check_pce(map))
	 {
	 	ft_printf("Ti manca uno fra P, C o E!");
	 	exit(1);
	 }
	else
		return (1);
}
