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
			exit (1); // to handle ft_eescape
		ft_strlcpy(vars->map.matrix[counter], vars->map.line, vars->map.width + 1);
		free(vars->map.line);
		counter++;
	}
	close(vars->map.fd);
	// for(int i = 0; i < vars->map.height; i++)
	// 	printf("%s\n", vars->map.matrix[i]);
}

void ft_update_matrix(t_vars *vars, char key)
{
	vars->map.matrix[vars->state.pos_y][vars->state.pos_x] = '0';

	if(key == 'w')
	{
		vars->map.matrix[vars->state.pos_y - 1][vars->state.pos_x] = 'P';
		vars->state.pos_y--;
	}
	else if(key == 's')
	{
		vars->map.matrix[vars->state.pos_y + 1][vars->state.pos_x] = 'P';
		vars->state.pos_y++;
	}
	else if(key == 'a')
	{
		vars->map.matrix[vars->state.pos_y][vars->state.pos_x - 1] = 'P';
		vars->state.pos_x--;
	}
	else if(key == 'd')
	{
		vars->map.matrix[vars->state.pos_y][vars->state.pos_x + 1] = 'P';
		vars->state.pos_x++;
	}	
}