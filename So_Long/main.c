/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:35:32 by mcenci            #+#    #+#             */
/*   Updated: 2023/07/20 18:39:52 by mcenci           ###   ########.fr       */
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
	check_correct_comp(&mtx);
	create_win(&mtx);
	supreme_put_image(&mtx);
	mlx_key_hook(mtx.window, movement, &mtx);
	mlx_loop(mtx.mlx);
}
