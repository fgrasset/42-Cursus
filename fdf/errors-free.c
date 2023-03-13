/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors-free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:17:53 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/13 10:01:46 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* depending on flag, prints the error message and exits program
	0 - error opening file
	1 - malloc failed
	2 - arguments error
	3 - file is empty */
void	check_error(int flag)
{
	if (flag == 0)
	{
		perror("Error opening file");
	}
	else if (flag == 1)
	{
		perror("Malloc failed");
	}
	else if (flag == 2)
	{
		perror("Error in the arguments");
	}
	else if (flag == 3)
	{
		perror("File is empty");
	}
	exit(1);
}

/* depending on flag, frees the correct given data
	M - frees map
	F - frees fmap */
void	to_free(t_data *data, char flag)
{
	int	i;

	i = -1;
	if (flag == 'M')
	{
		while (++i < data->y_max)
			free(data->map[i]);
		free(data->map);
	}
	else if (flag == 'F')
	{
		while (++i < data->y_max)
			free(data->f_map[i]);
		free(data->f_map);
	}
	else if (flag == 'X')
	{
		free(data->mlx);
		free(data->mlx_win);
		free(data->img.addr);
		free(data->img.img);
	}
}
