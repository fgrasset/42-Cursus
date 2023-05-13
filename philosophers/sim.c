/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:21:10 by fgrasset          #+#    #+#             */
/*   Updated: 2023/05/13 13:55:12 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philo(t_philo *philo);
void	create_thread(t_philo *philo, int nb_philo);
void	*philo(void	**config);

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

void	create_thread(t_philo *philo, int nb_philo)
{
	t_config	*config;

	config = malloc(sizeof(t_config));
	if (!config)
		return ;
	config->pos = nb_philo + 1;
	config->t_die = philo->time_die;
	config->t_eat = philo->time_eat;
	config->t_sleep = philo->time_sleep;
	if (philo->nb_time_eat)
		config->nb_t_eat = philo->nb_time_eat;
	if (!pthread_create(philo->threads[nb_philo], NULL, philo, (void *)&config))
		return ;
}

void	*philo(void	**config)
{
	int	ate;
	int	life;

	ate = 0;
	life = 1;

}
