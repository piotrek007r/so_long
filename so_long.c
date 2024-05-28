/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruszkie <pruszkie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:28:49 by pruszkie          #+#    #+#             */
/*   Updated: 2024/05/28 16:43:10 by pruszkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_count_items(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map.height)
	{
		j = 0;
		while (j < vars->map.width)
		{
			if (vars->map.matrix[i][j] == 'C')
				vars->state.collectible++;
			if (vars->map.matrix[i][j] == 'E')
				vars->state.exit++;
			if (vars->map.matrix[i][j] == 'P')
				vars->state.player++;
			j++;
		}
		i++;
	}
}

void	ft_check_walls(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map.height)
	{
		j = 0;
		while (j < vars->map.width)
		{
			if ((vars->map.matrix[0][j] != '1')
				|| vars->map.matrix[vars->map.height - 1][j] != '1'
				|| vars->map.matrix[i][0] != '1'
				|| vars->map.matrix[i][vars->map.width - 1] != '1')
			{
				ft_printf("Error\nMap is not surrounded by walls!\n");
				ft_close_app(vars);
			}
			j++;
		}
		i++;
	}
}

void	ft_check_rectangular(t_vars *vars)
{
	if (vars->map.rectangular == false)
	{
		ft_printf("Error\nMap is not rectangular\n");
		ft_close_app(vars);
	}
}

void	ft_check_items(t_vars *vars)
{
	vars->state.collectible = 0;
	vars->state.player = 0;
	vars->state.exit = 0;
	ft_count_items(vars);
	if (vars->state.player < 1)
		ft_printf("Error\nNo starting position on map!\n");
	if (vars->state.player > 1)
		ft_printf("Error\nMultiple starting position on map!\n");
	if (vars->state.exit < 1)
		ft_printf("Error\nNo exit position on map!\n");
	if (vars->state.exit > 1)
		ft_printf("Error\nMultiple exit position on map!\n");
	if (vars->state.collectible < 1)
		ft_printf("Error\nNo collectibles on map!\n");
	if (vars->state.player < 1 || vars->state.player > 1 || vars->state.exit < 1
		|| vars->state.exit > 1 || vars->state.collectible < 1)
		ft_close_app(vars);
}

void	ft_check_map(t_vars *vars)
{
	ft_check_walls(vars);
	ft_check_rectangular(vars);
	ft_check_items(vars);
	// ft_check_path(vars);
}

void	ft_map_init(t_vars *vars)
{
	vars->state.move_count = 0;
	vars->map.rectangular = true;
	ft_draw_layer(vars, "assets/floor_m.xpm", '0');
	ft_set_matrix(vars);
	ft_draw_layer(vars, "assets/wall_s.xpm", '1');
	ft_draw_layer(vars, "assets/coin_s.xpm", 'C');
	ft_draw_layer(vars, "assets/player_s.xpm", 'P');
	ft_draw_layer(vars, "assets/exit_s.xpm", 'E');
	ft_check_map(vars);
}

int	ft_action(int keys, t_vars *vars)
{
	if (keys == XK_w)
		ft_move(vars, 'w');
	if (keys == XK_s)
		ft_move(vars, 's');
	if (keys == XK_a)
		ft_move(vars, 'a');
	if (keys == XK_d)
		ft_move(vars, 'd');
	if (keys == XK_Escape)
		ft_close_app(vars);
	return (1);
}

	void ft_check_winsize(t_vars *vars)
	{
		int counter;

		vars->map.width = 0;
		vars->map.height = 0;

		vars->map.fd = open(vars->path, O_RDONLY);
		counter = 0;
		while(1)
		{
			vars->map.line = get_next_line(vars->map.fd);
			if(!vars->map.line)
				break;
			vars->map.width = ft_strlen(vars->map.line) - 1;
			counter++;
		}
		vars->map.height = counter;
		close(vars->map.fd);
	}

	void ft_check_args()
	{
		ft_printf("Error\nInawalid number of arguments!");
		exit(1);
	}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if(argc != 2)
		ft_check_args();
	vars.path = argv[1];
	printf("%s\n", vars.path);
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	ft_check_winsize(&vars);
	vars.window = mlx_new_window(vars.mlx, 60 * vars.map.width, 60 * vars.map.height, "window");
	if (!vars.mlx)
	{
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
		return (1);
	}

	vars.img.img = mlx_new_image(vars.mlx, 60 * vars.map.width, 60 * vars.map.height);
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
