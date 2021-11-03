/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizz <luizz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:47:39 by llima-ce          #+#    #+#             */
/*   Updated: 2021/11/03 17:10:34 by luizz            ###   ########.fr       */
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
		ft_printf("YOU WIN!\n");
	}
	else if (res == 3)
	{
		ft_printf("GAME OVER!\n");
		close_all(module);
	}
}

int key_hook(int keycode, t_module *module)
{
	printf("%d keycode\n", keycode);
	if(keycode == 113 || keycode == KEY_ESC)
	{
		ft_printf("GAME OVER!\n");
		close_all(module);
	}
	if(keycode == KEY_D || keycode == KEY_RIGHT)
		move(module, module->player->player_x + 1, module->player->player_y, 3);
	if(keycode == KEY_A || keycode == KEY_LEFT)
		move(module, module->player->player_x - 1, module->player->player_y, 2);
	if(keycode == KEY_S || keycode == KEY_DOWN)
		move(module, module->player->player_x, module->player->player_y + 1, 1);
	if(keycode == KEY_W || keycode == KEY_UP)
		move(module, module->player->player_x, module->player->player_y - 1, 0);
	return (0);
}

void	hook(t_module *module)
{
	mlx_key_hook(module->vars->win, &key_hook, module);
	mlx_hook(module->vars->win, 17, 0, &close_all, module);
	mlx_hook(module->vars->win, 9, 1L<<21, &print_map, module);
}
