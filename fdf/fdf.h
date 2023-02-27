/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:25:39 by fgrasset          #+#    #+#             */
/*   Updated: 2023/02/27 16:07:55 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <math.h>

# define WIN_W 1000
# define WIN_H 800
# define MOVE 10
# define ELEVATION 0.1
# define ZOOM 2

# define SNOW 0xfffafa
# define CYAN 0x00ffff

enum {
	EVENT_KEYDOWN = 2,
	EVENT_KEYUP = 3,
	EVENT_MOUSEDOWN = 4,
	EVENT_MOUSEUP = 5,
	EVENT_MOUSEMOVE = 6,
	EVENT_EXPOSE = 12,
	EVENT_DESTROY = 17
} ;

/* struct to create a 3D vector in float */
typedef struct s_v3d {
	float	x;
	float	y;
}				t_v3d;

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

/* struct to get the data fo fdf */
typedef struct s_data {
	void		*mlx;
	void		*mlx_win;
	char		*filename;
	int			**map;
	int			x_max;
	int			y_max;
	int			scale;
	int			mv_w;
	int			mv_h;
	float		attitude;
	float		dx;
	float		dy;
	float		rad;
	t_img		img;
	t_v3d		**f_map;
}				t_data;

// draw.c

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	line(t_data *data, float x0, float y0, float x1, float y1);
void	draw(t_data *data);
void	limits(t_data *data, int i, int j);
void	background(t_data *data);

//map.c

int		get_fd(t_data *data);
void	map_borders(t_data *data);
void	map_malloc(t_data *data, int y_pos, int flag);
void	add_line(t_data *data, char *line, int y_pos);
void	map_get(t_data *data);
void	print_map(t_data *data);

//proj.c

void	float_malloc(t_data *data);
void	proj(t_data *data);
void	print_fmap(t_data *data);

//errors-free.c

void	check_error(char *line, int flag);
void	to_free(t_data *data, char flag);

//graphic.c

void	make_window(t_data	*data);
void	graphical_interface(t_data *data);
int		display(t_data *data);

//hooks.c

int		destroy(t_data *data);
int		keypress(int keycode, t_data *data);
int		zoom(int keycode, int x, int y, t_data *data);

#endif
