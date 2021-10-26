/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:44:25 by prafael-          #+#    #+#             */
/*   Updated: 2021/10/22 17:56:560 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	key_hook(int keycode, t_vars *vars)
// {
// 	if(keycode == KEY_ESC)
// 		return (-1);
// 	ft_printf("Hello from key_hook!%d\n", keycode);
// 	return(0);
// }

int	main(int argc, char **argv)
{
	t_module	*module;

	if(argc == 2)
	{
		module = malloc(1 * sizeof(t_module));
		if(module == NULL)
			return(error(14, NULL)); 
		if (verify_map(argv[1], module) == 1)
		{
			clear_map(module->map);
			return(1);
		}
		else if (start_game(module) == 1)
			return(1);
		else if (hook(module) == 1)
			return(1);
	}
	else
		return(error(22, NULL));
	return (0);
}

// int main()
// {
// 	t_data_img	**test3;
// 	t_map		map;
// 	t_vars		*vars;
// 	// void		*mlx;

// 	vars = malloc(1 * sizeof(t_vars));
// 	test3 = malloc(7 * sizeof(t_data_img *));
// 	test3[0] = malloc(1 * sizeof(t_data_img));
// 	test3[1] = malloc(1 * sizeof(t_data_img));
// 	vars->mlx = mlx_init();
// 	printf(" ok ok \n\n\n");
// 	vars->win = mlx_new_window(vars->mlx, 400, 400, "so_long");
// 	// load_sprites(&map , mlx, test3);
// 	printf(" ok ok \n\n\n");
// 	test3[0]->img = mlx_xpm_file_to_image(vars->mlx, g_sprite_path[0], &test3[0]->img_width, &test3[0]->img_height);
// 	test3[1]->img = mlx_xpm_file_to_image(vars->mlx, g_sprite_path[1], &test3[1]->img_width, &test3[1]->img_height);
// 	mlx_put_image_to_window(vars->mlx, vars->win, test3[0]->img, 0, 0);
// 	mlx_put_image_to_window(vars->mlx, vars->win, test3[1]->img, 100, 0);
// 	mlx_put_image_to_window(vars->mlx, vars->win, test3[1]->img, 200, 0);
// 	// mlx_mouse_hook(vars.win, key_hook, &vars);
// 	// if(error = -1)
// 	// destroy_all(&vars, test, test2);
// 	mlx_loop(vars->mlx);
// 	return(0);
// }
