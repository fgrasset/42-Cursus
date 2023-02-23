/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:21:33 by fgrasset          #+#    #+#             */
/*   Updated: 2023/02/22 20:14:88 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* draws a pixel at (x, y) in color */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img.addr + (y * data->img.line_length + x * (data->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/* draws a line from (x0, y0) to (x1, y1) */
void	line(t_data *data, int x0, int y0, int x1, int y1)
{
	int	step;

	data->dx = abs(x1 - x0);
	data->dy = abs(y1 - y0);
	if (data->dx >= data->dy)
		step = data->dx;
	else
		step = data->dy;
	data->dx /= step;
	data->dy /= step;

}
