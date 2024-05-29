/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotr <piotr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:28:49 by pruszkie          #+#    #+#             */
/*   Updated: 2024/05/29 16:21:32 by piotr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map(t_vars *vars)
{
	ft_check_walls(vars);
	ft_check_rectangular(vars);
	ft_check_items(vars);
	ft_check_path(vars);
	ft_clean_matrix(vars);
	ft_set_matrix(vars);
	ft_count_items(vars);
}

void	ft_map_init(t_vars *vars)
{
	vars->state.move_count = 0;
	vars->map.rectangular = true;
	ft_set_matrix(vars);
	ft_check_map(vars);
	ft_draw_layer(vars, "assets/floor.xpm", '0');
	ft_draw_layer(vars, "assets/wall.xpm", '1');
	ft_draw_layer(vars, "assets/coin.xpm", 'C');
	ft_draw_layer(vars, "assets/dwarf.xpm", 'P');
	ft_draw_layer(vars, "assets/exit.xpm", 'E');
	ft_draw_layer(vars, "assets/dragon.xpm", 'G');
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

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		ft_check_args();
	vars.path = argv[1];
	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	ft_check_winsize(&vars);
	vars.window = mlx_new_window(vars.mlx, 50 * vars.map.width, 50
			* vars.map.height, "window");
	if (!vars.mlx)
	{
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
		return (1);
	}
	vars.img.img = mlx_new_image(vars.mlx, 50 * vars.map.width, 50
			* vars.map.height);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length, &vars.img.endian);
	ft_map_init(&vars);
	mlx_key_hook(vars.window, ft_action, &vars);
	mlx_hook(vars.window, 17, 0, (void *)ft_close_app, &vars);
	mlx_loop(vars.mlx);
}
