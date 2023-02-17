/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:25:39 by fgrasset          #+#    #+#             */
/*   Updated: 2023/02/17 16:16:52 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <math.h>

#  define XMAX 200
#  define YMAX 200

/* struct to create a matrix */
typedef struct s_matrix {
	int	x;
	int	y;
	int	z;
}				t_matrix;

/* struct to create each points
   having the z of the point and its
   associated color */
typedef struct s_point {
	float	x;
	float	y;
	float	z;
	int		color;
}				t_point;

/* struct to get the data fo fdf */
typedef struct s_data {
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_len;
	int			endian;
	int			***map;
	int			x_max;
	int			y_max;
}				t_data;

// draw.c
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	line(t_data *data, float x0, float y0, float x1, float y1, int color);

#endif
