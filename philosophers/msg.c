/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:11:07 by fgrasset          #+#    #+#             */
/*   Updated: 2023/06/07 09:01:18 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	msg(t_config *config, int status)
{
	static int	lol;

	if (status == EATS && lol < 1 && state(config))
		printf("%d %d is eating\n", get_time('n'), config->pos + 1);
	else if (status == SLEEPS && lol < 1 && state(config))
		printf("%d %d is sleeping\n", get_time('n'), config->pos + 1);
	else if (status == THINKS && lol < 1 && state(config))
		printf("%d %d is thinking\n", get_time('n'), config->pos + 1);
	else if (status == DIES && ++lol < 2)
		printf("%d %d died\n", get_time('n'), config->pos + 1);
	else if (status == FORKS && lol < 1 && state(config))
		printf("%d %d has taken a fork\n", get_time('n'), config->pos + 1);
}
