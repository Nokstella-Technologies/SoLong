/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vantoniel- <vanton@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:15:35 by llima-ce          #+#    #+#             */
/*   Updated: 2021/10/18 20:50:45 by vanton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }


int	key_hook(int keycode,t_vars *vars)
{
	if(keycode == KEY_ESC)
		return (-1);
	ft_printf("Hello from key_hook!%d\n", keycode);
	return(0);
}

int	verify_map(char *name_map,t_map	*map)
{
	map->fd = open(name_map, O_RDONLY);
	if (map->fd == -1)
	{
		perror("Error\n\033[1;31mMap doesn't exist\033[1;0m");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_vars vars;
	t_data_img	test;
	t_data_img	test2;
	int error;
		// void		*addr;
	if(argc == 2)
	{
		if(verify_map(argv[1], &map) == 1)
			return(1);
		else
		{
			test.relative_path = "./sprites/facetattoo.xpm";
			test2.relative_path = "./sprites/imagem.xpm";
			vars.mlx = mlx_init();
			vars.win = mlx_new_window(vars.mlx, 400, 400, "so_long");
			test.img = mlx_xpm_file_to_image(vars.mlx, test.relative_path, &test.img_width, &test.img_height);
			test2.img = mlx_xpm_file_to_image(vars.mlx, test2.relative_path, &test2.img_width, &test2.img_height);
			mlx_put_image_to_window(vars.mlx, vars.win, test2.img, 0, 0);
			mlx_put_image_to_window(vars.mlx, vars.win, test2.img, 100, 0);
			mlx_put_image_to_window(vars.mlx, vars.win, test.img, 200, 0);
			mlx_mouse_hook(vars.win, key_hook, &vars);
			// if(error = -1)
				// destroy_all(&vars, test, test2);
			mlx_loop(vars.mlx);
		}
	}
	else
	{
		perror("Error\n\033[1;31mMap doesn't exist\033[1;0m");
		return(1);
	}
	return (0);
}


// int main(void)
// {
// 	void *mlx;
// 	void *mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 100, 100, "Face Tattoo!");
// 	img.img = mlx_new_image(mlx, 100, 100);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 10);
// 	mlx_loop(mlx);
// }
