/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:43:58 by prafael-          #+#    #+#             */
/*   Updated: 2021/10/25 16:47:41 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <fcntl.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <string.h>

# define KEY_ESC			113
# define KEY_A				97
# define KEY_D				100
# define KEY_S				115
# define KEY_W				119
# define SPRITE_SIZE		32

typedef struct s_map{
	t_list	**map;
	int		fd;
	int		width;
	int		height;
	int		col;
	int		row;
}			t_map;

typedef struct	s_data_img {
	void	*img;
	int		img_width;
	int		img_height;
}				t_data_img;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_coin{
	int		amount;
	int		amount_taken;
}				t_coin;

typedef struct s_player{
	int		player_x;
	int		player_y;
	int		player_eye;
	int		player_step;
}				t_player;

typedef struct			s_module {
	t_vars		*vars;
	t_map		*map;
	t_player		*player;
	t_coin		*coin;
	t_data_img	**sprite;
}						t_module;





void	free_ptr(void *ptr);

int		ft_verify_str(char *str, char *ver, int max_search);

void	destroy_map(t_map *map);
void	destroy_window(t_module *module);
void	destroy_all(t_module *module);

int		start_game(t_module *module);
int		print_map(t_module *module);
int		error(int errnum, char *message);

int		verify_map(char *name_map, t_module *module);

int		hook(t_module *module);

void	position_player(t_module *module);

void	coin_print(t_module *module);
#endif
