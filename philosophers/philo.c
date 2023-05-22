/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:16:09 by fgrasset          #+#    #+#             */
/*   Updated: 2023/05/22 14:13:23 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize(t_philo *philo, char **settings);
int		ft_atoi(const char *str);


int	main(int ac, char **av)
{
	t_philo		*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (0);
	if (!infos_check(av, ac))
		return (0);
	initialize(philo, av);
	launch_sim(&philo);
	return (0);
}

/* initializes the philo struct based on the given infos */
void	initialize(t_philo *philo, char **settings)
{
	int i;

	i = 0;
	philo->nb_philo = ft_atoi(settings[++i]);
	if (philo->nb_philo < 1)
		return;
	philo->time_die = ft_atoi(settings[++i]);
	philo->time_eat = ft_atoi(settings[++i]);
	philo->time_sleep = ft_atoi(settings[++i]);
	if (settings[++i])
		philo->nb_time_eat = ft_atoi(settings[i]);
	philo->threads = malloc(sizeof(pthread_t) * philo->nb_philo);
	if (!philo->threads)
		return;

	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->nb_philo);
	if (!philo->forks)
		return;

	for (int j = 0; j < philo->nb_philo; j++) {
		if (pthread_mutex_init(&philo->forks[j], NULL) != 0)
			return;
	}

	philo->life_mutex = malloc(sizeof(pthread_mutex_t));
	if (!philo->life_mutex)
		return;

	if (pthread_mutex_init(philo->life_mutex, NULL) != 0)
		return;

	philo->life_state = malloc(sizeof(int) * philo->nb_philo);
	if (!philo->life_state)
		return;

	get_time('i');
}


/* basically atoi */
int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;

	i = 0;
	if (str[i] == '+')
		i++;
	nbr = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	return (nbr);
}
