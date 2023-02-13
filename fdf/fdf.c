/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:39:26 by fgrasset          #+#    #+#             */
/*   Updated: 2023/02/13 14:35:16 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	line_y(t_data *data, int x, int start, int end, int color)
{
	int	y;

	y = start;
	while (y <= end)
	{
		my_mlx_pixel_put(data, x, y, color);
		y++;
	}
}

void	line_x(t_data *data, int y, int start, int end, int color)
{
	int	x;

	x = start;
	while (x <= end)
	{
		my_mlx_pixel_put(data, x, y, color);
		x++;
	}
}

/* executes the program */
int main(int ac, char **ag)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	(void) ac;
	(void) ag;


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_len,
								&img.endian);
	line_y(&img, 5, 0, 100, 0x00FF0000);
	line_x(&img, 5, 0, 100, 0x000000FF);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
