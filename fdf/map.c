/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:24:10 by fgrasset          #+#    #+#             */
/*   Updated: 2023/02/18 12:51:21 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* reads the map and adds it into a matrix */
void	map_get(t_data *data, int map)
{
	/* use GNL to retrieve data then put
	 them in a matrix using split, getting first
	 line as y = 0, x = 1 to end of split
	 and y = value of the number at each split
	 let's make it so that what is after the ','
	 is the color of the point */
	int			fd;
	static int	line_pos;
	char		*line;

	fd = open("test_maps/basictest.fdf", "O_RDONLY");

	/* make the error cases */

	while (!get_next_line(line))
	{
		data->map[line_pos] = ft_split(line, ' ');
		line_pos++;
	}
	close(fd);
}


