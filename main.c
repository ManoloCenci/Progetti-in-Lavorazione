/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:35:32 by mcenci            #+#    #+#             */
/*   Updated: 2023/07/05 18:44:04 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **argv)
{
	my_map map;
	// void *mlx;
	// void *mlx_win;
	// void *img;
	// char *relative_path = "./images/P.xpm";
	// int img_width;
	// int img_height;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Solong");
	// img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	// mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	// mlx_loop(mlx);
if (ac < 2)
{
	return 0;
}

get_map(argv[1], &map);
check_ext(argv[1]);
set_len(&map);
ft_printf("%d\n",map.colum_map);
ft_printf("%d\n",map.row_map);
check_rect(&map);
ft_printf("Se 0 mappa errata, se 1 ok! %d\n",check_wall_rows(&map));
ft_printf("Se 0 mappa errata, se 1 ok! %d\n",check_wall_column(&map));
check_pce(&map);
}
