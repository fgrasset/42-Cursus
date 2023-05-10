/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:16:22 by fgrasset          #+#    #+#             */
/*   Updated: 2023/05/10 11:01:25 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define NB_PHILO = 1;
# define TIME_DIE = 2;
# define TIME_EAT = 3;
# define TIME_SLEEP = 4;
# define NB_TIME_EAT = 5;

typedef struct s_philo
{
	pthread_t		*threads;		//keep track of the threads ID
	pthread_mutex_t	*forks;			//forks used as mutex
}				t_philo;

typedef struct s_config
{
	int	pos;
	int	t_eat;
	int	t_die;
	int	t_sleep;
	int	nb_t_eat;
}				t_config;




// utils

int	my_malloc(void	**ptr, int size);

# endif
