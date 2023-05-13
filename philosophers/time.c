/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:11:20 by fgrasset          #+#    #+#             */
/*   Updated: 2023/05/13 14:04:08 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* if flag == 'i', initializes the timeofday, else return the
	difference with the current time */
int	get_time(char c)
{
	struct timeval tv;
	static int start_time;

	if (c == 'i')
	{
		gettimeofday(&tv, NULL);
		start_time = tv.tv_usec;
		return (0);
	}
	else
	{
		gettimeofday(&tv, NULL);
		return (tv.tv_usec - start_time);
	}
	return (0);
}