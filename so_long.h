/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizz <luizz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:43:58 by prafael-          #+#    #+#             */
/*   Updated: 2021/11/03 19:27:56 by luizz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <fcntl.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <string.h>


# define GROUND "./assets/sprites/0.xpm"
# define WALL "./assets/sprites/1.xpm"
# define COLLECT "./assets/sprites/C.xpm"
# define EXIT "./assets/sprites/E.xpm"
# define PLAYER "./assets/sprites/P.xpm"
# define ENEMY "./assets/sprites/J.xpm"
# define SPRITE_SIZE		32

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_DESTROY_NOTIFY 17
# define X_EVENT_FOCUS_IN 9

# define KEY_ESC 65307
# define KEY_Q 113

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

typedef struct s_map{
	char	**map;
	int		fd;
	int		width;
	int		height;
	int		col;
	int		row;
}			t_map;

typedef struct	s_sprite {

	void	*wall;
	void	*ground;
	void	*collect;
	void	*exit;
	void	*enemies;
	void	**player;
	int		img_width;
	int		img_height;
}				t_sprite;

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
	t_player	*player;
	t_coin		*coin;
	t_sprite	*sprite;
	t_bool		end_game;
}						t_module;

void	free_ptr(void **ptr);

int		ft_verify_str(char *str, char *ver, int max_search);

int		error(int errnum, char *message);
void	clear_map(t_map *map);
void	close_window(t_module *module);
int		close_all(t_module *module);

int		verify_map(char *name_map, t_module *module);
int		start_game(t_module *module);
int		print_map(t_module *module);

void	hook(t_module *module);

#endif
