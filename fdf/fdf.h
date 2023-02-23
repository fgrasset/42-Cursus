/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:25:39 by fgrasset          #+#    #+#             */
/*   Updated: 2023/02/23 16:25:30 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <math.h>

# define WIN_H 1920
# define WIN_W 1080

/* struct to create a 3D vector in float */
typedef struct s_v3d {
	float	x;
	float	y;
}				t_v3d;

typedef struct s_img {
	void	*img;
	void	*addr;
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

//map.c

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

#endif
