/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:13:44 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/23 15:16:49 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* takes a character and returns a 8 bit integer of the character */
void	send(char c, int pid)
{
	int	i;
	int	bit;

	i = 0;
	bit = 0;
	while (i < 8)
	{
		bit = (c & (1 << i)) != 0;
		if (bit % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(50);
		i++;
	}
}

/* prepares the message and the pid in arguments,
   and activates the function to send it to the server */
int	main(int ac, char **av)
{
	int	i;
	int	pid;

	if (ac == 3)
	{
		pid = atoi(av[1]);
		i = 0;
		while (av[2][i])
		{
			send(av[2][i], pid);
			i++;
		}
		send(0, pid);
	}
	else
		printf("Please write only the PID of the server \
		and the string you want to send\n");
}
