/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prafael- <prafaevanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:10:52 by prafael-          #+#    #+#             */
/*   Updated: 2021/10/18 23:11:244 by prafae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <fcntl.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"

# define KEY_ESC	65307
# define KEY_A		97
# define KEY_D		100
# define KEY_S		115
# define KEY_W		119

typedef struct s_map{
	int		fd;
	int		width;
	int		height;
}			t_map;

typedef struct	s_data_img {
	void	*img;
	void	*relative_path;
	int		img_width;
	int		img_height;

}				t_data_img;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;


#endif
