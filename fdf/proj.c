/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:37:37 by fgrasset          #+#    #+#             */
/*   Updated: 2023/02/28 18:48:54 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* malloc of my float map */
void	float_malloc(t_data *data)
{
	int	i;

	i = -1;
	data->f_map = malloc(sizeof(t_v3d *) * (data->y_max));
	if (!data->f_map)
		check_error(" ", 1);
	while (++i < data->y_max)
	{
		data->f_map[i] = malloc(sizeof(t_v3d) * data->x_max);
		if (!data->f_map[i])
			check_error(" ", 1);
	}
}

/* returns the average height of the map */
void	get_z(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	data->z_max = data->map[0][0];
	data->z_min = data->map[0][0];
	while (++i < data->y_max)
	{
		j = -1;
		while (++j < data->x_max)
		{
			if (data->map[i][j] > data->z_max)
				data->z_max = data->map[i][j];
			else if (data->map[i][j] < data->z_min)
				data->z_min = data->map[i][j];
		}
	}
}

/* creates a new float point, calculates it and returns it */
t_v3d	calculate(t_data *data, int x, int y)
{
	t_v3d	point;

	point.x = (x * cosf(data->rad)) + (y * cosf(data->rad + 2)) \
	+ (data->map[y][x] * data->attitude * cosf(data->rad - 2));
	point.y = (x * sinf(data->rad)) + (y * sinf(data->rad + 2)) \
	+ (data->map[y][x] * data->attitude * sinf(data->rad - 2));
	point.x *= data->scale;
	point.y *= data->scale;
	return (point);
}

/* takes the int map and projects each point
	to the float map */
void	proj(t_data *data)
{
	int		x;
	int		y;

	y = 0;
	get_z(data);
	float_malloc(data);
	while (y < data->y_max)
	{
		x = 0;
		while (x < data->x_max)
		{
			data->f_map[y][x] = calculate(data, x, y);
			x++;
		}
		y++;
	}
}

/* creates the different shades of colors */
int	colors(t_data *data, float x, float y)
{
	(void) data;
	(void) x;
	(void) y;
	return (0x00ffff);
}
