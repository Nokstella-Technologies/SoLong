/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:47:53 by llima-ce          #+#    #+#             */
/*   Updated: 2021/10/25 18:10:09 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *g_sprite_path[6] = {"./assets/sprites/0.xpm", "./assets/sprites/1.xpm",
"./assets/sprites/C.xpm", "./assets/sprites/E.xpm", "./assets/sprites/P.xpm",
"./assets/sprites/J.xpm"};

void	position_player(t_module *module)
{
	mlx_put_image_to_window(module->vars->mlx, module->vars->win, module->sprite[4]->img, SPRITE_SIZE * module->map->col , SPRITE_SIZE * module->map->row);
	module->player->player_x = module->map->col;
	module->player->player_y = module->map->row;
}

void	coin_print(t_module *module)
{
	module->coin->amount = module->coin->amount + 1;
	mlx_put_image_to_window(module->vars->mlx, module->vars->win, module->sprite[2]->img, SPRITE_SIZE * module->map->col , SPRITE_SIZE * module->map->row);
}

int	choose_sprite(char *line, t_module *module)
{
	if (line[module->map->col] == '0')
		mlx_put_image_to_window(module->vars->mlx, module->vars->win, module->sprite[0]->img, SPRITE_SIZE * module->map->col , SPRITE_SIZE * module->map->row);
	else if (line[module->map->col] == '1')
		mlx_put_image_to_window(module->vars->mlx, module->vars->win, module->sprite[1]->img, SPRITE_SIZE * module->map->col , SPRITE_SIZE * module->map->row);
	else if (line[module->map->col] == 'C')
		coin_print(module);
	else if (line[module->map->col] == 'E')
		mlx_put_image_to_window(module->vars->mlx, module->vars->win, module->sprite[3]->img, SPRITE_SIZE * module->map->col , SPRITE_SIZE * module->map->row);
	else if (line[module->map->col] == 'P')
	{

		position_player(module);
	}
	else if (line[module->map->col] == 'J')
		mlx_put_image_to_window(module->vars->mlx, module->vars->win, module->sprite[5]->img, SPRITE_SIZE * module->map->col ,SPRITE_SIZE * module->map->col);
	else
		return (1);
	return (0);
}

// 	typedef struct s_player{
// 	int		player_x;
// 	int		player_y;
// 	int		player_eye;
// 	int		player_step;
// 	int		player_x_old;
// 	int		player_y_old;
// }				t_player;
int	print_map(t_module *module)
{
	int	a;

	printf("ola mundo\n");
	module->map->row = 0;
	module->coin->amount  = 0;
	a = 0;
	while(module->map->row < module->map->height)
	{
		module->map->col = 0;
		while(module->map->col < module->map->width)
		{
			if(choose_sprite(, module) == 1)
				return (error(0, "It is not possible to find the sprite!"));
			module->map->col++;
		}
		tmp = tmp->next;
		module->map->row++;
	}
	return(0);
}

int	load_sprites(t_vars *vars, t_data_img **sprite)
{
	int	a;

	a = 0;
	while (a < 6)
	{
		sprite[a] = malloc(sizeof(t_data_img));
		sprite[a]->img = mlx_xpm_file_to_image(vars->mlx, g_sprite_path[a],
				&sprite[a]->img_width, &sprite[a]->img_height);
		if(sprite[a]->img == NULL)
			return (error(0, "It is not possible to load some sprites!"));
		a++;
	}
	return (0);
}

int	start_game(t_module *module)
{
	module->vars = malloc(1 * sizeof(t_vars));
	module->player = malloc(1 * sizeof(t_player));
	module->coin = malloc(1 * sizeof(t_coin));
	module->sprite = malloc(6 * sizeof(t_data_img *));
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
