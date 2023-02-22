/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors-free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:17:53 by fgrasset          #+#    #+#             */
/*   Updated: 2023/02/22 14:15:32 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* depending on flag, prints the error message and exits program
	0 - file is empty
	1 - malloc failed
	2 - arguments error */
void	check_error(char *line, int flag)
{
	if (flag == 0)
	{
		if (line[0] == '\0')
			perror("Empty map");
		else
			return ;
	}
	else if (flag == 1)
	{
		perror("Malloc failed");
	}
	else if (flag == 2)
	{
		perror("Error in the arguments");
	}
	exit(1);

}

/* depending on flag, frees the correct given data
	M - frees map*/
void	to_free(t_data *data, char flag)
{
	int	i;
	int	j;

	i = 0;
	if (flag == 'M')
	{
		while (data->map[i] != NULL)
		{
			j = 0;
			while (data->map[i])
			{
				free(data->map[i]);
				j++;
			}
			i++;
		}
		free(data->map);
	}
}
