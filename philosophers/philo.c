/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabien <fabien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:16:09 by fgrasset          #+#    #+#             */
/*   Updated: 2023/06/05 13:41:27 by fabien           ###   ########.fr       */
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
	terminate(philo);
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
	printf("time die: %d\n", philo->time_die);
	printf("time eat: %d\n", philo->time_eat);
	printf("time sleep: %d\n", philo->time_sleep);
	printf("nb philo: %d\n", philo->nb_philo);
	if (settings[++i])
		philo->nb_time_eat = ft_atoi(settings[i]);
	else
		philo->nb_time_eat = -1;
	printf("nb time eat: %d\n", philo->nb_time_eat);
	philo->threads = malloc(sizeof(pthread_t) * philo->nb_philo);
	if (!philo->threads)
		return;

	philo->forks = malloc(sizeof(pthread_mutex_t) * philo->nb_philo);	//fork mutex
	if (!philo->forks)
		return;
	for (int j = -1; j < philo->nb_philo; j++) {
		if (pthread_mutex_init(&philo->forks[j], NULL) != 0)
			return;
	}

	philo->sim_mutex = malloc(sizeof(pthread_mutex_t));					//sim_mutex
	if (!philo->sim_mutex)
		return;
	if (pthread_mutex_init(philo->sim_mutex, NULL) != 0)
		return;

	philo->sim_state = malloc(sizeof(int) * 2);							//sim_state
	if (!philo->sim_state)
		return;
	philo->sim_state[0] = 1;
	philo->sim_state[1] = 0;
	get_time('i');
}

/* writes the error message based on the flag and returns 0 */
int	error_msg(char flag)
{
	if (flag == 'M')
		printf("There is an error in the malloc of philo\n");
	else if (flag == 'A')
		printf("There is not enough arguments or they are not correctly formated\n");
	return (0);
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
