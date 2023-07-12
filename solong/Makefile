# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 14:34:51 by mcenci            #+#    #+#              #
#    Updated: 2023/07/08 17:38:11 by mcenci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MINILIBX_PATH	=	./mlx
MINILIBX		=	$(MINILIBX_PATH)/libmlx.a
LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a
PRINTF_PATH		=   ./ft_printf
PRINTF			=   $(PRINTF_PATH)/libftprintf.a
GNL_PATH		=   ./get_next_line
GNL				=   $(GNL_PATH)/get_next_line.a 

SRC				=	 ./main.c ./maps.c ./check_map.c ./check_comp.c ./graphic.c

HEADER			=	./so_long.h

OBJECTS			= 	$(SRC:%.c=%.o)

NAME			=	so_long

CC				=	gcc

RM				=	rm -f

MLX				=	./libmlx.dylib

CFLAGS			=	-Wall -Wextra -Werror

MLX_FLAGS		=	-Lmlx -lmlx -framework OpenGL -framework AppKit

all:			$(NAME)

$(NAME):	$(OBJECTS) $(LIBFT) $(PRINTF) $(GNL)
				$(CC) ${CFLAGS} -c $(SRC) -Imlx
				$(CC) $(OBJECTS) $(LIBFT) $(PRINTF) $(GNL) $(MLX_FLAGS) -o $(NAME)

$(MINILIBX):
				make -C $(MINILIBX_PATH)

$(LIBFT):
				make -C $(LIBFT_PATH)

$(PRINTF):
				make -C $(PRINTF_PATH)

$(GNL):
				make -C $(GNL_PATH)

clean:
				${RM} ${OBJECTS}
				make clean -C ${LIBFT_PATH}
				make clean -C ${PRINTF_PATH}
				make clean -C ${GNL_PATH}
				make clean -C ${MINILIBX_PATH}

fclean:			clean
					rm -f $(NAME)
					rm -f $(MINILIBX)
					rm -f $(LIBFT)
					rm -f $(PRINTF)
					rm -f $(GNL)

re:				fclean all

.PHONY:			all clean re