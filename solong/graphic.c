/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:16:39 by mcenci            #+#    #+#             */
/*   Updated: 2023/07/12 15:28:33 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	quit(void)
{
	exit(0);
}

void	create_win(my_map *map, image *img)
{
	int i;

	i = 0;
	while (map->map_mtx[i])
		i++;
	img->mlx = mlx_init();
	img->window = mlx_new_window(img->mlx, (64 * ft_strlen(map->map_mtx[0])), (64 * (i) + 64), "so_long");
	mlx_hook(img->window, 17, 0, quit, 0);
	mlx_hook(img->window, 2, 0, quit, 0);

}
void	assign_img(image *img)
{
	img->wall = mlx_xpm_file_to_image(img->mlx, "./images/wall.xpm", &img->size, &img->size);
	img->collector = mlx_xpm_file_to_image(img->mlx, "./images/Collection.xpm", &img->size, &img->size);
	img->hero = mlx_xpm_file_to_image(img->mlx, "./images/P.xpm", &img->size, &img->size);
	img->out = mlx_xpm_file_to_image(img->mlx, "./images/Turtle_60_60.xpm", &img->size, &img->size);
	img->empty = mlx_xpm_file_to_image(img->mlx, "./images/empty.xpm", &img->size, &img->size);
	img->enemy = mlx_xpm_file_to_image(img->mlx, "./images/Rino_64_64.xpm", &img->size, &img->size);
}

void	put_image(image *img, my_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	assign_img(img);
	while (map->map_mtx[i] != NULL)
	{
		while (map->map_mtx[i][j])
		{
			if (map->map_mtx[i][j] == '1')
				mlx_put_image_to_window(img->mlx, img->window, img->wall, j * 64 , i * 64);
			else if (map->map_mtx[i][j] == '0')
				mlx_put_image_to_window(img->mlx, img->window, img->empty, j * 64, i * 64);
			else if (map->map_mtx[i][j] == 'P')
				mlx_put_image_to_window(img->mlx, img->window, img->hero, j * 64, i * 64);
			else if (map->map_mtx[i][j] == 'E')
				mlx_put_image_to_window(img->mlx, img->window, img->out, j * 64, i * 64);
			else if (map->map_mtx[i][j] == 'C')
				mlx_put_image_to_window(img->mlx, img->window, img->collector, j * 64, i * 64);
			else if (map->map_mtx[i][j] == 'N')
				mlx_put_image_to_window(img->mlx, img->window, img->enemy, j * 64, i * 64);
			j++;
		}
		j = 0;
		i++;
	}
}
