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

/*
	1.ler
	2.verificar tamanho
	3.verificar todo o map

	map 


*/
int	key_hook(int keycode,t_vars *vars)
{
	if(keycode == KEY_ESC)
		return (-1);
	ft_printf("Hello from key_hook!%d\n", keycode);
	return(0);
}

void	free_ptr(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
	}
}

int	ft_verify_str(char *str, char *ver, int max_search)
{
	int	a;

	a = 0;
	if (str == NULL || ver == NULL)
		return (1);
	while (*str != 0 && a <= max_search  && ft_strchr(ver, *str))
		str++ && a++;
	if(a == max_search)
		return(0);
	return(1);
}
// ok.verificar tamanho minimo 
// letras erradas
//  verify width
// remocao do \n
// verificar borda

int verify_width_map(t_map *map, char *content, int heigth_now)
{
	if (map->width < 4)
		return (1);
	if (ft_verify_str(content, "1", map->width) == 0)
	{
		if (ft_strlen(content) != map->width && heigth_now > 0)
			return (1);
		if (ft_strlen(content) - 1 != map->width && heigth_now == 0)
			return (1);
		content[map->width] = '\0';
		return(0);
	}
	else if (ft_verify_str(content, "10ECPJ", map->width) == 0)
	{	
		if (content [0] != '1' && content [map->width - 1] != '1')
			return (1);
		if (ft_strlen(content) - 1 != map->width)
			return (1);
		content[map->width] = '\0';
		return(0);
	}
	return (1);
}

int	read_map(t_map *map)
{
	t_list	*tmp;
	int		a;

	map->map = malloc(1 * sizeof(t_list *));
	tmp = malloc(1 * sizeof(t_list));
	tmp->content = get_next_line(map->fd);
	map->width = ft_strlen(tmp->content) - 1;
	map->map[0] = tmp;
	a = 0;
	while(tmp->content != NULL)
	{
		if(verify_width_map(map, (char *) tmp->content, a) == 1)
			return(1);
		tmp->next = malloc(1 * sizeof(t_list));
		tmp = tmp->next;
		tmp->content = get_next_line(map->fd);
		a++;
	}
	if(a < 4)
		return (1);
	map->height = a;
	return(0);
}


int	verify_map(char *name_map, t_map *map)
{
	map->fd = open(name_map, O_RDONLY);
	if (map->fd == -1)
	{
		perror("Error\n\033[1;31mMap doesn't exist\033[1;0m");
		return (1);
	} 
	if(read_map(map) == 1)
	{
		perror("Error\n\033[1;31mMap size wrong\033[1;0m");
		return (1);
	}
	return (0);
}
void destroy_map(t_map *map)
{
	ft_lstclear(map->map, &free_ptr);
	free(map->map);
}

int	load_sprites(t_map *map, t_vars *vars, t_data_img **sprite)
{
	int	a;

	a = 0;
	while(a < 6)
	{
		ft_printf("<%s, %p>\n", g_sprite_path[a], vars->mlx);
		sprite[a]->img = mlx_xpm_file_to_image(vars->mlx, g_sprite_path[a],
				&sprite[a]->img_width, &sprite[a]->img_height);
		// if(sprite[a]->img == NULL)
		// 	return(1);
		a++;
	}
	return(0);
}

int	start_game(t_map *map, t_vars *vars)
{
	t_data_img	**sprites;

	sprites = malloc(7 * sizeof(t_data_img *));
	sprites[6] = NULL;
	if(sprites == NULL)
		return(1);
	vars->mlx = mlx_init();
	if(vars->mlx == NULL)
		return(1);
	vars->win = mlx_new_window(vars->mlx, map->width * SPRITE_SIZE, 
								map->height * SPRITE_SIZE, "so_long");
	if(vars->win == NULL)
		return(1);
	if(load_sprites(map, vars, sprites) == 1)
		return(1);
	mlx_put_image_to_window(vars->mlx, vars->win, sprites[0]->img, 0 , 0);
	mlx_loop(vars->mlx);
	return(0);
}

int	main(int argc, char **argv)
{
	t_map		map;
	t_vars		vars;

	if(argc == 2)
	{
		if (verify_map(argv[1], &map) == 1)
		{
			destroy_map(&map);
			return(-1);
		}
		if (start_game(&map, &vars) == 1)
		{
			perror("Error\n\033[1;31mErro no start game\033[1;0m");
			return(-1);
			// g_sprite_path = "./sprites/facetattoo.xpm";
			// test2.relative_path = "./sprites/imagem.xpm";
			// vars.mlx = mlx_init();
			// vars.win = mlx_new_window(vars.mlx, 400, 400, "so_long");
			// test.img = mlx_xpm_file_to_image(vars.mlx, test.relative_path, &test.img_width, &test.img_height);
			// test2.img = mlx_xpm_file_to_image(vars.mlx, test2.relative_path, &test2.img_width, &test2.img_height);
			// mlx_put_image_to_window(vars.mlx, vars.win, test2.img, 0, 0);
			// mlx_put_image_to_window(vars.mlx, vars.win, test2.img, 100, 0);
			// mlx_put_image_to_window(vars.mlx, vars.win, test.img, 200, 0);
			// mlx_mouse_hook(vars.win, key_hook, &vars);
			// // if(error = -1)
			// 	// destroy_all(&vars, test, test2);
			// mlx_loop(vars.mlx);
		}
	}
	else
	{
		perror("Error\n\033[1;31mMap doesn't exist\033[1;0m");
		return(-1);
	}
	return (0);
}
