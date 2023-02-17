/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:21:33 by fgrasset          #+#    #+#             */
/*   Updated: 2023/02/17 16:22:56 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* draws a pixel at (x, y) in color */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/* draws a line from (x0, y0) to (x1,, y1) */
void	line(t_data *data, float x0, float y0, float x1, float y1, int color)
{
	while (x0 <= x1 && y0 <= y1)
	{
		if (x0 <= x1)
			my_mlx_pixel_put(data, x0, y0, color);
		if (y0 <= y1)
			my_mlx_pixel_put(data, x0, y0, color);
		x0++;
		y0++;
	}
}
