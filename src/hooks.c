/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:47:39 by llima-ce          #+#    #+#             */
/*   Updated: 2021/10/25 16:46:32 by llima-ce         ###   ########.fr       */
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
		if (module->coin->amount != 0)
			return(1);
		else
			return(2);
	}
	if(verify == 'J')
		return (3);
	else
		return (2);
}

void	move_d(t_module *module, int is_player)
{
	t_list	*tmp;
	int		res;

	if(is_player == 1)
	{
		module->map->col = 0;
		tmp = module->map->map[0];
		module->map->row = 0;
		while(module->map->row < module->player->player_y)
		{
			printf("%s\n", tmp->content);
			tmp = tmp->next;
			module->map->row++;
		}
		res =verify_move(module, tmp->content[module->player->player_x + 1]);
		if (res == 0)
		{
			module->player->player_step = module->player->player_step + 1;
			module->player->player_eye = 3;
			tmp->content[module->player->player_x + 1] = 'P';
			tmp->content[module->player->player_x] = '0';
			print_map(module);
		}
		else if (res == 1)
			module->player->player_eye = 3;
		else if (res == 2)
		{
			ft_printf("YOU WIN!\n");
			// destroy_all(module);
		}
		else if (res == 3)
		{
			ft_printf("GAME OVER!\n");
			// destroy_all(module);
		}
	}
}

int key_hook(int keycode, t_module *module)
{
	printf("Hello from key_hook!\n");
	if(keycode == 113)
	{
		// destroy_all(module);
		return (1);
	}
	if(keycode == KEY_D)
		move_d(module, 1);
	return(0);
}

int	hook(t_module *module)
{
	mlx_key_hook(module->vars->win, key_hook, module);
	mlx_loop(module->vars->mlx);
	return (0);
}
