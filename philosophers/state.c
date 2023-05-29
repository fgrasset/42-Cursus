/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:28:20 by fgrasset          #+#    #+#             */
/*   Updated: 2023/05/29 11:43:41 by fgrasset         ###   ########.fr       */
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
