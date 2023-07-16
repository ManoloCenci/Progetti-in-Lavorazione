/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:04:06 by dmarcian          #+#    #+#             */
/*   Updated: 2023/07/16 17:05:37 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_up(game *m)
{
	mlx_clear_window(m->mlx, m->window);
	get_hero(m);
	if (m->map_mtx[m->hi - 1][m->hj] == '0' ||
		m->map_mtx[m->hi - 1][m->hj] == 'C')
	{
		if (m->map_mtx[m->hi - 1][m->hj] == 'C')
			m->colect--;
		m->map_mtx[m->hi - 1][m->hj] = 'P';
		m->map_mtx[m->hi][m->hj] = '0';
	}
	else if ((m->map_mtx[m->hi - 1][m->hj] == 'E' || \
			m->map_mtx[m->hi - 1][m->hj] == 'P') && m->colect == 0)
		exit(1);
	supreme_put_image(m);
}

void move_down(game *m)
{
	mlx_clear_window(m->mlx, m->window);
	get_hero(m);
	if (m->map_mtx[m->hi + 1][m->hj] == '0' ||
		m->map_mtx[m->hi + 1][m->hj] == 'C')
	{
		if (m->map_mtx[m->hi + 1][m->hj] == 'C')
			m->colect--;
		m->map_mtx[m->hi + 1][m->hj] = 'P';
		m->map_mtx[m->hi][m->hj] = '0';
	}
	else if ((m->map_mtx[m->hi + 1][m->hj] == 'E' || \
			m->map_mtx[m->hi + 1][m->hj] == 'P') && m->colect == 0)
		exit(1);
	supreme_put_image(m);
}

void move_right(game *m)
{
	mlx_clear_window(m->mlx, m->window);
	get_hero(m);
	if (m->map_mtx[m->hi][m->hj + 1] == '0' ||
		m->map_mtx[m->hi][m->hj + 1] == 'C')
	{
		if (m->map_mtx[m->hi][m->hj + 1] == 'C')
			m->colect--;
		m->map_mtx[m->hi][m->hj + 1] = 'P';
		m->map_mtx[m->hi][m->hj] = '0';
	}
	else if ((m->map_mtx[m->hi][m->hj + 1] == 'E' || \
			m->map_mtx[m->hi][m->hj + 1] == 'P') && m->colect == 0)
		exit(1);
	supreme_put_image(m);
}

void move_left(game *m)
{
	mlx_clear_window(m->mlx, m->window);
	get_hero(m);
	if (m->map_mtx[m->hi][m->hj - 1] == '0' ||
		m->map_mtx[m->hi][m->hj - 1] == 'C')
	{
		if (m->map_mtx[m->hi][m->hj - 1] == 'C')
			m->colect--;
		m->map_mtx[m->hi][m->hj - 1] = 'P';
		m->map_mtx[m->hi][m->hj] = '0';
	}
	else if ((m->map_mtx[m->hi][m->hj - 1] == 'E' || \
			m->map_mtx[m->hi][m->hj - 1] == 'P') && m->colect == 0)
		exit(1);
	supreme_put_image(m);
}

int movement(int m, game *mtx)
{
	if (m == w || m == fu)
	{
		move_up(mtx);
		move_left_enemy(mtx);
	}

	else if (m == s || m == fg)
	{
		move_down(mtx);
		move_up_enemy(mtx);
	}
	else if (m == d || m == fd)
	{
		move_right(mtx);
		move_down_enemy(mtx);
	}
	else if (m == a || m == fs)
	{
		move_left(mtx);
		move_right_enemy(mtx);
	}
	else if (m == ESC)
		exit(1);
	return (0);
}
