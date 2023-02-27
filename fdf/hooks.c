/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:42:21 by fgrasset          #+#    #+#             */
/*   Updated: 2023/02/27 14:03:13 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"

/* close the window and exit the program */
int	destroy(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	to_free(data, 'M');
	to_free(data, 'F');
	exit(1);
	return (0);
}

/* event handler for pressing keys */
int	keypress(int keycode, t_data *data)
{
	if (keycode == 123)
		data->mv_w -= MOVE;
	else if (keycode == 124)
		data->mv_w += MOVE;
	else if (keycode == 125)
		data->mv_h += MOVE;
	else if (keycode == 126)
		data->mv_h -= MOVE;
	else if (keycode == 53)
		destroy(data);
	return (0);
}

/* zoom handler for the scroll mouse*/
int	zoom(int keycode, int x, int y, t_data *data)
{
	(void) x;
	(void) y;

	if (keycode == 4)
		data->scale += ZOOM;
	else if (keycode == 5)
		data->scale -= ZOOM;
	return (0);
}

void	automation(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 10)
	{
		zoom(5, 1, 1, data);
		keypress(125, data);
		sleep(1);
	}
}
