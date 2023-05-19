/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:23:51 by fgrasset          #+#    #+#             */
/*   Updated: 2023/05/19 15:19:29 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* philosopher is eating */
void	eats(t_config *config)
{
	if ((get_time('n') - config->last_bite) >= config->t_die)
	{
		pthread_mutex_lock(&config->life_mutex[0]);
		config->life_state[0] = 1;
		pthread_mutex_unlock(&config->life_mutex[0]);
		return ;
	}
	pthread_mutex_lock(&config->forks[config->pos]);
	pthread_mutex_lock(&config->forks[config->next_pos]);
	msg(config, FORKS);
	msg(config, EATS);
	usleep(config->t_eat);
	pthread_mutex_unlock(&config->forks[config->pos]);
	pthread_mutex_unlock(&config->forks[config->next_pos]);
	config->last_bite = get_time('n');
	if (config->nb_t_eat && (++config->ate == config->nb_t_eat))
	{
		pthread_mutex_lock(&config->life_mutex[config->pos]);
		config->life_state[config->pos] = 1;
		pthread_mutex_unlock(&config->life_mutex[config->pos]);
	}
}

/* philosopher is sleeping */
void	sleeps(t_config *config)
{
	msg(config, SLEEPS);
	usleep(config->t_sleep);
}

/* philosopher is thinking */
void	thinks(t_config *config)
{
	msg(config, THINKS);
}
