/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proj.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:37:37 by fgrasset          #+#    #+#             */
/*   Updated: 2023/02/22 14:34:46 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* malloc of my float map */
void	float_malloc(t_data *data)
{
	int	i;

	i = -1;
	data->f_map = malloc(sizeof(t_v3d) * (data->y_max));
	if (!data->f_map)
		check_error(" ", 1);
	while (++i < data->x_max)
	{
		data->f_map[i] = malloc(sizeof(t_v3d) * data->x_max);
		if (!data->f_map[i])
			check_error(" ", 1);
	}
}

/* creates a new float point, calculates it and returns it */
t_v3d	calculate(t_data *data, int x, int y)
{
	t_v3d	point;

	point.x = (x * cosf(data->rad)) + (x * cosf(data->rad + 2)) + (data->map[y][x] * cosf(data->rad - 2));
	point.y = (y * sinf(data->rad)) + (x * sinf(data->rad + 2)) + (data->map[y][x] * sinf(data->rad - 2));
	ft_printf("points: (%f, %f)\n", point.x, point.y);
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
	ft_printf("%d\n", data->x_max);
	while (y < data->y_max)
	{
		x = 0;
		while (x < data->x_max)
		{
			data->f_map[x][y] = calculate(data, x, y);
			x++;
		}
		y++;
	}
	write(1, "test", 4);
}

void	print_fmap(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i <= data->y_max)
	{
		j = 0;
		while (j <= data->x_max)
		{
			ft_printf("(%f, %f) ", data->f_map[i][j].x, data->f_map[i][j].y);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
