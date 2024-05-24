/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruszkie <pruszkie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:28:49 by pruszkie          #+#    #+#             */
/*   Updated: 2024/05/24 18:29:07 by pruszkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_set_matrix(t_vars *vars)
{
	int counter;

	counter = 0;
	vars->map.matrix = (char **)malloc(vars->map.height * sizeof(char *) + 1);
	vars->map.fd = open("maps/small.ber", O_RDONLY);

	while(vars->map.line = get_next_line(vars->map.fd))
	{
		vars->map.matrix[counter] = (char *)malloc(vars->map.width + 1);
		if (!vars->map.matrix[counter])
			exit (1); // to handle
		ft_strlcpy(vars->map.matrix[counter], vars->map.line, vars->map.width + 1);
		free(vars->map.line);
		counter++;
	}
	close(vars->map.fd);
}

void	ft_map_init(t_vars *vars)
{
    ft_draw_layer(vars, "assets/floor_m.xpm", '0');
    ft_set_matrix(vars);
	//ft_check_doubles() TO DO
    ft_draw_layer(vars, "assets/wall_s.xpm", '1');
    ft_draw_layer(vars, "assets/coin_s.xpm", 'C');
    ft_draw_layer(vars, "assets/player_s.xpm", 'P');
    ft_draw_layer(vars, "assets/exit_s.xpm", 'E');
}

void ft_move_up(t_vars *vars)
{
	printf("display pos: %d / %d\n", vars->state.pos_x, vars->state.pos_y);

	for(int i = 0; i < vars->map.height; i++)
		printf("%s\n", vars->map.matrix[i]);

	//printf("print value of coords %c \n", vars->map.matrix[3][1]);
}

int	ft_action(int keys, t_vars *vars)
{
	if (keys == XK_w)
		ft_move_up(vars);
	if (keys == XK_Escape)
	{
		ft_clean_matrix(vars);
		mlx_destroy_image(vars->mlx, vars->img.img);
		mlx_destroy_window(vars->mlx, vars->window);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(1);
	}
	return (1);
}


int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.window = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "window");
	if (!vars.mlx)
	{
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
		return (1);
	}
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length,
										&vars.img.endian); // to free
	ft_map_init(&vars);
	mlx_key_hook(vars.window, ft_action, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.window);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
}

/*
Remember:

to clean matrix
*/
