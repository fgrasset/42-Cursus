/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:21:10 by fgrasset          #+#    #+#             */
/*   Updated: 2023/06/05 15:09:24 by fabien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philo(t_philo *philo);
void	create_thread(t_philo *philo, int nb_philo);
void	*philo_day(void	*config);

/* launches the simulation */
void	launch_sim(t_philo **philo)
{
	int	i;

	i = -1;
	create_philo(*philo);
	while (++i < (*philo)->nb_philo)
		pthread_join((*philo)->threads[i], NULL);
}

/* creates each thread of each individual philo */
void	create_philo(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->nb_philo)
		create_thread(philo, i);
}

/* creates a thread for a philo and sets up the config struct */
void	create_thread(t_philo *philo, int nb_philo)
{
	t_config	*config;

	config = malloc(sizeof(t_config));
	if (!config)
		return ;
	config->pos = nb_philo;
	if (config->pos == philo->nb_philo - 1)
		config->next_pos = 0;
	else
		config->next_pos = nb_philo + 1;
	config->t_die = philo->time_die;
	config->t_eat = philo->time_eat;
	config->t_sleep = philo->time_sleep;
	config->life = 1;
	config->ate = 0;
	config->last_bite = get_time('n');
	config->sim_state = philo->sim_state;
	config->nb_philo = philo->nb_philo;
	config->forks = philo->forks;
	config->sim_mutex = philo->sim_mutex;
	config->nb_t_eat = philo->nb_time_eat;
	if (!pthread_create(&philo->threads[nb_philo], NULL, \
	philo_day, (void *) config))
		return ;
}

/* the daily rountine of a philo */
void	*philo_day(void	*arg)
{
	t_config	*config;

	config = (t_config *)arg;
	// //printf to printf everything in the config struct
	// printf("pos: %d\n", config->pos);
	// printf("next_pos: %d\n", config->next_pos);
	// printf("t_die: %d\n", config->t_die);
	// printf("t_eat: %d\n", config->t_eat);
	// printf("t_sleep: %d\n", config->t_sleep);
	// printf("life: %d\n", config->life);
	// printf("ate: %d\n", config->ate);
	// printf("last_bite: %d\n", config->last_bite);
	// printf("------------------\n");
	if (config->pos % 2 != 0)
		usleep(3000);
	while (config->life)
	{
		eats(config);
		sleeps(config);
		thinks(config);
	}
	free(config);
	return (0);
}

/* checks if all the philo have eaten enough */
int	satiated(t_config *config)
{
	if (config->nb_t_eat == -1)
		return (0);
	pthread_mutex_lock(&config->sim_mutex[1]);
	if (config->sim_state[1] == config->nb_philo)
		return (1);
	pthread_mutex_unlock(&config->sim_mutex[1]);
	return (0);
}
