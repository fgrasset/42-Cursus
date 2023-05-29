/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:11:07 by fgrasset          #+#    #+#             */
/*   Updated: 2023/05/29 14:04:34 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msg(t_config *config, int state)
{
	static int	lol;

	if (state == EATS)
		printf("%d %d is eating\n", get_time('o'), config->pos);
	else if (state == SLEEPS)
		printf("%d %d is sleeping\n", get_time('o'), config->pos);
	else if (state == THINKS)
		printf("%d %d is thinking\n", get_time('o'), config->pos);
	else if (state == DIES && ++lol < 2)
		printf("%d %d died\n", get_time('o'), config->pos);
	else if (state == FORKS)
		printf("%d %d has taken a fork\n", get_time('o'), config->pos);
}
