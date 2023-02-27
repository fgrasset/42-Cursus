/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:39:59 by fgrasset          #+#    #+#             */
/*   Updated: 2023/02/27 16:02:45 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* creates the graphical window */
void	make_window(t_data	*data)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIN_W, WIN_H, "For Sparta");
	data->img.img = mlx_new_image(data->mlx, WIN_W, WIN_H);
	data->img.addr = mlx_get_data_addr(data->img.img, \
	&data->img.bits_per_pixel, &data->img.line_length, &data->img.endian);
	graphical_interface(data);
	mlx_loop(data->mlx);
}

/* launches the graphical interface and keeps it updated */
void	graphical_interface(t_data *data)
{
	mlx_key_hook(data->mlx_win, keypress, data);
	mlx_mouse_hook(data->mlx_win, zoom, data);
	mlx_hook(data->mlx_win, 17, 0, destroy, data);
	mlx_loop_hook(data->mlx, display, data);
}

/* updates the displayed image */
int	display(t_data *data)
{
	background(data);
	proj(data);
	draw(data);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img, 0, 0);
	return (0);
}
