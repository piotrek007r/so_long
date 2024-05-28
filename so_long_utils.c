/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: piotr <piotr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 17:23:06 by pruszkie          #+#    #+#             */
/*   Updated: 2024/05/27 19:17:59 by piotr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_clean_matrix(t_vars *vars)
{
	int counter;

	counter = 0;
	while(counter < vars->map.height)
	{
		free(vars->map.matrix[counter]);
		counter++;
	}
	free(vars->map.matrix);
}

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_length * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(offset + img->addr)) = color;
}

void ft_close_app(t_vars *vars)
{
		ft_clean_matrix(vars);
		mlx_destroy_image(vars->mlx, vars->img.img);
		mlx_destroy_window(vars->mlx, vars->window);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(1);
		
}