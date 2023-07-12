/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:35:32 by mcenci            #+#    #+#             */
/*   Updated: 2023/07/11 16:07:13 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <signal.h>

int main(int ac, char **argv)
{
	my_map map;
	image win;

	// char *relative_path = "./images/P.xpm";
	// int img_width;
	// int img_height;

	if (ac < 2)
		return 0;
	get_map(argv[1], &map);
	supreme_check(&map, argv[1]);
	//ft_printf("PID: %d\n", getpid());

	free(map.map);
	create_win(&map, &win);
	//assign_img(&win);
	put_image(&win, &map);
	mlx_loop(win.mlx);

}
