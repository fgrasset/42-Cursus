/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:39:59 by fgrasset          #+#    #+#             */
/*   Updated: 2023/02/25 13:22:13 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	destroy(int keycode, t_data *data)
{
	(void) keycode;
	mlx_destroy_window(data->mlx, data->mlx_win);
	return (0);
}

/* creates the graphical window
	0 - initiate the beginning
	1 - put image to window */
void	make_window(t_data	*data, int flag)
{
	if (flag == 0)
	{
		data->mlx = mlx_init();
		data->mlx_win = mlx_new_window(data->mlx, WIN_W, WIN_H, "For Sparta");
		data->img.img = mlx_new_image(data->mlx, WIN_W, WIN_H);
		data->img.addr = mlx_get_data_addr(data->img.img, \
		&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	}
	else if (flag == 1)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
		// mlx_hook(data->mlx_win, 17, 0, close, data);
		mlx_loop(data->mlx);
	}
}
