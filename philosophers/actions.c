/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:23:51 by fgrasset          #+#    #+#             */
/*   Updated: 2023/06/02 14:41:38 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		outlive(t_config *config, int time);

/* philosopher is eating */
void	eats(t_config *config)
{
	if (!state(config))
		return ;
	pthread_mutex_lock(&config->forks[config->pos]);
	msg(config, FORKS);
	if (!state(config))
		return ;
	pthread_mutex_lock(&config->forks[config->next_pos]);
	msg(config, FORKS);
	if (!state(config))
		return ;
	msg(config, EATS);
	if (outlive(config, config->t_eat))
		usleep(config->t_eat);
	pthread_mutex_unlock(&config->forks[config->pos]);
	pthread_mutex_unlock(&config->forks[config->next_pos]);
	if (!config->life)
		return ;
	config->last_bite = get_time('n');
	// printf("last bite: %d\n", config->last_bite);
	if (config->nb_t_eat >= 0 && (++config->ate == config->nb_t_eat))
		state_update(config, 'E');
}

/* philosopher is sleeping */
void	sleeps(t_config *config)
{
	if (!config->life)
		return ;
	msg(config, SLEEPS);
	if (outlive(config, config->t_sleep))
		usleep(config->t_sleep);
}

/* philosopher is thinking */
void	thinks(t_config *config)
{
	if (!config->life)
		return ;
	msg(config, THINKS);
}

/* true if philo outlives time he has to pass
	else it just waits and terminate the thread */
int	outlive(t_config *config, int time)
{
	if ((config->last_bite + time) < (config->last_bite + config->t_die))
		return (1);
	usleep((config->last_bite + config->t_die) - \
	(config->last_bite + config->t_die));
	state_update(config, 'L');
	config->life = 0;
	return (0);
}

/* updates the sim_state variable based on the flag
	if flag == 'L', put sim_state[0] == 0
	if flag == 'E', increases sim_state[1]++ */
void	state_update(t_config *config, char flag)
{
	if (flag == 'L')
	{
		pthread_mutex_lock(&config->sim_mutex[0]);
		config->sim_state[0] = 0;
		pthread_mutex_unlock(&config->sim_mutex[0]);
		config->life = 0;
		msg(config, DIES);
		return ;
	}
	if (flag == 'E')
	{
		pthread_mutex_lock(&config->sim_mutex[1]);
		config->sim_state[1] += 1;
		pthread_mutex_unlock(&config->sim_mutex[1]);
	}
	return ;
}
