/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:25:39 by fgrasset          #+#    #+#             */
/*   Updated: 2023/02/22 14:27:49 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <math.h>

#  define XMAX 200
#  define YMAX 200

/* struct to create a 3D vector in float */
typedef struct s_v3d {
	float	x;
	float	y;
	int		color;
}				t_v3d;

/* struct to get the data fo fdf */
typedef struct s_data {
	void		*img;
	void		*addr;
	char		*filename;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
	int			**map;
	int			x_max;
	int			y_max;
	float		dx;
	float		dy;
	float		rad;
	t_v3d		**f_map;
}				t_data;

// draw.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	line(t_data *data);

//map.c
void	map_borders(t_data *data);
void	map_malloc(t_data *data, int y_pos,  int flag);
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

#endif
