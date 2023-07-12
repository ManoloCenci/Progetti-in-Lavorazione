# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcenci <mcenci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/21 12:30:46 by mcenci            #+#    #+#              #
#    Updated: 2023/04/21 12:36:12 by mcenci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a

OBJS := ft_printf.o ft_hexadecimal.o ft_putchar.o ft_putnbr.o ft_putstr.o ft_unsint.o ft_voidhex.o

FLAGS := -Wall -Werror -Wextra

all: $(NAME)

%.o : %.c
	gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	ar crs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) ${B_OBJS}

fclean: clean
	rm -f $(NAME)

re: fclean all