/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:58:32 by mcenci            #+#    #+#             */
/*   Updated: 2023/07/16 16:56:11 by mcenci           ###   ########.fr       */
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

typedef struct t_img
{
     int row_map;
    int colum_map;
    char *map;
    char    **map_mtx;
    int size;
    void *wall;
    void *wall2;
    void *empty;
    void *hero;
    void *collector;
    void *enemy;
    void *out;
    void *mlx;
    void *window;
    int hi;
    int hj;
    int ei;
    int ej;
    int colect;

} game;

typedef enum tast {

    w = 13,
    s = 1,
    a = 0,
    d = 2,
    fu = 126,
    fg = 125,
    fd = 124,
    fs = 123,
    ESC = 53
} key_move;


int main(int ac, char **argv);
void    get_map(char *argv, game *m);
int check_rect(game *mtx);
int check_ext(char *name);
int count(char *s);
int set_len(game *mtx);
int check_only(char *s, char c);
int check_wall_rows(game *map);
int count_comp(char **str, char ctr);
int check_pce(game *map);
int supreme_check(game *map, char *name);
int check_correct_comp(game *map);
void	put_image(game *img);
void	put_image2(game *img);
void	supreme_put_image(game *img);
void	assign_img(game *img);
void	create_win(game *img);
void move_up(game *m);
int movement(int m, game *mtx );
void get_hero(game *m);
void move_down(game *m);
void move_right(game *m);
void move_left(game *m);
void get_collector(game *m);
void get_enemy(game *m);
void	move_up_enemy(game *m);
void	move_down_enemy(game *m);
void	move_right_enemy(game *m);
void	move_left_enemy(game *m);
#endif
