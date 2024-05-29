#ifndef SO_LONG_H
# define SO_LONG_H
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

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
	bool	rectangular;
	bool	path_clear;
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
	int		player;
	int		exit;
	int		collectible;
	int		pos_x;
	int		pos_y;
	int		move_count;
}			t_state;

typedef struct s_vars
{
	void	*mlx;
	void	*window;
	char	*path;
	t_img	img;
	t_map	map;
	t_obj	obj;
	t_state	state;
}			t_vars;

// main

void		ft_check_map(t_vars *vars);
void		ft_map_init(t_vars *vars);
int			ft_action(int keys, t_vars *vars);

// utils

void		my_pixel_put(t_img *img, int x, int y, int color);
void		ft_clean_matrix(t_vars *vars);
void		ft_close_app(t_vars *vars);
void		ft_count_items(t_vars *vars);

// drawing

void		ft_draw_el(t_vars *vars, char *lay_path, char lay_type);
void		ft_draw_layer(t_vars *vars, char *lay_path, char lay_type);
void		ft_rerender_map(t_vars *vars);

// map

void		ft_set_matrix(t_vars *vars);
void		ft_update_matrix(t_vars *vars, char key);

// movement

void		ft_move(t_vars *vars, char key);
char		ft_set_direction(t_vars *vars, char key);
void		ft_render_moves(t_vars *vars);

// checks

void		ft_check_walls(t_vars *vars);
void		ft_check_rectangular(t_vars *vars);
void		ft_check_items(t_vars *vars);
void		ft_flood_fill(t_vars *vars, int x, int y);
void		ft_check_path(t_vars *vars);
void		ft_check_winsize(t_vars *vars);
void		ft_check_args(void);

#endif
