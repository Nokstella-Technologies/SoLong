/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafael-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:43:58 by prafael-          #+#    #+#             */
/*   Updated: 2021/10/22 16:32:09 by prafael-         ###   ########.fr       */
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

typedef struct	s_module {
	t_vars		*vars;
	t_map		*map;
	t_data_img	**sprite;
}				t_module;

void	free_ptr(void *ptr);

int		ft_verify_str(char *str, char *ver, int max_search);

void	destroy_map(t_map *map);

int		start_game(t_module *module);

int		error(int errnum, char *message);

int		verify_map(char *name_map, t_module *module);

#endif
