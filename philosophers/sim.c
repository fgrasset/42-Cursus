/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:21:10 by fgrasset          #+#    #+#             */
/*   Updated: 2023/05/15 11:14:00 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philo(t_philo *philo);
void	create_thread(t_philo *philo, int nb_philo);
void	*philo_day(t_config	**config);

/* launches the simulation */
void	launch_sim(t_philo **philo, t_config **config)
{

}

/* creates each thread of each individual philo */
void	create_philo(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->nb_philo)
	{
		create_thread(philo, i);
	}
}

/* creates a thread for a philo and sets up the config struct */
void	create_thread(t_philo *philo, int nb_philo)
{
	t_config	*config;

	config = malloc(sizeof(t_config));
	if (!config)
		return ;
	config->pos = nb_philo + 1;
	if (config->pos == philo->nb_philo)
		config->next_pos = 1;
	else
		config->next_pos = nb_philo + 2;
	config->t_die = philo->time_die;
	config->t_eat = philo->time_eat;
	config->t_sleep = philo->time_sleep;
	config->life = 1;
	config->ate = 0;
	config->forks = philo->forks;
	if (philo->nb_time_eat)
		config->nb_t_eat = philo->nb_time_eat;
	if (!pthread_create(philo->threads[nb_philo], NULL, philo_day, (void *)&config))
		return ;
}

/* the daily rountine of a philo */
void	*philo_day(t_config	**config)
{
	if ((*config)->pos % 2 != 0)
		usleep(2000);
	while((*config)->life)
	{
		eats(&config);
		sleeps(&config);
		log(&config, THINKS);
	}
	log(&config, DIES);
}
