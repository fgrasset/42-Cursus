/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:39:59 by fgrasset          #+#    #+#             */
/*   Updated: 2023/02/25 22:15:33 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* close the window and exit the program */
int	destroy(int keycode, t_data *data)
{
	(void) keycode;
	mlx_destroy_window(data->mlx, data->mlx_win);
	to_free(data, 'M');
	to_free(data, 'F');
	exit(1);
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
		mlx_hook(data->mlx_win, EVENT_DESTROY, 0, &destroy, data);
		// mlx_key_hook(data->mlx_win, destroy, data);
		mlx_loop(data->mlx);
	}
}
