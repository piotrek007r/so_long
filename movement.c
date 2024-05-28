# include "so_long.h"

void ft_move(t_vars *vars, char key)
{
	char dir;

	dir = ft_set_direction(vars, key);
	printf("%c\n", dir);
	if(dir == '1')
		return ;
	else if (dir == '0')
		ft_update_matrix(vars, key);
	else if (dir == 'C')
	{
		vars->state.collectible--;
		ft_update_matrix(vars, key);
	}
	else if (dir == 'E' && vars->state.collectible == 0)
	{
		ft_close_app(vars);
	}
	ft_rerender_map(vars);

	vars->state.move_count++;
}

char ft_set_direction(t_vars *vars, char key)
{

	char c;

	if(key == 'w')
		c = vars->map.matrix[vars->state.pos_y - 1][vars->state.pos_x];
	if(key == 's')
		c = vars->map.matrix[vars->state.pos_y + 1][vars->state.pos_x];
	if(key == 'a')
		c = vars->map.matrix[vars->state.pos_y][vars->state.pos_x - 1];
	if(key == 'd')
		c = vars->map.matrix[vars->state.pos_y][vars->state.pos_x + 1];
	return (c);
}
