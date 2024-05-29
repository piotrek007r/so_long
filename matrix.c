#include "so_long.h"

void	ft_set_matrix(t_vars *vars)
{
	int	counter;

	counter = 0;
	vars->map.matrix = (char **)malloc(vars->map.height * sizeof(char *) + 1);
	vars->map.fd = open(vars->path, O_RDONLY);
	if (vars->map.fd == -1)
		ft_close_app(vars);
	while (1)
	{
		vars->map.line = get_next_line(vars->map.fd);
		if (!vars->map.line)
			break ;
		if (vars->map.width != (int)ft_strlen(vars->map.line) - 1
			&& vars->map.width != 0)
			vars->map.rectangular = false;
		vars->map.matrix[counter] = (char *)malloc(vars->map.width + 1);
		if (!vars->map.matrix[counter])
			ft_close_app(vars);
		ft_strlcpy(vars->map.matrix[counter], vars->map.line, vars->map.width
			+ 1);
		free(vars->map.line);
		counter++;
	}
	close(vars->map.fd);
}

void	ft_update_matrix(t_vars *vars, char key)
{
	vars->map.matrix[vars->state.pos_y][vars->state.pos_x] = '0';
	if (key == 'w')
	{
		vars->map.matrix[vars->state.pos_y - 1][vars->state.pos_x] = 'P';
		vars->state.pos_y--;
	}
	else if (key == 's')
	{
		vars->map.matrix[vars->state.pos_y + 1][vars->state.pos_x] = 'P';
		vars->state.pos_y++;
	}
	else if (key == 'a')
	{
		vars->map.matrix[vars->state.pos_y][vars->state.pos_x - 1] = 'P';
		vars->state.pos_x--;
	}
	else if (key == 'd')
	{
		vars->map.matrix[vars->state.pos_y][vars->state.pos_x + 1] = 'P';
		vars->state.pos_x++;
	}
}
