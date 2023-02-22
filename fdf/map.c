/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:24:10 by fgrasset          #+#    #+#             */
/*   Updated: 2023/02/22 13:44:35 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* gets the x_max and y_max of the given map */
void	map_borders(t_data *data)
{
	int		fd;
	int		i;
	char	*buf;

	i = -1;
	fd = open(data->filename, O_RDONLY);
	buf = get_next_line(fd);
	while (buf[++i])
	{
		if (buf[i] == ' ')
			data->x_max++;
	}
	data->x_max++;
	buf = get_next_line(fd);
	while (buf)
	{
		data->y_max++;
		buf = get_next_line(fd);
	}
	free(buf);
	close(fd);
}

/* malloc the map, flag=0 for Y and flag=1 for X */
void	map_malloc(t_data *data, int y_pos,  int flag)
{
	if (flag == 0)
	{
		data->map = (int **)malloc(data->y_max * sizeof(int **));
		if (!data->map)
			check_error(" ", 1);
	}
	else if (flag == 1)
	{
		data->map[y_pos] = (int *)malloc(data->x_max * sizeof(int *));
		if (!data->map[y_pos])
			check_error(" ", 1);
	}
}

/* adds a line (x) to the map converting it in int
	returns the len of the line */
void	add_line(t_data *data, char *line, int y_pos)
{
	int			x_pos;
	char		**buffer;

	x_pos = -1;
	buffer = ft_split(line, ' ');
	map_malloc(data, y_pos, 1);
	while (buffer[++x_pos])
		data->map[y_pos][x_pos] = ft_atoi(buffer[x_pos]);
	free(buffer);
}

/* reads the map and adds it into a matrix */
void	map_get(t_data *data)
{
	int			fd;
	static int	y_pos;
	char		*line;

	map_borders(data);
	map_malloc(data, y_pos, 0);
	fd = open(data->filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		check_error(line, 0);
		add_line(data, line, y_pos);
		line = get_next_line(fd);
		y_pos++;
	}
	free(line);
	close(fd);
}

/* prints the map in the data struct */
void	print_map(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->y_max - 1)
	{
		j = 0;
		while (j < data->x_max)
		{
			ft_printf("%d ", data->map[i][j]);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
