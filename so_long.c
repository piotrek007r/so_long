#include "so_long.h"

#define WIDTH 800
#define HEIGHT 600

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*window;
    t_data  img;
}			t_vars;

void	my_pixel_put(t_data *img, int x, int y, int color)
{
	int	offset;

	//🚨 Line len is in bytes. WIDTH 800 len_line ~3200 (can differ for alignment)
	offset = (img->line_length * y) + (x * (img->bits_per_pixel / 8));

	*((unsigned int *)(offset + img->addr)) = color;
}

/*
 * 🔥 my_pixel_put
*/
void	ft_horizotal(t_vars *data, int color, int y)
{

    int x;

    x = 0;
    while(x < WIDTH)
    {
        my_pixel_put(&data->img, x, y, color);
        x++;
    }
}

void	ft_vertical(t_vars *data, int color, int x)
{
    int y;

    y = 0;
    while(y < HEIGHT)
    {
        my_pixel_put(&data->img, x, y, color);
        y++;
    }
}


void	ft_grid(t_vars *data, int color)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while(y < HEIGHT)
    {
        printf("curr: y%d", y);
        ft_horizotal(data, color, y);
        y = y + 50;
    }
    while(x < WIDTH)
    {
        printf("curr: y%d", x);
        ft_vertical(data, color, x);
        x = x + 50;
    }
}	

void ft_put_tile(t_vars *vars)
{
    int width;
    int height;
    void *img;

    img = mlx_xpm_file_to_image(vars->mlx, "floor_1.xpm", &width, &height);
    if (img != NULL)
    {
        mlx_put_image_to_window(vars->mlx, vars->window, img, 50, 50);
        mlx_put_image_to_window(vars->mlx, vars->window, img, 50 + width, 50);
        mlx_put_image_to_window(vars->mlx, vars->window, img, 50 + 2 * width, 50);
    }
}
int	ft_start(int keys, t_vars *vars)
{
	if (keys == XK_space)
	{   
        // printf("nie zasraj się\n");
	    // ft_grid(vars, 0xff00);
		ft_put_tile(vars);
	}
	if (keys == XK_Escape)
	{
		mlx_destroy_window(vars->mlx, vars->window);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(1);
	}
    // mlx_put_image_to_window(vars->mlx, vars->window, vars->img.img, 0, 0);
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
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length,
			&vars.img.endian); // to free
    printf("bpp1: %d\n", vars.img.bits_per_pixel);
	mlx_key_hook(vars.window, ft_start, &vars);
	mlx_loop(vars.mlx);
	mlx_destroy_window(vars.mlx, vars.window);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);
}

//  compile line: gcc *.c -I./minilibx-linux -L./minilibx-linux -lmlx_Linux
// 	-lXext -lX11 -lm