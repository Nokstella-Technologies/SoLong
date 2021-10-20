/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafaevanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:10:52 by prafael-          #+#    #+#             */
/*   Updated: 2021/10/19 18:09:56 by prafae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <fcntl.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"

# define KEY_ESC			65307
# define KEY_A				97
# define KEY_D				100
# define KEY_S				115
# define KEY_W				119
# define SPRITE_SIZE		32

char *g_sprite_path[6] = {"./assets/sprites/0.xpm", "./assets/sprites/1.xpm",
"./assets/sprites/C.xpm", "./assets/sprites/E.xpm", "./assets/sprites/P.xpm",
"./assets/sprites/J.xpm"};

typedef struct s_map{
	t_list	**map;
	int		fd;
	int		width;
	int		height;
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


#endif
