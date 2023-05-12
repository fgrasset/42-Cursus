/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 11:21:10 by fgrasset          #+#    #+#             */
/*   Updated: 2023/05/12 10:21:44 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philo(t_philo *philo, t_config *config);
void	*philo(void	*config);

/* launches the simulation */
void	launch_sim(t_philo **philo, t_config **config)
{

}

/* creates each thread of each individual philo */
void	create_philo(t_philo *philo, t_config *config)
{
	int	i;

	i = -1;
	while (i < philo->nb_philo)
	{
		if (!pthread_create(philo->threads[i], NULL, philo, (void *)config))
			return ;
	}
}

void	*philo(void	*config)
{

}
