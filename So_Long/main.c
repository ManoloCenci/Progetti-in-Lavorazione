/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:35:32 by mcenci            #+#    #+#             */
/*   Updated: 2023/07/16 17:10:26 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <signal.h>

int	main(int ac, char **argv)
{
	game	mtx;

	if (ac < 2)
		return (0);
	get_map(argv[1], &mtx);
	supreme_check(&mtx, argv[1]);
	//free(mtx.map);
	create_win(&mtx);
	supreme_put_image(&mtx);
	mlx_key_hook(mtx.window, movement, &mtx);
	mlx_loop(mtx.mlx);
}
