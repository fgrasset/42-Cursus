/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:16:35 by fgrasset          #+#    #+#             */
/*   Updated: 2023/06/09 11:10:02 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* frees and terminates the program philo */
void	terminate(t_philo *philo)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(philo->sim_mutex);
	while (++i <= philo->nb_philo)
	{
		pthread_mutex_destroy(&philo->forks[i]);
	}
	free(philo->threads);
	free(philo->forks);
	free(philo->sim_mutex);
	free(philo->sim_state);
	free(philo);
}
