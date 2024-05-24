#include "get_next_line/get_next_line.h"
#include "so_long.h"

#define WIDTH 1200
#define HEIGHT 900

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_map
{
	int		fd;
	int		cur_line;
    int     width;
    int     height;
	char	*line;
    char    **matrix;
}			t_map;

typedef struct s_obj
{
    int     width_px;
    int     height_px;
    void    *addr_obj;
} t_obj;

typedef struct s_vars
{
	void	*mlx;
	void	*window;
	t_img	img;
	t_map	map;
    t_obj   obj;
}			t_vars;


void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_length * y) + (x * (img->bits_per_pixel / 8));
	*((unsigned int *)(offset + img->addr)) = color;
}


void ft_draw_el(t_vars *vars, char *lay_type)
{
    int i;

    vars->obj.addr_obj = mlx_xpm_file_to_image(vars->mlx, lay_type, &vars->obj.width_px,
            &vars->obj.height_px);
    i = 0;
    while (vars->map.line[i] != '\n' && vars->map.line[i] != '\0')
    {
        mlx_put_image_to_window(vars->mlx, vars->window, vars->obj.addr_obj, vars->obj.width_px * (1
                    + i), vars->obj.height_px * vars->map.cur_line);
        i++;
    }
    
}

void	ft_draw_layer(t_vars *vars, char *lay_type)
{
	int	counter;

	vars->map.fd = open("maps/small.ber", O_RDONLY);
	vars->map.cur_line = 1;
	counter = 0;
	while (1)
	{
		vars->map.line = get_next_line(vars->map.fd);
		if (vars->map.line)
		{
			ft_draw_el(vars, lay_type);
			vars->map.cur_line++;
		}
		if (!vars->map.line)
			break ;
		else
			free(vars->map.line);
	}
    close(vars->map.fd);
}

void	ft_draw_map(t_vars *vars)
{
    ft_draw_layer(vars, "assets/floor_m.xpm");
    // ft_set_matrix(vars);
    // ft_draw_walls(vars);
}

int	ft_start(int keys, t_vars *vars)
{
    t_map map;

	if (keys == XK_space)
	{
		// ft_grid(vars, 0xff00);
		ft_draw_map(vars);
	}
	if (keys == XK_Escape)
	{
		mlx_destroy_image(vars->mlx, vars->img.img);
		mlx_destroy_window(vars->mlx, vars->window);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(1);
	}
	// mlx_put_image_to_window(vars->mlx, vars->window, vars->img.img, 0, 0);
	return (1);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.window = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "window");
	if (!vars.mlx)
	{
		mlx_destroy_display(vars.mlx);
		free(vars.mlx);
		return (1);
	}
	vars.img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel,
			&vars.img.line_length,
										&vars.img.endian); // to free
	mlx_key_hook(vars.window, ft_start, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.window);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
}

