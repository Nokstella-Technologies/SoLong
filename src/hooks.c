/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:47:39 by llima-ce          #+#    #+#             */
/*   Updated: 2021/10/22 20:00:19 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move(t_module *module, int l)
{
	t_list *tmp;

	module->map->col = 0;
	tmp = module->map->map[0];
	module->map->row = 0;
	while(module->map->row <= module->player->player_y)
	{
		tmp = tmp->next;
		module->map->row++;
	}
	if(l == KEY_D)
		tmp->content[module->player->player_x]
}


int key_hook(int keycode, t_module *module)
{	
	printf("Hello from key_hook!\n");
	if(keycode == 113)
		destroy_all(module);
	if(keycode == KEY_D)
		player_move(module, keycode);
	return(0);
}

int	hook(t_module *module)
{
	mlx_key_hook(module->vars->win, key_hook, &module);
	mlx_loop(module->vars->mlx);
	return (0);
}
