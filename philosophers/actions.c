/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:23:51 by fgrasset          #+#    #+#             */
/*   Updated: 2023/05/17 13:36:15 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* philosopher is eating */
void	eats(t_config *config)
{
	pthread_mutex_lock(&config->forks[config->pos]);
	pthread_mutex_lock(&config->forks[config->next_pos]);
	msg(config, FORKS);
	msg(config, EATS);
	usleep(config->t_eat);
	pthread_mutex_unlock(&config->forks[config->pos]);
	pthread_mutex_unlock(&config->forks[config->next_pos]);
	config->last_bite = get_time('n');
	config->ate += 1;
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
