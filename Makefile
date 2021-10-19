# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 23:09:37 by prafael-          #+#    #+#              #
#    Updated: 2021/10/18 23:20:07 by llima-ce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

prfal-prafae1prafaeNAME = Solong.a
CFLAGS = -Wall -Wextra -Werror
CC = clang
SRC = main.c
OBJ =(SRC:.c=.o)

all: $(NAME)


$(NAME): 
	$(CC) $(SRC) -Lmlx_Linux -lmlx_Linux -L ./minilibx -Imlx_Linux -L ./libft -lft -lXext -lX11 -lm -lz 

# $(OBJ): $(SRC)
# 	$(CC) -Wall -Wextra -Werror -Imlx_linux -O3 -c $(SRC)
