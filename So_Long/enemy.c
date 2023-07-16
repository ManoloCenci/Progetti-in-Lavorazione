/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 17:54:46 by dmarcian          #+#    #+#             */
/*   Updated: 2023/07/16 17:00:12 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void get_enemy(game *m)
{
	int i;
	int j;

	i = 0;
	while (m->map_mtx[i])
	{
		j = 0;
		while (m->map_mtx[i][j])
		{
			if (m->map_mtx[i][j] == 'N')
			{
				m->ei = i;
				m->ej = j;
				break;
			}
			j++;
		}
		i++;
	}
}

void	move_up_enemy(game *m)
{
	mlx_clear_window(m->mlx, m->window);
	get_enemy(m);
	if (m->map_mtx[m->ei - 1][m->ej] == '0')
	{
		m->map_mtx[m->ei - 1][m->ej] = 'N';
		m->map_mtx[m->ei][m->ej] = '0';
	}
	else if (m->map_mtx[m->ei - 1][m->ej] == 'P')
		exit(1);
	supreme_put_image(m);
}

void	move_down_enemy(game *m)
{
	mlx_clear_window(m->mlx, m->window);
	get_enemy(m);
	if (m->map_mtx[m->ei + 1][m->ej] == '0')
	{
		m->map_mtx[m->ei + 1][m->ej] = 'N';
		m->map_mtx[m->ei][m->ej] = '0';
	}
	else if (m->map_mtx[m->ei + 1][m->ej] == 'P')
		exit(1);
	supreme_put_image(m);
}

void	move_right_enemy(game *m)
{
	mlx_clear_window(m->mlx, m->window);
	get_enemy(m);
	if (m->map_mtx[m->ei][m->ej + 1] == '0')
	{
		m->map_mtx[m->ei][m->ej + 1] = 'N';
		m->map_mtx[m->ei][m->ej] = '0';
	}
	else if (m->map_mtx[m->ei][m->ej + 1] == 'P')
		exit(1);
	supreme_put_image(m);
}

void	move_left_enemy(game *m)
{
	mlx_clear_window(m->mlx, m->window);
	get_enemy(m);
	if (m->map_mtx[m->ei][m->ej - 1] == '0')
	{
		m->map_mtx[m->ei][m->ej - 1] = 'N';
		m->map_mtx[m->ei][m->ej] = '0';
	}
	else if (m->map_mtx[m->ei][m->ej - 1] == 'P')
		exit(1);
	supreme_put_image(m);
}


