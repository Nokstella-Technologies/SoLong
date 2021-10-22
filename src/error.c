/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llima-ce <llima-ce@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:45:38 by prafael-          #+#    #+#             */
/*   Updated: 2021/10/22 19:26:09 by llima-ce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	destroy_map(t_map *map)
{
	ft_lstclear(map->map, &free_ptr);
	free(map->map);
}

void	destroy_window(t_module *module)
{	
	int i;

	i = -1;
	while (i++ < 6)
	{
		mlx_destroy_image(module->vars->mlx, module->sprite[i]->img);
		free(module->sprite[i]);
	}
	destroy_map(module->map);
	mlx_destroy_window(module->vars->mlx, module->vars->win);
	free(module->vars);
}

void	destroy_all(t_module *module)
{
	destroy_window(module);
	mlx_loop_end(module->vars->mlx);
	free(module);
}

/*
errnum = 1 --> Operation not permitted
errnum = 2 --> No such file or directory
errnum = 3 --> No such process
errnum = 4 --> Interrupted function call
errnum = 5 --> Input/output error
errnum = 6 --> No such device or address
errnum = 7 --> Arg list too long
errnum = 8 --> Exec format error
errnum = 9 --> Bad file descriptor
errnum = 10 --> No child processes
errnum = 11 --> Resource temporarily unavailable
errnum = 12 --> Not enough space
errnum = 13 --> Permission denied
errnum = 14 --> Bad address
errnum = 15 --> Unknown error
errnum = 16 --> Resource device
errnum = 17 --> File exists
errnum = 18 --> Improper link
errnum = 19 --> No such device
errnum = 20 --> Not a directory
errnum = 21 --> Is a directory
errnum = 22 --> Invalid argument
errnum = 23 --> Too many open files in system
errnum = 24 --> Too many open files
errnum = 25 --> Inappropriate I/O control operation
errnum = 26 --> Unknown error
errnum = 27 --> File too large
errnum = 28 --> No space left on device
errnum = 29 --> Invalid seek
errnum = 30 --> Read-only file system
errnum = 31 --> Too many links
errnum = 32 --> Broken pipe
errnum = 33 --> Domain error
errnum = 34 --> Result too large
errnum = 35 --> Unknown error
errnum = 36 --> Resource deadlock avoided
errnum = 37 --> Unknown error
errnum = 38 --> Filename too long
errnum = 39 --> No locks available
*/

int	error(int errnum, char *message)
{
	if(errnum == 0 && message != NULL)
		perror(message);
	else if (errnum > 0)
		perror(strerror(errnum));
	else
		perror(strerror(26));
	return(1);
}
