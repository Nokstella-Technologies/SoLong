# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luizz <luizz@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 16:11:34 by prafael-          #+#    #+#              #
#    Updated: 2021/11/03 14:56:51 by luizz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Solong.a
CFLAGS = -Wall -Wextra -Werror
CC = gcc
SRC = so_long.c error.c start_game.c utils.c verify_map.c hooks.c print_map.c
OBJ = $(SRC:.c=.o)

all:
	$(CC) $(addprefix ./src/,$(SRC)) $(CFLAGS) -I . -g3 -Lmlx_Linux -lmlx_Linux -L ./minilibx -Imlx_Linux -L ./libft -lft -lXext -lX11 -lm -lz

$(OBJ):
	gcc $(CFLAGS) -I . -c $(addprefix ./src/, $(SRC))


clean:
	rm -f $(OBJ)

teste: all
	./a.out "./assets/maps/map_3.ber"

valgrind: all
	valgrind --track-origins=yes  --leak-check=full   ./a.out "./assets/maps/map_2.ber" 
# $(OBJ): $(SRC)
# 	$(CC) -Wall -Wextra -Werror -Imlx_linux -O3 -c $(SRC)
