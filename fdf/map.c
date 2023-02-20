/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:24:10 by fgrasset          #+#    #+#             */
/*   Updated: 2023/02/20 15:12:35 by fgrasset         ###   ########.fr       */
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
	write(1, "map", 3);
	data->x_max++;
	while (buf[0] != '\0')
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
	/* use GNL to retrieve data then put
	 them in a matrix using split, getting first
	 line as y = 0, x = 1 to end of split
	 and y = value of the number at each split
	 let's make it so that what is after the ' '
	 is the color of the point */
	int			fd;
	static int	y_pos;
	char		*line;

	map_borders(data);
	write(1, "test", 4);
	fd = open(data->filename, O_RDONLY);
	line = get_next_line(fd);
	while (line[0] != '\0')
	{
		check_error(line, 0);
		add_line(data, line, y_pos);
		line = get_next_line(fd);
		y_pos++;
	}
	close(fd);
}


