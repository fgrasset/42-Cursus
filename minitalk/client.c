/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrasset <fgrasset@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:13:44 by fgrasset          #+#    #+#             */
/*   Updated: 2022/12/17 13:26:36 by fgrasset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* takes a character and returns a 8 bit integer of the character */
void	send(char c, int pid)
{
	int	i;
	// int	value;
	// value = (c >> 1) & 1;

	i = 8;
	while (i > 0)
	{
		kill(pid, (((c >> i) & 1) % 2 == 0) ? SIGUSR2 : SIGUSR1);
		i--;
	}
}

/* prepares the message and the pid in arguments, and activates the function to send it to the server */
int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int	i;
		int	pid;

		pid = atoi(av[1]);
		i = 0;
		while (av[2][i])
		{
			send(av[2][i], pid);
			i++;
		}
		send('\n', pid);
	}
	else
		printf("Please write only the PID and the string you want to send\n");
}
