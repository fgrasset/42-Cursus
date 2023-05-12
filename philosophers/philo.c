/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:16:09 by fgrasset          #+#    #+#             */
/*   Updated: 2023/05/12 10:21:48 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize(t_philo **philo, t_config **config, char **infos);
int		ft_atoi(const char *str);


int	main(int ac, char **av)
{
	t_config	*config;
	t_philo		*philo;

	if (!my_malloc(&config, sizeof(config)) && !my_malloc(&philo, sizeof(philo)))
		return (0);
	if (!infos_check(av, ac))
		return (0);
	initialize(&philo, &config, av);
	printf("reussi!");
}

/* initializes the config struct based on the given infos */
void	initialize(t_philo **philo, t_config **config, char **infos)
{
	/*
	Check all the times and fill up the config struct
	also malloc the forks mutex and the threads based on the number of philo
	*/
	int	i;

	i = 0;
	(*philo)->nb_philo = ft_atoi(infos[++i]); //need to make a check to be atleast one philo !!!
	(*philo)->time_die = ft_atoi(infos[++i]);
	(*philo)->nb_time_eat = ft_atoi(infos[++i]);
	(*philo)->time_sleep = ft_atoi(infos[++i]);
	if (infos[++i])
		(*philo)->nb_time_eat = ft_atoi(infos[i]);
	(*philo)->threads = malloc(sizeof(pthread_t) * (*philo)->nb_philo);
	if (!(*philo)->threads)
		return ;
	(*philo)->forks = malloc(sizeof(pthread_mutex_t) * (*philo)->nb_philo);
	if (!(*philo)->forks)
		return ;
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


