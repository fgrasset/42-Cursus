/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:16:22 by fgrasset          #+#    #+#             */
/*   Updated: 2023/05/31 10:12:42 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define EATS 1
# define SLEEPS 2
# define THINKS 3
# define DIES 4
# define FORKS 5

typedef struct s_philo
{
	pthread_t		*threads;		//keep track of the threads ID
	pthread_mutex_t	*forks;			//forks used as mutex
	pthread_mutex_t	*sim_mutex;
	int				*sim_state;
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_time_eat;
}				t_philo;

typedef struct s_config
{
	int				pos;
	int				next_pos;
	int				nb_philo;
	int				t_eat;
	int				t_die;
	int				t_sleep;
	int				nb_t_eat;
	int				life;
	int				ate;
	int				last_bite;
	int				*sim_state;
	pthread_mutex_t	*sim_mutex;
	pthread_mutex_t	*forks;
}				t_config;

// utils

int			my_malloc(void	**ptr, int size);

// errors

int			infos_check(char **infos, int nb_args);

// time

int			get_time(char c);

// msg

void		msg(t_config *config, int state);

// actions

void		eats(t_config *config);
void		sleeps(t_config *config);
void		thinks(t_config *config);

// sim

void		launch_sim(t_philo **philo);
int			satiated(t_config *config);

// state

int			state(t_config *config);
void		state_update(t_config *config, char flag);

// terminate

void		terminate(t_philo *philo);

#endif
