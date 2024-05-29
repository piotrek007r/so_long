/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotr <piotr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:39:53 by pruszkie          #+#    #+#             */
/*   Updated: 2024/05/29 16:24:16 by piotr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_el(t_vars *vars, char *lay_path, char lay_type)
{
	int	i;

	vars->obj.addr_obj = mlx_xpm_file_to_image(vars->mlx, lay_path,
			&vars->obj.width_px, &vars->obj.height_px);
	i = 0;
	while (vars->map.line[i] != '\n' && vars->map.line[i] != '\0')
	{
		if (vars->map.line[i] == lay_type)
			mlx_put_image_to_window(vars->mlx, vars->window, vars->obj.addr_obj,
				vars->obj.width_px * (i), vars->obj.height_px
				* (vars->map.cur_line - 1));
		i++;
	}
	mlx_destroy_image(vars->mlx, vars->obj.addr_obj);
}

void	ft_draw_layer(t_vars *vars, char *lay_path, char lay_type)
{
	vars->map.width = 0;
	vars->map.fd = open(vars->path, O_RDONLY);
	if (vars->map.fd == -1)
		ft_close_app(vars);
	vars->map.cur_line = 1;
	while (1)
	{
		vars->map.line = get_next_line(vars->map.fd);
		if (!vars->map.line)
			break ;
		ft_draw_el(vars, lay_path, lay_type);
		vars->map.cur_line++;
		if (!vars->map.line)
			break ;
		else
			free(vars->map.line);
	}
	vars->map.height = vars->map.cur_line - 1;
	close(vars->map.fd);
}

void	ft_rerender_map(t_vars *vars)
{
	int	i;

	vars->map.cur_line = 1;
	i = 0;
	while (i < vars->map.height)
	{
		vars->map.line = vars->map.matrix[i];
		ft_draw_el(vars, "assets/floor.xpm", '0');
		ft_draw_el(vars, "assets/wall.xpm", '1');
		ft_draw_el(vars, "assets/coin.xpm", 'C');
		ft_draw_el(vars, "assets/dwarf.xpm", 'P');
		ft_draw_el(vars, "assets/exit.xpm", 'E');
		ft_draw_el(vars, "assets/dragon.xpm", 'G');
		vars->map.cur_line++;
		i++;
	}
}
