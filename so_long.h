#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 1200
# define HEIGHT 900

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
	int		width;
	int		height;
	char	*line;
	char	**matrix;
}			t_map;

typedef struct s_obj
{
	int		width_px;
	int		height_px;
	void	*addr_obj;
}			t_obj;

typedef struct s_state
{
	int pos_x;
	int pos_y;
}	t_state;


typedef struct s_vars
{
	void	*mlx;
	void	*window;
	t_img	img;
	t_map	map;
	t_obj	obj;
	t_state state;
}			t_vars;

void		ft_clean_matrix(t_vars *vars);
void		my_pixel_put(t_img *img, int x, int y, int color);
void		ft_draw_el(t_vars *vars, char *lay_path, char lay_type);
void		ft_draw_layer(t_vars *vars, char *lay_path, char lay_type);

#endif

