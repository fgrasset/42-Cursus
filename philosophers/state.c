/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:28:20 by fgrasset          #+#    #+#             */
/*   Updated: 2023/06/02 14:40:49 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* returns true if the state of the sim is to continue */
int	state(t_config *config)
{
	if (!config->life)
		return (0);
	if (satiated(config))
	{
		config->life = 0;
		return (0);
	}
	// printf("%d < %d\n", config->t_die + config->last_bite, get_time('n'));
	// printf("last bite: %d\n", config->last_bite);
	// printf("config->t_die + config->last_bite: %d\n", (config->t_die/1000) + config->last_bite);
	// printf("get_time('n'): %d\n", get_time('n'));
	if ((config->t_die + config->last_bite) < get_time('n'))		//ISSUE HERE WTF IS THAT
	{
		write(1, "test\n", 5);
		state_update(config, 'L');
		sleep(1);
		return (0);
	}
	pthread_mutex_lock(config->sim_mutex);
	if (config->sim_state[0] == 0)
	{
		pthread_mutex_unlock(config->sim_mutex);
		config->life = 0;
		msg(config, DIES);
		return (0);
	}
	pthread_mutex_unlock(config->sim_mutex);
	return (1);
}
