#include "so_long.h"

void	ft_move(t_vars *vars, char key)
{
	char	dir;

	dir = ft_set_direction(vars, key);
	if (dir == '1')
		return ;
	else if (dir == '0')
		ft_update_matrix(vars, key);
	else if (dir == 'C')
	{
		vars->state.collectible--;
		ft_update_matrix(vars, key);
	}
	else if (dir == 'E' && vars->state.collectible == 0)
		ft_close_app(vars);
	else if (dir == 'G')
		ft_close_app(vars);
	ft_rerender_map(vars);
	vars->state.move_count++;
	ft_render_moves(vars);
}

char	ft_set_direction(t_vars *vars, char key)
{
	char	c;

	if (key == 'w')
		c = vars->map.matrix[vars->state.pos_y - 1][vars->state.pos_x];
	if (key == 's')
		c = vars->map.matrix[vars->state.pos_y + 1][vars->state.pos_x];
	if (key == 'a')
		c = vars->map.matrix[vars->state.pos_y][vars->state.pos_x - 1];
	if (key == 'd')
		c = vars->map.matrix[vars->state.pos_y][vars->state.pos_x + 1];
	return (c);
}

void	ft_render_moves(t_vars *vars)
{
	char	*str;

	str = ft_itoa(vars->state.move_count);
	mlx_string_put(vars->mlx, vars->window, 25, 25, 0x00FF00, str);
	free(str);
}
