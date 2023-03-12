/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:24:10 by fgrasset          #+#    #+#             */
/*   Updated: 2023/03/12 15:13:25 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* returns the file name and ensures it can be opened */
int	get_fd(t_data *data)
{
	int		fd;
	char	*line;

	fd = open(data->filename, O_RDONLY);
	if (fd < 0)
		check_error(0);
	line = get_next_line(fd);
	if (!line)
		check_error(3);
	free(line);
	return (fd);
}

/* gets the x_max and y_max of the given map */
void	map_borders(t_data *data)
{
	int		fd;
	int		i;
	char	*buf;

	i = -1;
	fd = get_fd(data);
	buf = get_next_line(fd);
	while (buf[++i])
	{
		if (buf[i] == ' ')
			data->x_max++;
		while (buf[i] == ' ' && buf[i])
			i++;
	}
	free(buf);
	data->x_max++;
	buf = get_next_line(fd);
	while (buf)
	{
		free(buf);
		data->y_max++;
		buf = get_next_line(fd);
	}
	data->y_max++;
	close(fd);
}

/* malloc the map, flag=0 for Y and flag=1 for X */
void	map_malloc(t_data *data, int y_pos, int flag)
{
	if (flag == 0)
	{
		data->map = (int **)malloc(data->y_max * sizeof(int **));
		if (!data->map)
			check_error(1);
	}
	else if (flag == 1)
	{
		data->map[y_pos] = (int *)malloc(data->x_max * sizeof(int *));
		if (!data->map[y_pos])
			check_error(1);
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
	{
		data->map[y_pos][x_pos] = ft_atoi(buffer[x_pos]);
		free(buffer[x_pos]);
	}
	free(buffer);
}

/* reads the map.fdf and adds it into a map */
void	map_get(t_data *data)
{
	int			fd;
	static int	y_pos;
	char		*line;

	map_borders(data);
	map_malloc(data, y_pos, 0);
	fd = get_fd(data);
	line = get_next_line(fd);
	while (line)
	{
		// check_error(line, 0);
		add_line(data, line, y_pos);
		free(line);
		line = get_next_line(fd);
		y_pos++;
	}
	close(fd);
}
