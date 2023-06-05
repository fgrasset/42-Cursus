/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:23:51 by fgrasset          #+#    #+#             */
/*   Updated: 2023/06/05 15:58:07 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		outlive(t_config *config, int time);

/* philosopher is eating */
void	eats(t_config *config)
{
	int start;

	if (!state(config))
		return ;
	while (config->life && pthread_mutex_lock(&config->forks[config->pos]))
		state(config);
	msg(config, FORKS);
	if (!config->life)
		return ;
	while (config->life && pthread_mutex_lock(&config->forks[config->next_pos]))
		state(config);
	msg(config, FORKS);
	start = get_time('n');
	msg(config, EATS);
	config->last_bite = get_time('n');
	while (config->life && (start + config->t_eat) > get_time('n'))
		state(config);
	pthread_mutex_unlock(&config->forks[config->pos]);
	pthread_mutex_unlock(&config->forks[config->next_pos]);
	if (config->life && config->nb_t_eat >= 0 && (++config->ate == config->nb_t_eat))
		state_update(config, 'E');
}

/* philosopher is sleeping */
void	sleeps(t_config *config)
{
	int	start;

	state(config);
	if (!config->life)
		return ;
	start = get_time('n');
	msg(config, SLEEPS);
	while (config->life && (start + config->t_sleep) > get_time('n'))
		state(config);
}

/* philosopher is thinking */
void	thinks(t_config *config)
{
	state(config);
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
	if flag == 'E', increases sim_state[1]++
	and check if the philos have all eaten */
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
		if (config->sim_state[1] == config->nb_t_eat)
			state_update(config, 'L');
		pthread_mutex_unlock(&config->sim_mutex[1]);
	}
	return ;
}
