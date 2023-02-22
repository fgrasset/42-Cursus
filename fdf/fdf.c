/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:39:26 by fgrasset          #+#    #+#             */
/*   Updated: 2023/02/22 14:25:05 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* initialisation of struct data */
void	initialisation(t_data *data)
{
	data->x_max = 0;
	data->rad = 120;
}

/* executes the program */
int main(int ac, char **ag)
{
	t_data	data;

	if (ac != 2)
		check_error(" ", 2);
	data.filename = ag[1];
	initialisation(&data);
	map_get(&data);
	print_map(&data);
	proj(&data);
	print_fmap(&data);
}
