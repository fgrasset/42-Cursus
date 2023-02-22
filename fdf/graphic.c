/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:39:59 by fgrasset          #+#    #+#             */
/*   Updated: 2023/02/22 16:02:59 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* creates the graphical window */
void	make_window(t_data	*data)
{
	data->mlx_win = mlx_new_window(data->mlx, 1920, 1080, "FdF ma gueule");
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_len,
								&data->endian);
	my_mlx_pixel_put(data->img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	mlx_loop(data->mlx);
}
