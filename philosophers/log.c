/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:11:07 by fgrasset          #+#    #+#             */
/*   Updated: 2023/06/05 15:59:20 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msg(t_config *config, int state)
{
	static int	lol;

	if (state == EATS && lol < 1)
		printf("%d %d is eating\n", get_time('n'), config->pos + 1);
	else if (state == SLEEPS && lol < 1)
		printf("%d %d is sleeping\n", get_time('n'), config->pos + 1);
	else if (state == THINKS && lol < 1)
		printf("%d %d is thinking\n", get_time('n'), config->pos + 1);
	else if (state == DIES && ++lol < 2)
		printf("%d %d died\n", get_time('n'), config->pos + 1);
	else if (state == FORKS && lol < 1)
		printf("%d %d has taken a fork\n", get_time('n'), config->pos + 1);
}
