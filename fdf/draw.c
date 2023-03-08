/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:21:33 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/06 20:12:54 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* draws a pixel at (x, y) in color */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIN_W && y >= 0 && y < WIN_H)
	{
		dst = data->img.addr + (y * data->img.line_length + \
		x * (data->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

/* draws a line from (x0, y0) to (x1, y1) */
void	line(t_data *data, t_v3d *start, t_v3d *end)
{
	int		step;
	int		i;
	float	x;
	float	y;

	x = start->x;
	y = start->y;
	data->dx = (end->x - start->x);
	data->dy = (end->y - start->y);
	if (fabs(data->dx) >= fabs(data->dy))
		step = fabs(data->dx);
	else
		step = fabs(data->dy);
	data->dx /= step;
	data->dy /= step;
	i = 1;
	while (i <= step)
	{
		my_mlx_pixel_put(data, x + (WIN_W / 2) + data->mv_w, \
		y + (WIN_H / 2) + data->mv_h, 0x00ffff);
		x += data->dx;
		y += data->dy;
		i++;
	}
}

/* decides which lines to draw depending on the
	position of the point */
void	limits(t_data *data, int i, int j)
{
	t_v3d	start;
	t_v3d	end;

	start.x = data->f_map[i][j].x;
	start.y = data->f_map[i][j].y;
	if (i < data->y_max - 1 && j < data->x_max - 1)
	{
		assign(data, &end, i, j + 1);
		line(data, &start, &end);
		assign (data, &end, i + 1, j);
		line(data, &start, &end);
	}
	else if (i < data->y_max - 1 && j == data->x_max - 1)
	{
		assign (data, &end, i + 1, j);
		line(data, &start, &end);
	}
	else if (i == data->y_max - 1 && j < data->x_max - 1)
	{
		assign (data, &end, i, j + 1);
		line(data, &start, &end);
	}
	else
		return ;
}

/* draws the float map */
void	draw(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->y_max)
	{
		j = 0;
		while (j < data->x_max)
		{
			limits(data, i, j);
			j++;
		}
		i++;
	}
	to_free(data, 'F');
}

/* draws the background of the map */
void	background(t_data *data)
{
	int	height;
	int	width;

	height = -1;
	while (++height < WIN_H)
	{
		width = -1;
		while (++width < WIN_W)
		{
			my_mlx_pixel_put(data, width, height, SNOW);
		}
	}
}
