/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:58:32 by mcenci            #+#    #+#             */
/*   Updated: 2023/07/11 16:07:30 by mcenci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "mlx/mlx.h"
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>


typedef struct the_map
{
    int row_map;
    int colum_map;
    char *map;
    char    **map_mtx;

} my_map;

typedef struct t_img
{
    int size;
    void *wall;
    void *empty;
    void *hero;
    void *collector;
    void *enemy;
    void *out;
    void *mlx;
    void *window;
} image;



int main(int ac, char **argv);
void    get_map(char *argv, my_map *m);
int check_rect(my_map *mtx);
int check_ext(char *name);
int count(char *s);
int set_len(my_map *mtx);
int check_only(char *s, char c);
int check_wall_rows(my_map *map);
int count_comp(char **str, char ctr);
int check_pce(my_map *map);
int supreme_check(my_map *map, char *name);
int check_correct_comp(my_map *map);
void	put_image(image *img, my_map *map);
void	assign_img(image *img);
void	create_win(my_map *map, image *img);

#endif
