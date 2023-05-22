/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:23:51 by fgrasset          #+#    #+#             */
/*   Updated: 2023/05/22 14:41:06 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		outlive(t_config *config, char flag);

/* philosopher is eating */
void	eats(t_config *config)
{
	if ((get_time('n') - config->last_bite) >= config->t_die)
	{
		pthread_mutex_lock(&config->life_mutex[0]);
		config->life_state[0] = 1;
		pthread_mutex_unlock(&config->life_mutex[0]);
		config->life = 0;
		return ;
	}
	pthread_mutex_lock(&config->forks[config->pos]);
	msg(config, FORKS);
	pthread_mutex_lock(&config->forks[config->next_pos]);
	msg(config, FORKS);
	msg(config, EATS);
	if (outlive(config, 'E'))
		usleep(config->t_eat);
	else
		config->life = 0;
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

/* true if philo outlives time he has to pass
	if flag == 'S' for sleep
	if flag == 'E' for sleep
	if flag == */
int	outlive(t_config *config, char flag)
{
	if (flag == 'S')
	{
		if (((get_time('n') + config->t_sleep) - config->last_bite) < config->t_die)
			return (1);
	}
	else if (flag == 'E')
	{
		if ((get_time('n') - config->last_bite) < config->t_die)
			return (1);
	}
	else
	{
		if ((get_time('n') - (sleep * 1000)) < config->t_die)
			return (1);
	}
	return (0);
}
