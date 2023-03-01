/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:21:33 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/01 16:57:24 by fgrasset         ###   ########.fr       */
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
	int	step;
	int	i;

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
		my_mlx_pixel_put(data, start->x + (WIN_W / 2) + data->mv_w, \
		start->y + (WIN_H / 2) + data->mv_h, 0x00ffff);
		start->x += data->dx;
		start->y += data->dy;
		i++;
	}
	// int	step;
	// int	i;
	// int x0;
	// int x1;
	// int y0;
	// int y1;

	// x0 = data->start.x;
	// x1 = data->end.x;
	// y0 = data->start.y;
	// y1 = data->end.y;

	// data->dx = (x1 - x0);
	// data->dy = (y1 - y0);
	// if (fabs(data->dx) >= fabs(data->dy))
	// 	step = fabs(data->dx);
	// else
	// 	step = fabs(data->dy);
	// data->dx /= step;
	// data->dy /= step;
	// i = 1;
	// while (i <= step)
	// {
	// 	my_mlx_pixel_put(data, x0 + (WIN_W / 2) + data->mv_w, \
	// 	y0 + (WIN_H / 2) + data->mv_h, 0x00ffff);
	// 	x0 += data->dx;
	// 	y0 += data->dy;
	// 	i++;
	// }
}

/* decides which lines to draw depending on the
	position of the point */
void	limits(t_data *data, int i, int j)
{
	t_v3d *start;
	t_v3d *end;

	start->x = data->f_map[i][j].x;
	start->y = data->f_map[i][j].y;
	if (i < data->y_max - 1 && j < data->x_max - 1)
	{
		end->x = data->f_map[i][j + 1].x;
		end->y = data->f_map[i][j + 1].y;
		line(data, start, end);
		end->x = data->f_map[i + 1][j].x;
		end->y = data->f_map[i + 1][j].y;
		line(data, start, end);
	}
	else if (i < data->y_max - 1 && j == data->x_max - 1)
	{
		end->x = data->f_map[i + 1][j].x;
		end->y = data->f_map[i + 1][j].y;
		line(data, start, end);
	}
	else if (i == data->y_max - 1 && j < data->x_max - 1)
	{
		end->x = data->f_map[i][j + 1].x;
		end->y = data->f_map[i][j + 1].y;
		line(data, start, end);
	}
	else
	{
		return ;
	}
	// 	if (i < data->y_max - 1 && j < data->x_max - 1)
	// {
	// 	line(data, data->f_map[i][j].x, data->f_map[i][j].y, \
	// 		data->f_map[i][j + 1].x, data->f_map[i][j + 1].y);
	// 	line(data, data->f_map[i][j].x, data->f_map[i][j].y, \
	// 		data->f_map[i + 1][j].x, data->f_map[i + 1][j].y);
	// }
	// else if (i < data->y_max - 1 && j == data->x_max - 1)
	// {
	// 	line(data, data->f_map[i][j].x, data->f_map[i][j].y, \
	// 		data->f_map[i + 1][j].x, data->f_map[i + 1][j].y);
	// }
	// else if (i == data->y_max - 1 && j < data->x_max - 1)
	// {
	// 	line(data, data->f_map[i][j].x, data->f_map[i][j].y, \
	// 		data->f_map[i][j + 1].x, data->f_map[i][j + 1].y);
	// }
	// else
	// {
	// 	return ;
	// }
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
