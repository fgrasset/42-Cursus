/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:11:20 by fgrasset          #+#    #+#             */
/*   Updated: 2023/06/07 09:16:07 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* if flag == 'i', initializes the timeofday,
	if flag == 'n', returns the time as of now
	else return the difference with the current time */
int	get_time(char c)
{
	struct timeval			tv;
	static struct timeval	start_time;

	if (c == 'i')
	{
		gettimeofday(&start_time, NULL);
		return (0);
	}
	else if (c == 'n')
	{
		gettimeofday(&tv, NULL);
		return ((tv.tv_sec - start_time.tv_sec) * 1000
			+ (tv.tv_usec - start_time.tv_usec) / 1000);
	}
	return (0);
}
