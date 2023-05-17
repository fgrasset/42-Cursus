/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:16:09 by fgrasset          #+#    #+#             */
/*   Updated: 2023/05/17 13:45:47 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	initialize(t_philo **philo, char **infos);
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

/* initializes the config struct based on the given infos */
void	initialize(t_philo **philo, char **infos)
{
	int	i;

	i = 0;
	(*philo)->nb_philo = ft_atoi(infos[++i]);
	if ((*philo)->nb_philo < 1)
		return ;
	(*philo)->time_die = ft_atoi(infos[++i]);
	(*philo)->time_eat = ft_atoi(infos[++i]);
	(*philo)->time_sleep = ft_atoi(infos[++i]);
	if (infos[++i])
		(*philo)->nb_time_eat = ft_atoi(infos[i]);
	(*philo)->threads = malloc(sizeof(pthread_t) * (*philo)->nb_philo);
	if (!(*philo)->threads)
		return ;
	(*philo)->forks = malloc(sizeof(pthread_mutex_t) * (*philo)->nb_philo);
	if (!(*philo)->forks)
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


