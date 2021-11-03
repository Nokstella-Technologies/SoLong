/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luizz <luizz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:47:53 by llima-ce          #+#    #+#             */
/*   Updated: 2021/11/03 15:03:21 by luizz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*img_initalize(char *img,void *mlx, t_sprite *sprite)
{
	void	*img_ptr;

	img_ptr = mlx_xpm_file_to_image
		(mlx, img, &sprite->img_width, &sprite->img_height);
	return (img_ptr);
}

int	load_sprites(t_vars *vars, t_sprite *sprite)
{
	sprite->wall = img_initalize(WALL, vars->mlx, sprite);
	sprite->ground = img_initalize(GROUND, vars->mlx, sprite);
	sprite->collect = img_initalize(COLLECT, vars->mlx, sprite);
	sprite->enemies = img_initalize(ENEMY, vars->mlx, sprite);
	sprite->exit = img_initalize(EXIT, vars->mlx, sprite);
	sprite->player = malloc(4 * sizeof(void *));
	if (sprite->player == NULL)
		return (error(14, NULL));
	sprite->player[0] = img_initalize(PLAYER, vars->mlx, sprite);
	return (0);
}

int	start_game(t_module *module)
{
	module->vars = malloc(1 * sizeof(t_vars));
	module->player = malloc(1 * sizeof(t_player));
	module->coin = malloc(1 * sizeof(t_coin));
	module->sprite = malloc(6 * sizeof(t_sprite));
	if (module->sprite == NULL || module->vars == NULL
	|| module->player == NULL || module->coin == NULL)
		return (error(14, NULL));
	module->vars->mlx = mlx_init();
	if (module->vars->mlx == NULL)
		return (error(0, "It is not possible to start the game!"));
	module->vars->win = mlx_new_window(module->vars->mlx, module->map->width * SPRITE_SIZE, module->map->height * SPRITE_SIZE, "so_long");
	if (module->vars->win == NULL)
		return (error(0, "It is not possible to open the window of the game!"));
	if (load_sprites(module->vars, module->sprite) == 1)
		return (1);
	if (print_map(module) == 1)
		return (1);
	return(0);
}
