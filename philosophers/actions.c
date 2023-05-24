/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:23:51 by fgrasset          #+#    #+#             */
/*   Updated: 2023/05/24 16:34:58 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		outlive(t_config *config, int time);

/* philosopher is eating */
void	eats(t_config *config)
{
	if ((get_time('n') - config->last_bite) >= config->t_die)
	{
		pthread_mutex_lock(&config->sim_mutex[0]);
		config->sim_state[0] = 1;
		pthread_mutex_unlock(&config->sim_mutex[0]);
		config->life = 0;
		return ;
	}
	pthread_mutex_lock(&config->forks[config->pos]);
	msg(config, FORKS);
	pthread_mutex_lock(&config->forks[config->next_pos]);
	msg(config, FORKS);
	msg(config, EATS);
	if (outlive(config, config->t_eat))
		usleep(config->t_eat);
	pthread_mutex_unlock(&config->forks[config->pos]);
	pthread_mutex_unlock(&config->forks[config->next_pos]);
	if (!config->life)
		return ;
	config->last_bite = get_time('n');
	if (config->nb_t_eat && (++config->ate == config->nb_t_eat))
	{
		pthread_mutex_lock(&config->sim_mutex[1]);
		config->sim_state[1] += 1;
		pthread_mutex_unlock(&config->sim_mutex[1]);
	}
}

/* philosopher is sleeping */
void	sleeps(t_config *config)
{
	msg(config, SLEEPS);
	if (outlive(config, config->t_sleep))
		usleep(config->t_sleep);
}

/* true if philo outlives time he has to pass
	else it just waits and terminate the thread */
int	outlive(t_config *config, int time)
{
	/*
	make it so that if it outlives it it returns 1, else it usleep for the time left to live,
	*/
	if ((config->last_bite + time) < (config->last_bite + config->t_die))
		return (1);
	usleep((config->last_bite + config->t_die) - (config->last_bite + config->t_die));
	config->life = 0;
	return (0);
}
