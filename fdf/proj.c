/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:37:37 by fgrasset          #+#    #+#             */
/*   Updated: 2023/02/25 13:00:17 by fgrasset         ###   ########.fr       */
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
int	average(t_data *data)
{
	float	average;
	int	i;
	int	j;

	average = 0;
	i = 0;
	while(i < data->y_max)
	{
		j = 0;
		while (j < data->x_max)
		{
			average += data->map[i][j];
			j++;
		}
		i++;
	}
	average /= (i * j);
	return (average);
}

/* creates a new float point, calculates it and returns it */
t_v3d	calculate(t_data *data, int x, int y)
{
	t_v3d	point;
	float	av;

	// x *= data->scale;
	// y *= data->scale;
	av = average(data);
	point.x = (x * cosf(data->rad)) + (y * cosf(data->rad + 2)) \
	+ (data->map[y][x] / av * cosf(data->rad - 2));
	point.y = (x * sinf(data->rad)) + (y * sinf(data->rad + 2)) \
	+ (data->map[y][x] / av * sinf(data->rad - 2));

	// point.x = (x - data->map[y][x]) / sqrtf(2);
	// point.y = (x + 2 * y + data->map[y][x]) / sqrtf(6);

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

void	print_fmap(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->y_max)
	{
		j = 0;
		while (j < data->x_max)
		{
			printf("(%f, %f) ", data->f_map[i][j].x, data->f_map[i][j].y);
			j++;
		}
		printf("\n");
		i++;
	}
}
