#include "so_long.h"

void	ft_check_winsize(t_vars *vars)
{
	int	counter;

	vars->map.width = 0;
	vars->map.height = 0;
	vars->map.fd = open(vars->path, O_RDONLY);
	counter = 0;
	while (1)
	{
		vars->map.line = get_next_line(vars->map.fd);
		if (!vars->map.line)
			break ;
		vars->map.width = ft_strlen(vars->map.line) - 1;
		free(vars->map.line);
		counter++;
	}
	vars->map.height = counter;
	close(vars->map.fd);
	if (vars->map.width < 1)
	{
		ft_printf("Error\nNo map in source file!\n");
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(1);
	}
}

void	ft_check_args(void)
{
	ft_printf("Error\nInawalid number of arguments!");
	exit(1);
}
