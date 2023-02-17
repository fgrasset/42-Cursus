/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:39:26 by fgrasset          #+#    #+#             */
/*   Updated: 2023/02/17 16:24:07 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

/* initialisation of struct data */
void	initialisation(t_data *data)
{

}

/* executes the program */
int main(int ac, char **ag)
{
	void	*mlx;
	void	*mlx_win;
	t_data	data;

	(void) ac;
	(void) ag;


	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	data.img = mlx_new_image(mlx, 1920, 1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_len,
								&data.endian);
	// line_y(&data, 5, 0, 100, 0x00FF0000);
	// line_x(&data, 5, 0, 100, 0x000000FF);
	line(&data, 0, 0, 100, 100, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, data.img, 0, 0);
	mlx_loop(mlx);
}
