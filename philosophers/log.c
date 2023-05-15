/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:11:07 by fgrasset          #+#    #+#             */
/*   Updated: 2023/05/15 11:14:55 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	log(t_config *config, int state)
{
	if (state == EATS)
		printf("%d %d is eating\n", get_time('n'), config->pos);
	else if (state == SLEEPS)
		printf("%d %d is sleeping\n", get_time('n'), config->pos);
	else if (state == THINKS)
		printf("%d %d is thinking\n", get_time('n'), config->pos);
	else if (state == DIES)
		printf("%d %d died\n", get_time('n'), config->pos);
	else if (state == FORKS)
		printf("%d %d has taken a fork\n", get_time('n'), config->pos);
}
