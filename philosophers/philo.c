/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:16:09 by fgrasset          #+#    #+#             */
/*   Updated: 2023/05/10 11:07:54 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **ag)
{
	t_config	*config;
	t_philo		*philo;

	if (!my_malloc(&config, sizeof(config)) && !my_malloc(&philo, sizeof(philo)))
		return (0);
	if (!infos_check(ag))
		return (0);
}

/* initializes the config struct based on the given infos */
void	initialize(t_philo **philo, t_config **config, char **infos)
{
	/*
	Check all the times and fill up the config struct
	also malloc the forks mutex and the threads based on the number of philo
	*/
}
