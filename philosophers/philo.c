/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:16:09 by fgrasset          #+#    #+#             */
/*   Updated: 2023/05/19 15:02:57 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize(t_philo **philo, char **settings);
int		ft_atoi(const char *str);


int	main(int ac, char **av)
{
	t_config	*config;
	t_philo		*philo;

	if (!my_malloc((void **)&config, sizeof(config)) && !my_malloc((void **)&philo, sizeof(philo)))
		return (0);
	if (!infos_check(av, ac))
		return (0);
	initialize(&philo, av);
	printf("reussi!");
}

/* initializes the philo struct based on the given infos */
void	initialize(t_philo **philo, char **settings)
{
	int	i;

	i = 0;
	(*philo)->nb_philo = ft_atoi(settings[++i]);
	if ((*philo)->nb_philo < 1)
		return ;
	(*philo)->time_die = ft_atoi(settings[++i]);
	(*philo)->time_eat = ft_atoi(settings[++i]);
	(*philo)->time_sleep = ft_atoi(settings[++i]);
	if (settings[++i])
		(*philo)->nb_time_eat = ft_atoi(settings[i]);
	(*philo)->threads = malloc(sizeof(pthread_t) * (*philo)->nb_philo);
	if (!(*philo)->threads)
		return ;
	if (!pthread_mutex_init((*philo)->forks, NULL))
		return ;
	(*philo)->forks = malloc(sizeof(pthread_mutex_t) * (*philo)->nb_philo);
	if (!(*philo)->forks)
		return ;
	if (!pthread_mutex_init((*philo)->life_mutex, NULL))
		return ;
	(*philo)->life_state = malloc(sizeof(int) * (*philo)->nb_philo + 1);
	if (!(*philo)->life_state)
		return ;
	get_time('i');
}

/* basically atoi */
int	ft_atoi(const char *str) {
	int sign = 1;
	int result = 0;

	while (*str == ' ' || (*str >= '\t' && *str <= '\r')) {
		str++;
	}
	if (*str == '-' || *str == '+') {
		sign = (*str++ == '-') ? -1 : 1;
	}
	while (*str >= '0' && *str <= '9') {
		int digit = *str - '0';
		if (sign == 1 && (result > (2147483647 - digit) / 10)) {
			return (2147483647);
		}else if (sign == -1 && (result > (2147483647 - digit) / 10)) {
			return (-2147483648);
		}
		result = result * 10 + digit;
		str++;
	}

	return (sign * result);
}


