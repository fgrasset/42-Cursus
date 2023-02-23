/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:21:33 by fgrasset          #+#    #+#             */
/*   Updated: 2023/02/23 16:22:41 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* draws a pixel at (x, y) in color */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > WIN_W && y < WIN_H)
	{
		dst = data->img.addr + (y * data->img.line_length + \
		x * (data->img.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

/* draws a line from (x0, y0) to (x1, y1) */
void	line(t_data *data, float x0, float y0, float x1, float y1)
{
	int	step;
	int	i;

	data->dx = (x1 - x0);
	data->dy = (y1 - y0);
	if (fabs(data->dx) >= fabs(data->dy))
		step = fabs(data->dx);
	else
		step = fabs(data->dy);
	data->dx /= step;
	data->dy /= step;
	i = 1;
	while (i <= step)
	{
		my_mlx_pixel_put(data, -x0 + (WIN_W / 3), \
		-y0 + (WIN_H / 3), 0x0000FF00);
		x0 += data->dx;
		y0 += data->dy;
		i++;
	}
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
			line(data, data->f_map[i][j].x, data->f_map[i][j].y, \
			data->f_map[i][j + 1].x, data->f_map[i][j + 1].y);
			line(data, data->f_map[i][j].x, data->f_map[i][j].y, \
			data->f_map[i + 1][j].x, data->f_map[i + 1][j].y);
			j++;
		}
		i++;
	}
}
