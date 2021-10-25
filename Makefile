# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llima-ce <llima-ce@student.42sp.org.br     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/22 16:11:34 by prafael-          #+#    #+#              #
#    Updated: 2021/10/25 16:36:25 by llima-ce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Solong.a
CFLAGS = -Wall -Wextra -Werror
CC = clang
SRC = so_long.c error.c start_game.c utils.c verify_map.c hooks.c
OBJ = $(SRC:.c=.o)

all:
	$(CC) $(addprefix ./src/,$(SRC)) $(CFLAGS) -I . -g3 -Lmlx_Linux -lmlx_Linux -L ./minilibx -Imlx_Linux -L ./libft -lft -lXext -lX11 -lm -lz

$(OBJ):
	gcc $(CFLAGS) -I . -c $(addprefix ./src/, $(SRC))


clean:
	rm -f $(OBJ)

teste:
	./a.out "./assets/maps/map_3.ber"

# $(OBJ): $(SRC)
# 	$(CC) -Wall -Wextra -Werror -Imlx_linux -O3 -c $(SRC)