/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:28:32 by fgrasset          #+#    #+#             */
/*   Updated: 2023/02/20 13:50:12 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// /* adds point (x, y, z) to the matrix at position i, j */
// void	add_point(t_matrix *matrix, int x, int y, int z)
// {

// }

// /* transform each point so that they
//    are ready to be drawned to the window,
//    continue while true */
// int	transform(t_data *data)
// {
// 	float	**rotation;
// 	t_point	*point;
// 	static int x;
// 	static int y;

// 	rotation_matrix(&rotation);
// 	if ((x <= data->x_max) && (data->y_max <= YMAX))
// 	{
// 		point->x += rotation[0][0] * x;
// 		point->x += rotation[0][1] * y;
// 		point->x += rotation[0][2] * data->map[x][y][0];
// 		point->y += rotation[1][0] * x;
// 		point->y += rotation[1][1] * y;
// 		point->y += rotation[1][2] * data->map[x][y][0];
// 		x++;
// 		y++;
// 		data->map[x][y][1] = point;
// 		return (0);
// 	}
// 	else
// 		return (1);
// }

// /* returns the rotation matrix */
// t_matrix	rotation_matrix(float **rotation)
// {
// 	int	x;

// 	x = 1 / sqrt(6);
// 	rotation[0][0] = x * sqrt(3);
// 	rotation[0][1] = 0;
// 	rotation[0][2] = x * -sqrt(3);
// 	rotation[1][0] = x * 1;
// 	rotation[1][1] = x * 2;
// 	rotation[1][2] = x * 1;
// 	rotation[2][0] = x * sqrt(2);
// 	rotation[2][1] = x * -sqrt(2);
// 	rotation[2][2] = x * sqrt(2);
// }
