/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:16:22 by fgrasset          #+#    #+#             */
/*   Updated: 2023/05/08 17:19:18 by fgrasset         ###   ########.fr       */
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
	int	test;
}				t_philo;


# endif
