/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizz <luizz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:47:39 by llima-ce          #+#    #+#             */
/*   Updated: 2021/11/03 19:31:29 by luizz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		verify_move(t_module *module, char verify)
{
	if(verify == '0')
		return (0);
	if(verify == '1')
		return (1);
	if(verify == 'C')
	{
		module->coin->amount_taken = module->coin->amount_taken + 1;
		return(0);
	}
	if(verify == 'E')
	{
		if (module->coin->amount == 0)
			return(2);
		else
			return(1);
	}
	else
		return (3);
}

void	move(t_module *module, int x, int y, int eye)
{
	int		res;

	res = verify_move(module, module->map->map[y][x]);
	if (res == 0)
	{
		module->player->player_step = module->player->player_step + 1;
		module->player->player_eye = eye;
		module->map->map[y][x] = 'P';
		module->map->map[module->player->player_y]
			[module->player->player_x] = '0';
		print_map(module);
	}
	else if (res == 1)
		module->player->player_eye = eye;
	else if (res == 2)
	{
		ft_printf("\033[32mYOU WIN!\n\033[0");
		module->end_game = TRUE;
	}
	else if (res == 3)
	{
		ft_printf("\033[31mGAME OVER!\n\033[0");
		module->end_game = TRUE;
	}
}

int key_hook(int keycode, t_module *module)
{
	if(keycode == 113 || keycode == KEY_ESC)
		close_all(module);
	else if(module->end_game == TRUE)
		return (0);
	else if(keycode == KEY_D || keycode == KEY_RIGHT)
		move(module, module->player->player_x + 1, module->player->player_y, 3);
	else if(keycode == KEY_A || keycode == KEY_LEFT)
		move(module, module->player->player_x - 1, module->player->player_y, 2);
	else if(keycode == KEY_S || keycode == KEY_DOWN)
		move(module, module->player->player_x, module->player->player_y + 1, 1);
	else if(keycode == KEY_W || keycode == KEY_UP)
		move(module, module->player->player_x, module->player->player_y - 1, 0);
	return (0);
}
int print_steps(t_module *module)
{
	char *test;
	
	test = ft_strjoin("STEPS: ", ft_itoa(module->player->player_step));
	mlx_string_put(module->vars->mlx,module->vars->win, 11, 11,
			0x00FFFFFF, test);
	free_ptr((void **)&test);
	return (0);
}


void	hook(t_module *module)
{
	mlx_key_hook(module->vars->win, &key_hook, module);
	mlx_loop_hook(module->vars->mlx,&print_steps, module);
	mlx_hook(module->vars->win, 17, 0, &close_all, module);
	mlx_hook(module->vars->win, 9, 1L<<21, &print_map, module);
}
