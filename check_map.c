#include "so_long.h"

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

void	ft_flood_fill(t_vars *vars, int x, int y)
{
	if (vars->map.matrix[y][x] == '1' || vars->map.matrix[y][x] == ' '
		|| vars->map.matrix[y][x] == 'G')
		return ;
	else
	{
		if (vars->map.matrix[y][x] == 'C')
			vars->state.collectible--;
		if (vars->map.matrix[y][x] == 'E')
			vars->map.path_clear = true;
		vars->map.matrix[y][x] = ' ';
		ft_flood_fill(vars, x + 1, y);
		ft_flood_fill(vars, x - 1, y);
		ft_flood_fill(vars, x, y + 1);
		ft_flood_fill(vars, x, y - 1);
	}
}

void	ft_check_path(t_vars *vars)
{
	int	x;
	int	y;

	vars->map.path_clear = false;
	x = vars->state.pos_x;
	y = vars->state.pos_y;
	ft_flood_fill(vars, x, y);
	if (vars->state.collectible > 0)
	{
		ft_printf("Error\nSome collectibles are not reacheble!\n");
		ft_close_app(vars);
	}
	if (!vars->map.path_clear)
	{
		ft_printf("Error\nPath not clear!\n");
		ft_close_app(vars);
	}
}
